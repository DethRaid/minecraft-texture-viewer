#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#include "glad.h"

#include <string>

class gl_texture {
public:
	/*!
	* \brief Initializes a new gl_texture and sets its binding to the given binding location
	*
	* \param binding The location to bind this texture to
	*/
	gl_texture(int binding);

	gl_texture(gl_texture&& other);

	/*!
	* \brief Destructor. Deletes the texture data and deletes the GPU texture object
	*/
	~gl_texture();

	GLuint get_gl_name();

	void set_color(int red, int green, int blue);
	void set_color(int grayscale);
	void load_from_file(std::string filename);

private:
	unsigned char* data = nullptr;
	int width;
	int height;
	int num_components;

	GLuint gl_name;

	void upload_texture_data();
};

#endif