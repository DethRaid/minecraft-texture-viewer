#include "gl_texture.h"
#include <easylogging++.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

gl_texture::gl_texture(int binding) {
	glGenTextures(1, &gl_name);
	glBindTexture(binding, gl_name);
}

gl_texture::gl_texture(gl_texture&& other) {
	this->data = other.data;
	this->width = other.width;
	this->height = other.height;
	this->num_components = other.num_components;
	this->gl_name = gl_name;

	other.data = nullptr;
	other.gl_name = 0;
}

gl_texture::~gl_texture() {
	glDeleteTextures(1, &gl_name);
	if(data != nullptr) {
		delete[] data;
	}
}

GLuint gl_texture::get_gl_name() {
	return gl_name;
}

void gl_texture::set_color(int red, int green, int blue) {
	data = new unsigned char[3];
	data[0] = red;
	data[1] = green;
	data[2] = blue;

	width = 1;
	height = 1;
	num_components = 3;
	upload_texture_data();
}

void gl_texture::set_color(int grayscale) {
	data = new unsigned char[1];
	data[0] = grayscale;
	width = 1;
	height = 1;
	upload_texture_data();
}

void gl_texture::load_from_file(std::string filename) {
	data = stbi_load(filename.c_str(), &width, &height, &num_components, 0);
	upload_texture_data();
}

void gl_texture::upload_texture_data() {
	GLenum format;
	switch(num_components) {
	case 1:
		format = GL_RED;
		break;
	case 2:
		format = GL_RG;
		break;
	case 3:
		format = GL_RGB;
		break;
	case 4:
		format = GL_RGBA;
		break;
	default:
		LOG(ERROR) << "Unsupported number of components. You have " << num_components
			<< " components "
			<< ", but I need a number in [1,4]";
	}
	
	GLint previous_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &previous_texture);
	glBindTexture(GL_TEXTURE_2D, gl_name);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_FLOAT, data);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, (GLuint)previous_texture);
}