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
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos = glm::vec3(3.0, 10.0f, 5.0f);
    glm::vec3 camPos(1.0f);


    Shader modelShader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/vmonkey.glsl","C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/fmonkey.glsl");
    modelShader.Bind();
    Model monkeyModel("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Model/cube.fbx");
    
    modelShader.Bind();
    modelShader.SetUniform3f("lcolor", lightColor.x, lightColor.y, lightColor.z);
    modelShader.SetUniform3f("lpos", lightPos.x, lightPos.y, lightPos.z);



    //material uniform 
    Texture tex("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Textures/can.png");
    tex.Bind(0);
    modelShader.SetUniform1i("material.diffuse", 0);
    Texture texrama("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Textures/rama.png");
    texrama.Bind(1);
    modelShader.SetUniform1i("material.specular", 1);



    modelShader.SetUniform1f("material.shininess", 32.0f);

    modelShader.SetUniform3f("light.ambient", 0.2f, 0.2f, 0.2f);
    modelShader.SetUniform3f("light.diffuse", 1.0f, 1.0f, 1.0f); // darken the light a bit to fit the scene
    modelShader.SetUniform3f("light.specular", 1.0f, 1.0f, 1.0f);
    
    
    //new model
    Model mod("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Model/cube.fbx");
    





    int width, height;
    window.SetClearColor(glm::vec3(0.1,0.15,0.15));
    while (!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        glfwGetWindowSize(window.getGLFWwindow(),&width,&height);
        glViewport(0,0,width,height);
        window.Update();
        camera.Update();
        proj = glm::perspective(glm::radians(65.0f), (float)width / height, 0.1f, 1000.0f);
        view = camera.GetViewMatrix();
        camPos = camera.GetCameraPos();





        //draw mankey
        modelShader.Bind();
        modelShader.SetUniformMatrix4f("model",glm::value_ptr(model),1);
        modelShader.SetUniformMatrix4f("view",glm::value_ptr(view),1);
        modelShader.SetUniformMatrix4f("proj",glm::value_ptr(proj),1);
        modelShader.SetUniform3f("camPos",camPos.x, camPos.y, camPos.z);

        //lightColor.x = sin(glfwGetTime() * 2.0f);
        //lightColor.y = sin(glfwGetTime() * 0.7f);
        //lightColor.z = sin(glfwGetTime() * 1.3f);

        //glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // decrease the influence
        //glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // low influence

        //modelShader.SetUniform3f("lcolor", lightColor.x, lightColor.y, lightColor.z);
        //modelShader.SetUniform3f("light.ambient", ambientColor.x, ambientColor.y, ambientColor.z);
        //modelShader.SetUniform3f("light.diffuse", diffuseColor.x, diffuseColor.y, diffuseColor.z);
        
        
        tex.Bind(0);
        texrama.Bind(1);



        monkeyModel.Draw(modelShader);
        

        mod.Draw(modelShader);






        window.PoolEvents();
    }

    glfwTerminate();
    return 0;
}