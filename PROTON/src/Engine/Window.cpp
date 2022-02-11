#include <iostream>
#include "window.h"
#include "keyboard.h"
#include "mouse.h"
#include <sstream>




	Window::Window(const std::string& name, int width, int height)
	{
		init(name, width, height);



	}

	void Window::init(const std::string& name, int width, int height)
	{


		this->name = name;
		this->width = width;
		this->height = height;


		if (!glfwInit())
		{
			std::cout << "glfw don't init";
		}

		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);




		if (!window)
		{
			std::cout << "window don't init";
		}


		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
			std::cout << "GLEW failed..." << std::endl;

		glfwSetWindowUserPointer(window, this);
		glfwSetCursorPosCallback(window,Mouse::cursorPosCallback );
		glfwSetScrollCallback(window, Mouse::mouseWheelCallback);
		glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);
		glfwSetKeyCallback(window, Keyboard::keyCallback);
		glfwSetWindowSizeCallback(window, window_size_callback);

		

		

		glClearColor(0.1,0.2,0.3,1.0);
		glEnable(GL_DEPTH_TEST);
	}
	void Window::window_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::SetClearColor(glm::vec3 color) {
		glClearColor(color.x, color.y,color.z, 1.0);
	}
	void Window::Update() {

		if(Keyboard::key(GLFW_KEY_ESCAPE)){ glfwSetWindowShouldClose(window, GLFW_TRUE); }
		if(Keyboard::key(GLFW_KEY_F1)){ glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
		if(Keyboard::key(GLFW_KEY_F2)){ glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); }


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}
	void Window::PoolEvents() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}















	Window::~Window()
	{
		glfwWindowShouldClose(window);
	}

