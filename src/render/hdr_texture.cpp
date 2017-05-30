#include "hdr_texture.h"

#include <stb_image.h>
#include <easylogging++.h>

hdr_texture::hdr_texture(int binding, std::string filename, bool make_mipmaps) {
	create(binding);

	data = (unsigned char*) stbi_loadf(filename.c_str(), &width, &height, &num_components, 0);
	upload_texture_data();

	if(make_mipmaps) {
		LOG(TRACE) << "Making mipmaps for texture " << gl_name;
		glGenerateTextureMipmap(gl_name);
	}
}

void hdr_texture::upload_texture_data() {
	GLenum format;
	GLenum internal_format;
	switch(num_components) {
	case 1:
		internal_format = GL_R16F;
		format = GL_RED;
		break;
	case 2:
		internal_format = GL_RG16F;
		format = GL_RG;
		break;
	case 3:
		internal_format = GL_RGB16F;
		format = GL_RGB;
		break;
	case 4:
		internal_format = GL_RGBA16F;
		format = GL_RGBA;
		break;
	default:
		LOG(ERROR) << "Unsupported number of components. You have " << num_components << " components, but I need a "
			<< "number in [1,4]";
	}

	glTextureStorage2D(gl_name, 1, internal_format, width, height);

	GLint previous_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &previous_texture);
	glBindTexture(GL_TEXTURE_2D, gl_name);
	glTextureSubImage2D(gl_name, 0, 0, 0, width, height, format, GL_FLOAT, data);
	LOG(TRACE) << "HDR texture data uploaded";

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, (GLuint)previous_texture);
}