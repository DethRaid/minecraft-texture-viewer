#ifndef HDR_TEXTURE_H
#define HDR_TEXTURE_H

#include "gl_texture.h"

class hdr_texture : public texture {
public:
	hdr_texture(int binding, std::string filename, bool make_mipmaps = true);
private:
	void upload_texture_data();
};

#endif // !HDR_TEXTURE_H
