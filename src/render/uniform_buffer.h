#ifndef RENDERER_GL_UNIFORM_BUFFER_H
#define RENDERER_GL_UNIFORM_BUFFER_H

#include <string>
#include "glad.h"
#include "material.h"

#include <easylogging++.h>

/*!
* \brief A nice interface for uniform buffer objects
*/
template <typename BufferStruct>
class uniform_buffer {
public:
	uniform_buffer(std::string name) : name(name) {
		glCreateBuffers(1, &gl_name);
		//LOG(TRACE) << "creating ubo " << name << " with size: " << sizeof(BufferStruct);
		glNamedBufferStorage(gl_name, sizeof(BufferStruct), nullptr, GL_DYNAMIC_STORAGE_BIT);
	}

	uniform_buffer(uniform_buffer &&old) noexcept {
		gl_name = old.gl_name;
		name = old.name;

		old.gl_name = 0;
		old.name = "";
	}

	void link_to_material(const std::shared_ptr<material> mat) {
		auto program_id = mat->get_program_id();
		ubo_index = glGetUniformBlockIndex(program_id, name.c_str());
		glBindBuffer(GL_UNIFORM_BUFFER, gl_name);
		glBindBufferBase(GL_UNIFORM_BUFFER, ubo_index, gl_name);
	}

	void send_data(BufferStruct data) {
		this->data = data;
		send_data();
	}

	void send_data() {
		//LOG(TRACE) << "sending date with size: " << sizeof(BufferStruct) << " to ubo " << name;
 		glNamedBufferSubData(gl_name, 0, sizeof(BufferStruct), &data);
	}

	void bind() {
		glBindBuffer(GL_UNIFORM_BUFFER, gl_name);
	}

	BufferStruct& get_data() {
		return data;
	}

	/*!
	* \brief Deallocates this uniform buffer
	*/
	~uniform_buffer() {
		glDeleteBuffers(1, &gl_name);
	}

private:
	GLuint gl_name;
	GLuint ubo_index;
	std::string name;
	BufferStruct data;
};

#endif //RENDERER_GL_UNIFORM_BUFFER_H