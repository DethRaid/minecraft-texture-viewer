//
// Created by gold1 on 26-Apr-17.
//

#ifndef TEXTUREPREVIEWER_MAIN_WINDOW_H
#define TEXTUREPREVIEWER_MAIN_WINDOW_H

#include <GLFW/glfw3.h>
#include "texture_preview_canvas.h"
#include "export_options_dialogue.h"

class main_window {
public:
    /*!
     * \brief Initializes the window to the given size
     *
     * \param view_width The width of the window
     * \param view_height The height of the window
     */
    main_window(int view_width, int view_height);

    /*!
     * Renders the window and everything in it
     */
    void draw();
private:
	std::unique_ptr<texture_preview_canvas> gl_canvas;
	std::unique_ptr<export_options_dialogue> export_dialogue;

    GLFWwindow* window;
    glm::ivec2 window_dimensions;

	textures_struct textures;

    float opacity = 0;
    float f0 = 0.2;
    float smoothness = 0.9;
    glm::vec3 emission = {0, 0, 0};
    float height = 1;
    float porosity = 0.1;
    float translucence = 0;

	void draw_albedo_controls();
	void draw_opacity_controls();
	void draw_normal_controls();
	void draw_specular_color_controls();
	void draw_smoothness_controls();
	void draw_emission_controls();
	void draw_height_controls();
	void draw_porosity_controls();
	void draw_translucence_controls();
	void draw_ao_controls();

    void draw_top_menu();
    void draw_file_menu();

	void on_export_textures_pbr();

	void change_background(std::string background_name);
};

void draw_texture_128(std::shared_ptr<texture> data);

std::shared_ptr<texture> pick_texture_from_disk();


#endif //TEXTUREPREVIEWER_MAIN_WINDOW_H
