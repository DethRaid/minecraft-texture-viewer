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

    float opacity;

	void draw_albedo_controls();
	void draw_opacity_controls();

	void draw_normal_controls();

	void hook_up_specular_color_controls();
	void set_f0(int f0);

	void hook_up_smoothness_controls();
	void set_smoothness(int smoothness);

	void hook_up_emission_controls();
	void set_emission(int emission);

	void hook_up_height_controls();
	void set_height(int height);

	void hook_up_porosity_controls();
	void set_porosity(int porosity);

	void hook_up_translucence_controls();
	void set_translucence(int translucence);

	void hook_up_ao_controls();
	void set_ao(int ao);

	void on_export_textures_pbr(wxCommandEvent& event);
	void refresh_shaders(wxCommandEvent& event);
	void change_background_to_blue_hour(wxCommandEvent& event);
	void change_background_to_autumn_road(wxCommandEvent& event);
	void change_background_to_road_in_valley(wxCommandEvent& event);

	void change_background(std::string background_name);
};

void set_text_input_value(wxTextCtrl* input, int value);

float get_input_value(wxTextCtrl* input);

void draw_texture_128(std::shared_ptr<texture> data);


#endif //TEXTUREPREVIEWER_MAIN_WINDOW_H
