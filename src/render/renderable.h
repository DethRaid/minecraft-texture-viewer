#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <memory>

#include "glad.h"
#include "material.h"

/*!
 * \brief Something that can be rendered
 *
 * While I normally don't like OOP renderers, this is easy to write
 */
class renderable {
public:
	void draw();

	void set_material(std::shared_ptr<material> new_material);
private:
	std::shared_ptr<material> mat;

	GLuint vao;
};

#endif