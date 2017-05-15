#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "glad.h"

class framebuffer {
public:
	framebuffer(int width, int height);
	framebuffer(framebuffer&& other);

	~framebuffer();

	void bind();
	void generate_mipmaps();
private:
	GLuint framebuffer_id;

	enum texture_index {
		DEPTH = 0,
		DIFFUSE_COLOR,
		DIFFUSE_LIGHT,
		SPECULAR_LIGHT,
		NORMALS,
		NUM_ATTACHMENTS,
	};

	GLuint attachments[NUM_ATTACHMENTS];
};

#endif