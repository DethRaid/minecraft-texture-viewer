#include "gl_texture.h"
#include <easylogging++.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

gl_texture::gl_texture(int binding, int red, int green, int blue) {
	create(binding);

	data = new unsigned char[3];
	data[0] = red;
	data[1] = green;
	data[2] = blue;

	width = 1;
	height = 1;
	num_components = 3;
	upload_texture_data();
}

gl_texture::gl_texture(int binding, int grayscale) {
	create(binding);

	data = new unsigned char[1];
	data[0] = grayscale;
	width = 1;
	height = 1;
	num_components = 1;
	upload_texture_data();
}

gl_texture::gl_texture(int binding, std::string& filename) {
	create(binding);

	data = stbi_load(filename.c_str(), &width, &height, &num_components, 0);
	upload_texture_data();
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

void gl_texture::create(int binding) {
	glCreateTextures(GL_TEXTURE_2D, 1, &gl_name);
	glBindTextureUnit(binding, gl_name);
}

GLuint gl_texture::get_gl_name() {
	return gl_name;
}

void gl_texture::upload_texture_data() {
	GLenum format;
	GLenum internal_format;
	switch(num_components) {
	case 1:
		internal_format = GL_R8;
		format = GL_RED;
		break;
	case 2:
		internal_format = GL_RG8;
		format = GL_RG;
		break;
	case 3:
		internal_format = GL_RGB8;
		format = GL_RGB;
		break;
	case 4:
		internal_format = GL_RGBA8;
		format = GL_RGBA;
		break;
	default:
		LOG(ERROR) << "Unsupported number of components. You have " << num_components
			<< " components "
			<< ", but I need a number in [1,4]";
	}

	if(!storage_allocated) {
		glTextureStorage2D(gl_name, 1, internal_format, width, height);
		storage_allocated = true;
	}
	
	GLint previous_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &previous_texture);
	glBindTexture(GL_TEXTURE_2D, gl_name);
	glTextureSubImage2D(gl_name, 0, 0, 0, width, height, format, GL_UNSIGNED_BYTE, data);
	LOG(TRACE) << "Texture data updated";

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, (GLuint)previous_texture);
}