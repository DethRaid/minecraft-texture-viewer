//
// Created by gold1 on 26-Apr-17.
//

#include "main_window.h"
#include <sstream>

#include <easylogging++.h>
#include <imgui.h>
#include <nfd.h>

void error_callback(int error, const char *description) {
	LOG(ERROR) << "GLFW Error " << error << ": " << description;
}

static const char* get_clipboard_text(void* user_data) {
    return glfwGetClipboardString((GLFWwindow*)user_data);
}

static void set_clipboard_text(void* user_data, const char* text) {
    glfwSetClipboardString((GLFWwindow*)user_data, text);
}

void mouse_button_callback(GLFWwindow*, int button, int action, int /*mods*/) {
    if(action == GLFW_PRESS && button >= 0 && button < 3) {
        g_MousePressed[button] = true;
    }
}

void scroll_callback(GLFWwindow*, double /*xoffset*/, double yoffset) {
    g_MouseWheel += (float)yoffset; // Use fractional mouse wheel, 1.0 unit 5 lines.
}

void key_callback(GLFWwindow*, int key, int, int action, int mods) {
    ImGuiIO& io = ImGui::GetIO();
    if(action == GLFW_PRESS) {
        io.KeysDown[key] = true;
    }

    if(action == GLFW_RELEASE) {
        io.KeysDown[key] = false;
    }

    (void)mods; // Modifiers are not reliable across systems
    io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
    io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
    io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
    io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
}

void char_callback(GLFWwindow*, unsigned int c) {
    ImGuiIO& io = ImGui::GetIO();
    if (c > 0 && c < 0x10000) {
        io.AddInputCharacter((unsigned short) c);
    }
}

main_window::main_window(int view_width, int view_height) {
	glfwSetErrorCallback(error_callback);

	if(glfwInit() == 0) {
		LOG(FATAL) << "Could not initialize GLFW";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(view_width, view_height, "Minecraft Texture Packer", NULL, NULL);
	if(window == nullptr) {
		LOG(FATAL) << "Could not initialize window :(";
	}
	LOG(INFO) << "GLFW window created";

	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

	if(gladLoadGL() == 0) {
		LOG(FATAL) << "Could not load OpenGL";
	}

	const GLubyte *vendor = glGetString(GL_VENDOR);
	LOG(INFO) << "Vendor: " << vendor;

	glfwGetFramebufferSize(window, &window_dimensions.x, &window_dimensions.y);
	glViewport(0, 0, window_dimensions.x, window_dimensions.y);

	glfwSetKeyCallback(window, key_callback);
	glfwSetCharCallback(window, char_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSwapInterval(0);

    ImGuiIO& io = ImGui::GetIO();
    io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;                         // Keyboard mapping. ImGui will use those indices to peek into the io.KeyDown[] array.
    io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
    io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
    io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
    io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
    io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
    io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
    io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
    io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
    io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
    io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
    io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
    io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
    io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
    io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
    io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

    io.RenderDrawListsFn = ImGui_ImplGlfwGL3_RenderDrawLists;       // Alternatively you can set this to NULL and call ImGui::GetDrawData() after ImGui::Render() to get the same ImDrawData pointer.
    io.SetClipboardTextFn = set_clipboard_text;
    io.GetClipboardTextFn = get_clipboard_text;
    io.ClipboardUserData = window;
#ifdef _WIN32
    io.ImeWindowHandle = glfwGetWin32Window(window);
#endif

	gl_canvas = std::make_unique<texture_preview_canvas>(this, attrs, size);

    draw_opacity_controls();
    draw_normal_controls();
	hook_up_specular_color_controls();
	hook_up_smoothness_controls();
	hook_up_height_controls();
	hook_up_porosity_controls();
	hook_up_translucence_controls();
	hook_up_ao_controls();
	hook_up_emission_controls();
}

void main_window::draw() {
    draw_albedo_controls();
}

void main_window::on_export_textures_pbr(wxCommandEvent& event) {
	LOG(INFO) << "Exporting textures...";

	export_dialogue.reset();
	export_dialogue = std::make_unique<export_options_dialogue>(this, textures);
	export_dialogue->Show(true);
}

void main_window::draw_albedo_controls() {
    ImGui::Begin("Albedo");
    draw_texture_128(textures.albedo_tex);
    ImGui::LabelText("Selected texture:##albedo", "%s", textures.albedo_tex->get_filepath().data());
    if(ImGui::Button("Select Texture##albedo", {50, 20})) {
        nfdchar_t *outPath = nullptr;
        nfdresult_t result = NFD_OpenDialog(nullptr, nullptr, &outPath);

        if(result == NFD_OKAY) {
            std::string filepath(outPath);
            LOG(INFO) << "Grabbed file " << filepath;
            textures.albedo_tex = std::make_shared<texture>(3, filepath);
        }
	}
    ImGui::End();
}

void main_window::draw_opacity_controls() {
    ImGui::Begin("Opacity");
    draw_texture_128(textures.opacity_tex);
    ImGui::LabelText("Selected Texture:##opacity", "%s", textures.opacity_tex->get_filepath());
    float lastOpacity = opacity;
    ImGui::SliderFloat("Opacity##slider", &opacity, 0, 1);
    ImGui::InputFloat("Opacity##input", &opacity, 0, 1);

    if(opacity != lastOpacity) {
        LOG(DEBUG) << "Updating opacity to " << opacity;
        textures.opacity_tex = std::make_shared<texture>(OPACITY_BINDING, opacity);
    }

    if(ImGui::Button("Select Texture##opacity", {50, 20})) {
        nfdchar_t *outPath = nullptr;
        nfdresult_t result = NFD_OpenDialog(nullptr, nullptr, &outPath);

        if(result == NFD_OKAY) {
            std::string filepath(outPath);
            LOG(INFO) << "Grabbed file " << filepath;
            textures.opacity_tex = std::make_shared<texture>(3, filepath);
        }
    }

    ImGui::End();
}

void main_window::draw_normal_controls() {
    ImGui::Button("Normals");
    draw_texture_128(textures.normal_tex);
    ImGui::LabelText("Selected Texture:##normals", "%s", textures.normal_tex->get_filepath());

    if(ImGui::Button("Select Texture##normals", {50, 20})) {
        nfdchar_t *outPath = nullptr;
        nfdresult_t result = NFD_OpenDialog(nullptr, nullptr, &outPath);

        if(result == NFD_OKAY) {
            std::string filepath(outPath);
            LOG(INFO) << "Grabbed file " << filepath;
            textures.normal_tex = std::make_shared<texture>(3, filepath);
        }
    }

    ImGui::End();
}

void main_window::hook_up_specular_color_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto f0 = specular_red_slider->GetValue();

		set_f0(f0);
	};

	specular_red_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto f0 = get_input_value(specular_red_input);

		set_f0(f0);
	};

	specular_red_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.f0_tex = std::make_shared<texture>(F0_BINDING, event.GetPath().ToStdString());
	};

	specular_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_f0(int f0) {
	set_text_input_value(specular_red_input, f0);

	specular_red_slider->SetValue(f0);


	LOG(DEBUG) << "Updating F0 to " << f0;

	textures.f0_tex = std::make_shared<texture>(F0_BINDING, f0);
}

void main_window::hook_up_smoothness_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto smoothness = smoothness_slider->GetValue();

		set_smoothness(smoothness);
	};

	smoothness_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto smoothness = get_input_value(smoothness_input);

		set_smoothness(smoothness);
	};

	smoothness_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.smoothness_tex = std::make_shared<texture>(SMOOTHNESS_BINDING, event.GetPath().ToStdString());
	};

	smoothness_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_smoothness(int smoothness) {
	set_text_input_value(smoothness_input, smoothness);

	smoothness_slider->SetValue(smoothness);

	LOG(DEBUG) << "Updating smoothness to " << smoothness;

	textures.smoothness_tex = std::make_shared<texture>(SMOOTHNESS_BINDING, smoothness);
}

void main_window::hook_up_emission_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto emission = emission_slider->GetValue();

		set_emission(emission);
	};

	emission_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto emission = get_input_value(emission_input);

		set_emission(emission);
	};

	emission_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.emission_tex = std::make_shared<texture>(EMISSION_BINDING, event.GetPath().ToStdString());
	};

	emission_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_emission(int emission) {
	set_text_input_value(emission_input, emission);

	emission_slider->SetValue(emission);

	LOG(DEBUG) << "Updating emission to " << emission;

	textures.emission_tex = std::make_shared<texture>(EMISSION_BINDING, emission);
}

void main_window::hook_up_height_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto height = height_slider->GetValue();

		set_height(height);
	};

	height_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto height = get_input_value(height_input);

		set_height(height);
	};

	height_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.height_tex = std::make_shared<texture>(HEIGHT_BINDING, event.GetPath().ToStdString());
	};

	height_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_height(int height) {
	set_text_input_value(height_input, height);

	height_slider->SetValue(height);

	LOG(DEBUG) << "Updating height to " << height;

	textures.height_tex = std::make_shared<texture>(HEIGHT_BINDING, height);
}

void main_window::hook_up_porosity_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto porosity = porosity_slider->GetValue();

		set_porosity(porosity);
	};

	porosity_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto porosity = get_input_value(porosity_input);

		set_porosity(porosity);
	};

	porosity_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.porosity_tex = std::make_shared<texture>(POROSITY_BINDING, event.GetPath().ToStdString());
	};

	porosity_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_porosity(int porosity) {
	set_text_input_value(porosity_input, porosity);

	porosity_slider->SetValue(porosity);

	LOG(DEBUG) << "Updating porosity to " << porosity;

	textures.porosity_tex = std::make_shared<texture>(POROSITY_BINDING, porosity);
}

void main_window::hook_up_translucence_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto translucence = translucence_slider->GetValue();

		set_translucence(translucence);
	};

	translucence_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto translucence = get_input_value(translucence_input);

		set_translucence(translucence);
	};

	translucence_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.translucence_tex = std::make_shared<texture>(TRANSLUCENCE_BINDING, event.GetPath().ToStdString());
	};

	translucence_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_translucence(int translucence) {
	set_text_input_value(translucence_input, translucence);

	translucence_slider->SetValue(translucence);

	LOG(DEBUG) << "Updating translucence to " << translucence;

	textures.translucence_tex = std::make_shared<texture>(TRANSLUCENCE_BINDING, translucence);
}

void main_window::hook_up_ao_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto ao = ao_slider->GetValue();

		set_ao(ao);
	};

	ao_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto ao = get_input_value(ao_input);

		set_ao(ao);
	};

	ao_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.ao_tex = std::make_shared<texture>(AO_BINDING, event.GetPath().ToStdString());
	};

	ao_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_ao(int ao) {
	set_text_input_value(ao_input, ao);

	ao_slider->SetValue(ao);

	LOG(DEBUG) << "Updating ao to " << ao;

	textures.ao_tex = std::make_shared<texture>(AO_BINDING, ao);
}

void main_window::refresh_shaders(wxCommandEvent& event) {
	gl_canvas->load_shaders();
}

void main_window::change_background_to_blue_hour(wxCommandEvent& event) {
	change_background("blue_hour_at_pier.hdr");
}

void main_window::change_background_to_autumn_road(wxCommandEvent& event) {
	change_background("golden_autumn_road.hdr");
}

void main_window::change_background_to_road_in_valley(wxCommandEvent& event) {
	change_background("road_in_valley.hdr");
}

void main_window::change_background(std::string background_name) {
	gl_canvas->change_background(background_name);
}

wxBEGIN_EVENT_TABLE(main_window, _main_window)
	EVT_SIZE(									main_window::on_size_change)
	EVT_MENU(ID_EXPORT_PBR,						main_window::on_export_textures_pbr)
	EVT_MENU(ID_REFRESH_SHADERS,				main_window::refresh_shaders)
	EVT_MENU(ID_BLUE_HOUR_AT_PIER_BACKGROUND,	main_window::change_background_to_blue_hour)
	EVT_MENU(ID_GOLDEN_AUTUMN_ROAD_BACKGROUND,	main_window::change_background_to_autumn_road)
	EVT_MENU(ID_ROAD_IN_VALLEY_BACKGROUND,		main_window::change_background_to_road_in_valley)
wxEND_EVENT_TABLE()

void set_text_input_value(wxTextCtrl* input, int value) {
	static std::stringstream converter;
	converter.precision(3);
	converter << std::fixed << float(value) / 255.f;
	input->SetValue(converter.str());
	converter.str("");
}

float get_input_value(wxTextCtrl* input) {
	return std::atof(input->GetValue()) * 255;
}

void draw_texture_128(std::shared_ptr<texture> data) {
    ImGui::Image(data.get(), {128, 128});
}
