#include "framebuffer.h"

#include <easylogging++.h>

framebuffer::framebuffer(int width, int height) {
	glGenFramebuffers(1, &framebuffer_id);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_id);

	glGenTextures(NUM_ATTACHMENTS, attachments);

	glBindTexture(GL_TEXTURE_2D, attachments[DEPTH]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
	glNamedFramebufferTexture(framebuffer_id, GL_DEPTH_ATTACHMENT, attachments[DEPTH], 0);
	
	for(int i = 1; i < NUM_ATTACHMENTS; i++) {
		glBindTexture(GL_TEXTURE_2D, attachments[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
		//glTextureStorage2D(attachments[i], 1, GL_RGBA8, width, height);
		glBindTexture(GL_TEXTURE_2D, attachments[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glNamedFramebufferTexture(framebuffer_id, GL_COLOR_ATTACHMENT0 + (i - 1), attachments[i], 0);
	}
	
	glBindTextureUnit(2, attachments[DEPTH]);
	glBindTextureUnit(13, attachments[DIFFUSE_COLOR]);
	glBindTextureUnit(14, attachments[DIFFUSE_LIGHT]);
	glBindTextureUnit(15, attachments[SPECULAR_LIGHT]);
	glBindTextureUnit(16, attachments[NORMALS]);

	auto status = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
	switch(status) {
	case GL_FRAMEBUFFER_COMPLETE:
		LOG(DEBUG) << "Framebuffer " << framebuffer_id << " is complete";
		break;
	case GL_FRAMEBUFFER_UNDEFINED:
		LOG(ERROR) << "Somehow didn't bind the framebuffer";
		break;
	case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
		LOG(ERROR) << "A necessary attachment is not initialized";
		break;
	case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
		LOG(ERROR) << "There are no images attached to the framebuffer";
		break;
	case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
		LOG(ERROR) << "Every drawing buffer has an attachment";
		break;
	case GL_FRAMEBUFFER_UNSUPPORTED:
		LOG(ERROR) << "The framebuffrer format is not supported";
		break;
	}
}

framebuffer::framebuffer(framebuffer&& other) {
	for(int i = 0; i < NUM_ATTACHMENTS; i++) {
		attachments[i] = other.attachments[i];
		other.attachments[i] = 0;
	}

	framebuffer_id = other.framebuffer_id;
}

framebuffer::~framebuffer() {
	LOG(TRACE) << "Deleting framebuffer " << framebuffer_id;
	glDeleteTextures(NUM_ATTACHMENTS, attachments);
	glDeleteFramebuffers(1, &framebuffer_id);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void framebuffer::bind() {
	GLenum active_buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };

	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_id);
	glDrawBuffers(4, active_buffers);
}

void framebuffer::generate_mipmaps() {
	for(int i = 0; i < NUM_ATTACHMENTS; i++) {
		glBindTexture(GL_TEXTURE_2D, attachments[i]);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}