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

void mouse_button_callback(GLFWwindow*, int button, int action, int mods) {
    if(action == GLFW_PRESS && button >= 0 && button < 3) {
        g_MousePressed[button] = true;
    }
}

void scroll_callback(GLFWwindow*, double xoffset, double yoffset) {
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

	gl_canvas = std::make_unique<texture_preview_canvas>(this, window_dimensions);

    draw_opacity_controls();
    draw_normal_controls();
    draw_specular_color_controls();
    draw_smoothness_controls();
    draw_height_controls();
    draw_porosity_controls();
    draw_translucence_controls();
    draw_ao_controls();
    draw_emission_controls();

    draw_top_menu();
}

void main_window::draw() {
    draw_albedo_controls();
}

void main_window::on_export_textures_pbr() {
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
        textures.albedo_tex = pick_texture_from_disk();
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
        textures.opacity_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_normal_controls() {
    ImGui::Button("Normals");
    draw_texture_128(textures.normal_tex);
    ImGui::LabelText("Selected Texture:##normals", "%s", textures.normal_tex->get_filepath());
    if(ImGui::Button("Select Texture##normals", {50, 20})) {
        textures.normal_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_specular_color_controls() {
    ImGui::Begin("Reflectance at Normal Incidence");
    draw_texture_128(textures.f0_tex);

    float last_f0 = f0;
    ImGui::SliderFloat("F0##slider", &f0, 0, 1);
    ImGui::InputFloat("F0##input", &f0, 0, 1);
    if(f0 != last_f0) {
        textures.f0_tex = std::make_shared<texture>(F0_BINDING, f0);
    }

    ImGui::LabelText("Selected Texture:##f0", "%s", textures.f0_tex->get_filepath());
    if(ImGui::Button("Select Texture##f0", {50, 20})) {
        textures.f0_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_smoothness_controls() {
    ImGui::Begin("Smoothness");
    draw_texture_128(textures.smoothness_tex);

    float last_smoothness = smoothness;
    ImGui::SliderFloat("Smoothness##slider", &smoothness, 0, 1);
    ImGui::InputFloat("Smoothness##input", &smoothness, 0, 1);
    if(smoothness != last_smoothness) {
        textures.smoothness_tex = std::make_shared<texture>(SMOOTHNESS_BINDING, smoothness);
    }

    ImGui::LabelText("Selected Texture:##smoothness", "%s", textures.smoothness_tex->get_filepath());
    if(ImGui::Button("Select Texture##smoothness", {50, 20})) {
        textures.smoothness_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_emission_controls() {
    ImGui::Begin("Emission");
    draw_texture_128(textures.emission_tex);

    glm::vec3 last_emission = emission;
    ImGui::ColorEdit3("Emission##color_edit", &emission.x);
    if(emission != last_emission) {
        textures.emission_tex = std::make_shared<texture>(EMISSION_BINDING, emission.x, emission.y, emission.z);
    }

    ImGui::LabelText("Selected Texture:##emission", "%s", textures.emission_tex->get_filepath());
    if(ImGui::Button("Select Texture##emission", {50, 20})) {
        textures.emission_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_height_controls() {
    ImGui::Begin("Heightmap");
    draw_texture_128(textures.height_tex);

    float last_height = height;
    ImGui::SliderFloat("Height##slider", &height, 0, 1);
    ImGui::InputFloat("Height##input", &height, 0, 1);
    if(last_height != height) {
        textures.height_tex = std::make_shared<texture>(HEIGHT_BINDING, height);
    }

    ImGui::LabelText("Selected Texture:##height", "%s", textures.height_tex->get_filepath());
    if(ImGui::Button("Select Texture##height", {50, 20})) {
        textures.height_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_porosity_controls() {
    ImGui::Begin("Porosity");
    draw_texture_128(textures.porosity_tex);

    float last_porosity = porosity;
    ImGui::SliderFloat("Porosity##slider", &porosity, 0, 1);
    ImGui::InputFloat("Porosity##input", &porosity, 0, 1);
    if(last_porosity != porosity) {
        textures.porosity_tex = std::make_shared<texture>(POROSITY_BINDING, porosity);
    }

    ImGui::LabelText("Selected Texture:##porosity", "%s", textures.porosity_tex->get_filepath());
    if(ImGui::Button("Select Texture##porosity", {50, 20})) {
        textures.porosity_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_translucence_controls() {
    ImGui::Begin("Translucence");
    draw_texture_128(textures.translucence_tex);

    float last_translucence = translucence;
    ImGui::SliderFloat("Translucence##slider", &translucence, 0, 1);
    ImGui::InputFloat("Translucence##input", &translucence, 0, 1);
    if(translucence != last_translucence) {
        textures.translucence_tex = std::make_shared<texture>(TRANSLUCENCE_BINDING, translucence);
    }

    ImGui::LabelText("Selected Texture:##translucence", "%s", textures.translucence_tex->get_filepath());
    if(ImGui::Button("Select Texture##translucence", {50, 20})) {
        textures.translucence_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_ao_controls() {
    ImGui::Begin("Ambient Occlusion");
    draw_texture_128(textures.ao_tex);

    ImGui::LabelText("Selected Texture:##ao", "%s", textures.ao_tex->get_filepath());
    if(ImGui::Button("Select Texture##ao", {50, 20})) {
        textures.ao_tex = pick_texture_from_disk();
    }
    ImGui::End();
}

void main_window::draw_top_menu() {
    if (ImGui::BeginMainMenuBar()) {
        if(ImGui::BeginMenu("File")) {
            draw_file_menu();
            ImGui::EndMenu();
        }

        if(ImGui::BeginMenu("Change background")) {
            if(ImGui::MenuItem("Blue Hour")) {
                change_background("blue_hour_at_pier.hdr");
            }
            if(ImGui::MenuItem("Autumn Road")) {
                change_background("golden_autumn_road.hdr");
            }
            if(ImGui::MenuItem("Road in Valley")) {
                change_background("road_in_valley.hdr");
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

void main_window::draw_file_menu() {
    if(ImGui::MenuItem("Export", "Ctrl+E")) {
        on_export_textures_pbr();
    }
    ImGui::Separator();
    if(ImGui::MenuItem("Refresh shaders", "Ctrl+R")) {
        gl_canvas->load_shaders();
    }

    if(ImGui::MenuItem("Quit", "Alt+F4")) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void main_window::change_background(std::string background_name) {
	gl_canvas->change_background(background_name);
}

void draw_texture_128(std::shared_ptr<texture> data) {
    ImGui::Image(data.get(), {128, 128});
}

std::shared_ptr<texture> pick_texture_from_disk() {
    nfdchar_t *outPath = nullptr;
    nfdresult_t result = NFD_OpenDialog(nullptr, nullptr, &outPath);

    if(result == NFD_OKAY) {
        std::string filepath(outPath);
        LOG(INFO) << "Grabbed file " << filepath;
        return std::make_shared<texture>(3, filepath);
    }
}
