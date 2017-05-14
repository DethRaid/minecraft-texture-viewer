/*!
 * \brief Defines all the UBOs used by this program
 */

#ifndef BUFFERS_H
#define BUFFERS_H

#include <glm/glm.hpp>

struct mvp_buffer {
	glm::mat4 model_matrix;
	glm::mat4 view_matrix;
	glm::mat4 projection_matrix;
};

#endif