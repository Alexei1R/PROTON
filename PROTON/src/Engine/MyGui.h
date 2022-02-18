#pragma once 
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

namespace Gui {

	class MyGui {
	public :
		GLFWwindow* window;
	public:
		MyGui(GLFWwindow* window);
		~MyGui();

		void Render();
		void Update();


	private:


		void Cleanup();
		void Draw();





	};












}







