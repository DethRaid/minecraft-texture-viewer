#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "glad.h"

class framebuffer {
public:
	framebuffer(int width, int height);
	framebuffer(framebuffer&& other);

	void bind();
	void generate_mipmaps();
private:
	GLuint framebuffer_id;

	GLuint attachments[5];

	enum texture_index {
		DEPTH = 0,
		DIFFUSE_COLOR,
		DIFFUSE_LIGHT,
		SPECULAR_LIGHT,
		NORMALS,
		NUM_ATTACHMENTS,
	};
};

#endif