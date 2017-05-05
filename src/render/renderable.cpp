#include "renderable.h"

vertex::vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 tangent, glm::vec2 uv) 
	: position(position), normal(normal), tangent(tangent), uv(uv) {}

void renderable::draw() {
	mat->bind();
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, num_indices, GL_INT, 0);
}

void renderable::set_vertex_data(std::vector<vertex> vertices, std::vector<int> indices) {
	num_indices = indices.size();

	if(vao > 0) {
		glDeleteVertexArrays(1, &vao);
	}
	glCreateVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint buffers[2];
	glCreateBuffers(2, buffers);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * 11 * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLint), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);	// position
	glEnableVertexAttribArray(1);	// normals
	glEnableVertexAttribArray(2);	// tangents
	glEnableVertexAttribArray(3);	// UVs

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (void *)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (void *)(6 * sizeof(GLfloat)));
	glVertexAttribPointer(4, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (void *)(9 * sizeof(GLfloat)));
}

void renderable::set_material(std::shared_ptr<material> new_material) {
	mat = new_material;
}