#include "gl_texture.h"
#include <easylogging++.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

texture::texture() {}

texture::texture(int binding, int red, int green, int blue) {
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

texture::texture(int binding, int grayscale) {
	create(binding);

	data = new unsigned char[1];
	data[0] = grayscale;
	width = 1;
	height = 1;
	num_components = 1;
	upload_texture_data();
}

texture::texture(int binding, std::string& filename) {
	create(binding);

	data = stbi_load(filename.c_str(), &width, &height, &num_components, 0);
	upload_texture_data();
}

texture::texture(texture&& other) {
	this->data = other.data;
	this->width = other.width;
	this->height = other.height;
	this->num_components = other.num_components;
	this->gl_name = gl_name;

	other.data = nullptr;
	other.gl_name = 0;
}

texture::~texture() {
	glDeleteTextures(1, &gl_name);
	if(data != nullptr) {
		delete[] data;
	}
}

void texture::create(int binding) {
	glGenTextures(1, &gl_name);
	glActiveTexture(GL_TEXTURE0 + binding);
	glBindTexture(GL_TEXTURE_2D, gl_name);
}

GLuint texture::get_gl_name() {
	return gl_name;
}

void texture::upload_texture_data() {
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
		LOG(ERROR) << "Unsupported number of components. You have " << num_components << " components, but I need a "
				   << "number in [1,4]";
	}
		
	GLint previous_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &previous_texture);
	glBindTexture(GL_TEXTURE_2D, gl_name);
	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	LOG(TRACE) << "Texture data updated";

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, (GLuint)previous_texture);
}

glm::vec4 texture::at(glm::vec2 uv, bool bilinear) {
	if(bilinear) {
		return at_bilinear(uv);
	} else {
		return at_point(uv);
	}
}

glm::vec4 texture::at_point(glm::vec2 uv) {
	int x_coord = uv.x * width;
	int y_coord = uv.y * height;

	return texel_fetch(x_coord, y_coord);
}

glm::vec4 texture::at_bilinear(glm::vec2 uv) {
	float u = uv.s * width - 0.5;
	float v = uv.t * height - 0.5;
	int x = floor(u);
	int y = floor(v);
	double u_ratio = u - x;
	double v_ratio = v - y;
	double u_opposite = 1 - u_ratio;
	double v_opposite = 1 - v_ratio;

	glm::vec4 result = (texel_fetch(x,     y)		* u_opposite 
					  + texel_fetch(x + 1, y)		* u_ratio)		* v_opposite 
					 + (texel_fetch(x,     y + 1)	* u_opposite
					  + texel_fetch(x + 1, y + 1)	* u_ratio)		* v_ratio;
	return result;
}

glm::vec4 texture::texel_fetch(int x, int y) {
	int index = x + y * width;
	index *= num_components;

	glm::vec4 ret_val;

	switch(num_components) {
	case 4: ret_val.w = data[index + 3];
	case 3: ret_val.z = data[index + 2];
	case 2: ret_val.y = data[index + 1];
	case 1: ret_val.x = data[index];
	}

	return ret_val;
}

glm::vec4 operator*(glm::vec4 vec, float f) {
	return f * vec;
}
