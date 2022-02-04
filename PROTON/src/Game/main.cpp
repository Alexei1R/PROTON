#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"
#include "Camera.h"
#include "keyboard.h"
#include "mouse.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"














int main(void)
{
    Window& window = Window::getInstanse();
    Camera camera(glm::vec3(0.0,0.0,3.0));
    

    glm::mat4 view(1.0f);
    glm::mat4 proj(1.0f);
    glm::mat4 model(1.0f);
    glm::mat4 lmodel(1.0f);
    glm::vec3 lightColor = glm::vec3(0.5f, 1.0f, 1.0f);
    glm::vec3 lightPos = glm::vec3(3.0, 10.0f, 5.0f);
    glm::vec3 camPos(1.0f);


    Shader modelShader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/vmonkey.glsl","C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/fmonkey.glsl");
    modelShader.Bind();
    Model monkeyModel("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Model/monkey.obj");
    
    modelShader.Bind();
    modelShader.SetUniform3f("lcolor", lightColor.x, lightColor.y, lightColor.z);
    modelShader.SetUniform3f("lpos", lightPos.x, lightPos.y, lightPos.z);


    
    

    





    int width, height;
    window.SetClearColor(glm::vec3(0.1,0.15,0.15));
    while (!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        window.Update();
        camera.Update();
        proj = glm::perspective(glm::radians(65.0f), (float)800 / 800, 0.1f, 1000.0f);
        view = camera.GetViewMatrix();
        camPos = camera.GetCameraPos();





        //draw mankey
        modelShader.Bind();
        modelShader.SetUniformMatrix4f("model",glm::value_ptr(lmodel),1);
        modelShader.SetUniformMatrix4f("view",glm::value_ptr(view),1);
        modelShader.SetUniformMatrix4f("proj",glm::value_ptr(proj),1);
        modelShader.SetUniform3f("camPos",camPos.x, camPos.y, camPos.z);



        monkeyModel.Draw(modelShader);
        

        






        window.PoolEvents();
    }

    glfwTerminate();
    return 0;
}