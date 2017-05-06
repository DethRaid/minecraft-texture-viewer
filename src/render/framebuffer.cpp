#include "framebuffer.h"

#include <easylogging++.h>

framebuffer::framebuffer(int width, int height) {
	glCreateFramebuffers(1, &framebuffer_id);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_id);

	glCreateTextures(GL_TEXTURE_2D, 5, attachments);

	glTextureStorage2D(attachments[DEPTH], 1, GL_DEPTH_COMPONENT16, width, height);
	glNamedFramebufferTexture(framebuffer_id, GL_DEPTH_ATTACHMENT, attachments[DEPTH], 0);
	
	for(int i = 1; i < NUM_ATTACHMENTS; i++) {
		glTextureStorage2D(attachments[i], 1, GL_RGBA8, width, height);
		glBindTexture(GL_TEXTURE_2D, attachments[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + (i - 1), GL_TEXTURE_2D, attachments[i], 0);
	}
	
	glBindTexture(2, attachments[DEPTH]);
	glBindTexture(13, attachments[DIFFUSE_COLOR]);
	glBindTexture(14, attachments[DIFFUSE_LIGHT]);
	glBindTexture(15, attachments[SPECULAR_LIGHT]);
	glBindTexture(16, attachments[NORMALS]);

	auto status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	switch(status) {
	case GL_FRAMEBUFFER_COMPLETE:
		LOG(INFO) << "Framebuffer " << framebuffer_id << " is complete";
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

void framebuffer::bind() {
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_id);
}

void framebuffer::generate_mipmaps() {
	for(int i = 0; i < NUM_ATTACHMENTS; i++) {
		glGenerateTextureMipmap(attachments[i]);
	}
}