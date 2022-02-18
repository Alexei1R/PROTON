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
    glm::vec3 lightPos = glm::vec3(-0.5, 2.0f, 3.0f);
    glm::vec3 camPos(1.0f);
    glm::vec3 camFront(1.0f);
    //model = glm::rotate(model,glm::radians(90.0f), glm::vec3(1, 0, 0));


    Shader modelShader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/vmonkey.glsl","C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/light.glsl");
    modelShader.Bind();
    Model monkeyModel("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Model/cub.fbx");
    
    modelShader.Bind();
    //modelShader.SetUniform3f("lcolor", lightColor.x, lightColor.y, lightColor.z);
    modelShader.SetUniform3f("lpos", lightPos.x, lightPos.y, lightPos.z);


    //material uniform 
    Texture tex("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Textures/can.png");
    tex.Bind(0);
    modelShader.SetUniform1i("material.diffuse", 0);
    Texture texrama("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Textures/rama.png");
    texrama.Bind(1);
    
    
    
    

    //cube pos
    glm::vec3 cubePositions[] = {
    glm::vec3(0.0f,  0.0f,  0.0f),
    glm::vec3(2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f,  2.0f, -2.5f),
    glm::vec3(1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    // position of poit lights
    glm::vec3 pointLightPositions[] = {
        glm::vec3(0.7f,0.2f,2.0f),
        glm::vec3(2.3f,-3.3f,-4.0f),
        glm::vec3(-4.0f,2.0f,-12.0f),
        glm::vec3(0.0f,0.0f,-3.0f)
    };

    modelShader.SetUniform3f("dirLight.direction", -0.2f, -1.0f, -0.3f);
    modelShader.SetUniform3f("dirLight.ambient", 0.05f, 0.05f, 0.05f);
    modelShader.SetUniform3f("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
    modelShader.SetUniform3f("dirLight.specular", 0.5f, 0.5f, 0.5f);


    // point light 1
    modelShader.SetUniform3f("pointLights[0].position", pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
    modelShader.SetUniform3f("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
    modelShader.SetUniform3f("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
    modelShader.SetUniform3f("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
    modelShader.SetUniform1f("pointLights[0].constant", 1.0f);
    modelShader.SetUniform1f("pointLights[0].linear", 0.09f);
    modelShader.SetUniform1f("pointLights[0].quadratic", 0.032f);
    // point light 2
    modelShader.SetUniform3f("pointLights[1].position", pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
    modelShader.SetUniform3f("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
    modelShader.SetUniform3f("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
    modelShader.SetUniform3f("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
    modelShader.SetUniform1f("pointLights[1].constant", 1.0f);
    modelShader.SetUniform1f("pointLights[1].linear", 0.09f);
    modelShader.SetUniform1f("pointLights[1].quadratic", 0.032f);
    // point light 3
    modelShader.SetUniform3f("pointLights[2].position", pointLightPositions[2].x , pointLightPositions[2].y , pointLightPositions[2].z);
    modelShader.SetUniform3f("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
    modelShader.SetUniform3f("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
    modelShader.SetUniform3f("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
    modelShader.SetUniform1f("pointLights[2].constant", 1.0f);
    modelShader.SetUniform1f("pointLights[2].linear", 0.09f);
    modelShader.SetUniform1f("pointLights[2].quadratic", 0.032f);
    // point light 4
    modelShader.SetUniform3f("pointLights[3].position", pointLightPositions[3].x , pointLightPositions[3].y, pointLightPositions[3].z);
    modelShader.SetUniform3f("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
    modelShader.SetUniform3f("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
    modelShader.SetUniform3f("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
    modelShader.SetUniform1f("pointLights[3].constant", 1.0f);
    modelShader.SetUniform1f("pointLights[3].linear", 0.09f);
    modelShader.SetUniform1f("pointLights[3].quadratic", 0.032f);

    modelShader.SetUniform3f("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    modelShader.SetUniform3f("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
    modelShader.SetUniform3f("spotLight.specular", 1.0f, 1.0f, 1.0f);
    modelShader.SetUniform1f("spotLight.constant", 1.0f);
    modelShader.SetUniform1f("spotLight.linear", 0.09f);
    modelShader.SetUniform1f("spotLight.quadratic", 0.032f);
    modelShader.SetUniform1f("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    modelShader.SetUniform1f("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

    modelShader.SetUniform1f("material.shininess", 32);

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
        camFront = camera.GetCameraFront();






        //draw mankey
        modelShader.Bind();
        //modelShader.SetUniformMatrix4f("model",glm::value_ptr(model),1);
        modelShader.SetUniformMatrix4f("view",glm::value_ptr(view),1);
        modelShader.SetUniformMatrix4f("proj",glm::value_ptr(proj),1);
        modelShader.SetUniform3f("viewPos",camPos.x, camPos.y, camPos.z);

        
        modelShader.SetUniform3f("spotLight.position",camPos.x, camPos.y, camPos.z);
        modelShader.SetUniform3f("spotLight.direction", camFront.x, camFront.y, camFront.z);
        
        

        tex.Bind(0);
        texrama.Bind(1);

        
        //multiple cubs
        for (unsigned int  i = 0; i < 10; i++)
        {
            glm::mat4 modelmoltiplecub(1.0f);
            modelmoltiplecub = glm::translate(modelmoltiplecub,cubePositions[i]);

            modelmoltiplecub = glm::scale(modelmoltiplecub, glm::vec3(0.5, 0.5, 0.5));
            modelShader.SetUniformMatrix4f("model", glm::value_ptr(modelmoltiplecub), 1);

            monkeyModel.Draw(modelShader);
        }







        window.PoolEvents();
    }


    // Cleanup

    glfwTerminate();
    return 0;
}