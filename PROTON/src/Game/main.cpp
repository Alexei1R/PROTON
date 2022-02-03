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
#include "VAO.h"
#include "VBO.h"
#include "IBO.h"


//float vertices[] = {
//
//    // positions          // colors           // texture coords
//    0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//    0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//   -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//   -0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
//
//    0.5f,  0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//    0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//   -0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//   -0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
//
//
//};
//unsigned int indices[] = {
//    0, 1, 3, // first triangle
//    1, 2, 3,
//
//    4,5,0,
//    5,1,0,
//
//    7,6,4,
//    6,5,4,
//
//    3,2,7,
//    2,6,7,
//
//    1,5,2,
//    5,6,2,
//
//    4,0,7,
//    0,3,7
//
//
//};

float cubevertices[] = {
 0.25f, 0.25f, 0.25f,           0.0f,  0.0f, -1.0f,           0.0f,  0.0f,
 1.25f, 0.25f, 0.25f,           0.0f,  0.0f, -1.0f,           1.0f,  0.0f,
 1.25f,  1.25f, 0.25f,           0.0f,  0.0f, -1.0f,           1.0f,  1.0f,
 1.25f,  1.25f, 0.25f,           0.0f,  0.0f, -1.0f,           1.0f,  1.0f,
0.25f,  1.25f, 0.25f,           0.0f,  0.0f, -1.0f,           0.0f,  1.0f,
0.25f, 0.25f, 0.25f,           0.0f,  0.0f, -1.0f,           0.0f,  0.0f,
0.25f, 0.25f,  1.25f,           0.0f,  0.0f,  1.0f,           0.0f,  0.0f,
 1.25f, 0.25f,  1.25f,           0.0f,  0.0f,  1.0f,           1.0f,  0.0f,
 1.25f,  1.25f,  1.25f,           0.0f,  0.0f,  1.0f,           1.0f,  1.0f,
 1.25f,  1.25f,  1.25f,           0.0f,  0.0f,  1.0f,           1.0f,  1.0f,
0.25f,  1.25f,  1.25f,           0.0f,  0.0f,  1.0f,           0.0f,  1.0f,
0.25f, 0.25f,  1.25f,           0.0f,  0.0f,  1.0f,           0.0f,  0.0f,
0.25f,  1.25f,  1.25f,          -1.0f,  0.0f,  0.0f,           1.0f,  0.0f,
0.25f,  1.25f, 0.25f,          -1.0f,  0.0f,  0.0f,           1.0f,  1.0f,
0.25f, 0.25f, 0.25f,          -1.0f,  0.0f,  0.0f,           0.0f,  1.0f,
0.25f, 0.25f, 0.25f,          -1.0f,  0.0f,  0.0f,           0.0f,  1.0f,
0.25f, 0.25f,  1.25f,          -1.0f,  0.0f,  0.0f,           0.0f,  0.0f,
0.25f,  1.25f,  1.25f,          -1.0f,  0.0f,  0.0f,           1.0f,  0.0f,
 1.25f,  1.25f,  1.25f,           1.0f,  0.0f,  0.0f,           1.0f,  0.0f,
 1.25f,  1.25f, 0.25f,           1.0f,  0.0f,  0.0f,           1.0f,  1.0f,
 1.25f, 0.25f, 0.25f,           1.0f,  0.0f,  0.0f,           0.0f,  1.0f,
 1.25f, 0.25f, 0.25f,           1.0f,  0.0f,  0.0f,           0.0f,  1.0f,
 1.25f, 0.25f,  1.25f,           1.0f,  0.0f,  0.0f,           0.0f,  0.0f,
 1.25f,  1.25f,  1.25f,           1.0f,  0.0f,  0.0f,           1.0f,  0.0f,
0.25f, 0.25f, 0.25f,           0.0f, -1.0f,  0.0f,           0.0f,  1.0f,
 1.25f, 0.25f, 0.25f,           0.0f, -1.0f,  0.0f,           1.0f,  1.0f,
 1.25f, 0.25f,  1.25f,           0.0f, -1.0f,  0.0f,           1.0f,  0.0f,
 1.25f, 0.25f,  1.25f,           0.0f, -1.0f,  0.0f,           1.0f,  0.0f,
0.25f, 0.25f,  1.25f,           0.0f, -1.0f,  0.0f,           0.0f,  0.0f,
0.25f, 0.25f, 0.25f,           0.0f, -1.0f,  0.0f,           0.0f,  1.0f,
0.25f,  1.25f, 0.25f,           0.0f,  1.0f,  0.0f,           0.0f,  1.0f,
 1.25f,  1.25f, 0.25f,           0.0f,  1.0f,  0.0f,           1.0f,  1.0f,
 1.25f,  1.25f,  1.25f,           0.0f,  1.0f,  0.0f,           1.0f,  0.0f,
 1.25f,  1.25f,  1.25f,           0.0f,  1.0f,  0.0f,           1.0f,  0.0f,
0.25f,  1.25f,  1.25f,           0.0f,  1.0f,  0.0f,           0.0f,  0.0f,
0.25f,  1.25f, 0.25f,           0.0f,  1.0f,  0.0f,           0.0f,  1.0f


};


float vertices[] =
{
    // positions          // normals           // texture coords
    /*-0.5f, -0.5f, -0.5f,           0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,           0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,           0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
     0.5f,  0.5f, -0.5f,           0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
    -0.5f,  0.5f, -0.5f,           0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, -0.5f,           0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,           0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,           0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,           0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
     0.5f,  0.5f,  0.5f,           0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
    -0.5f,  0.5f,  0.5f,           0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
    -0.5f, -0.5f,  0.5f,           0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,          -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,          -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
    -0.5f, -0.5f, -0.5f,          -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, -0.5f,          -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f,  0.5f,          -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,          -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,           1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,           1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
     0.5f, -0.5f, -0.5f,           1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
     0.5f, -0.5f, -0.5f,           1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
     0.5f, -0.5f,  0.5f,           1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,           1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,           0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
     0.5f, -0.5f, -0.5f,           0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
     0.5f, -0.5f,  0.5f,           0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,           0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,           0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,           0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
    -0.5f,  0.5f, -0.5f,           0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
     0.5f,  0.5f, -0.5f,           0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
     0.5f,  0.5f,  0.5f,           0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,           0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,           0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,           0.0f,  1.0f,  0.0f,  0.0f,  1.0f*/

    -10.0,0.0,-10.0,    0.0,1.0,0.0,          0.0 ,0.0,
     10.0,0.0,-10.0,    0.0,1.0,0.0,          1.0, 0.0,
     10.0,0.0, 10.0,    0.0,1.0,0.0,          1.0, 1.0,

     -10.0,0.0,-10.0,    0.0,1.0,0.0,         0.0 ,0.0,
    -10.0,0.0, 10.0,    0.0,1.0,0.0,          0.0, 1.0,
     10.0,0.0, 10.0,    0.0,1.0,0.0,          1.0, 1.0,

};

GLfloat lightVertices[] =
{ //     COORDINATES     //
    -0.1f, -0.1f,  0.1f,
    -0.1f, -0.1f, -0.1f,
     0.1f, -0.1f, -0.1f,
     0.1f, -0.1f,  0.1f,
    -0.1f,  0.1f,  0.1f,
    -0.1f,  0.1f, -0.1f,
     0.1f,  0.1f, -0.1f,
     0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
    0, 1, 2,
    0, 2, 3,
    0, 4, 7,
    0, 7, 3,
    3, 7, 6,
    3, 6, 2,
    2, 6, 5,
    2, 5, 1,
    1, 5, 4,
    1, 4, 0,
    4, 5, 6,
    4, 6, 7
};






int main(void)
{
    Window& window = Window::getInstanse();
    Camera camera(glm::vec3(0.0,0.0,3.0));
    glm::mat4 view(1.0f);
    glm::mat4 proj(1.0f);



    









    Shader shader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/vs.glsl", "C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/fs.glsl");
    shader.Bind();
    Texture tex("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Textures/floor.png");
	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	//EBO EBO1(indices, sizeof(indices));
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	

    glm::mat4 model(1.0f);
    

    //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.05f), glm::vec3(0.5f, 1.0f, 0.0f));
    view = camera.GetViewMatrix();
    proj = glm::perspective(glm::radians(65.0f), (float)800 / 800, 0.1f, 1000.0f);
    shader.SetUniformMatrix4f("proj", glm::value_ptr(proj),1);
    shader.SetUniformMatrix4f("model", glm::value_ptr(model),1);
    shader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);

    //light cube
    Shader lshader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/lvs.glsl", "C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/lfs.glsl");
    lshader.Bind();
    VAO lvao;
    lvao.Bind();
    VBO lvbo(lightVertices,sizeof(lightVertices));
    EBO libo(lightIndices, sizeof(lightIndices));
    VAO1.LinkAttrib(lvbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

    glm::mat4 lmodel(1.0f);
    glm::vec3 lightPos = glm::vec3(3.0, 4.0f, 0.75f);

    lmodel = glm::translate(lmodel, lightPos);
    //lmodel = glm::scale(lmodel,glm::vec3(0.5,0.5,0.5));

    lshader.SetUniformMatrix4f("proj", glm::value_ptr(proj), 1);
    lshader.SetUniformMatrix4f("lmodel", glm::value_ptr(lmodel), 1);
    lshader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);


    //================================
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);


    lshader.Bind();
    lshader.SetUniform3f("lcolor" , lightColor.x, lightColor.y, lightColor.z);


    shader.Bind();
    shader.SetUniform3f("lcolor" , lightColor.x, lightColor.y, lightColor.z);
    shader.SetUniform3f("lpos",lightPos.x,lightPos.y, lightPos.z);

    glm::vec3 camPos(1.0f);
    





    //cube implementation 
    Shader cubeshader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/cubevertex.glsl", "C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/ASSETS/cubefragment.glsl");
    cubeshader.Bind();
    Texture texcube("C:/Users/alexe/OneDrive/Desktop/PROJECTS/PROTON/PROTON/Textures/cat.gif");
    VAO cubevao;
    cubevao.Bind();
    VBO cubevbo(cubevertices, sizeof(cubevertices));
    cubevao.LinkAttrib(cubevbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    cubevao.LinkAttrib(cubevbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    cubevao.LinkAttrib(cubevbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    glm::mat4 cubemodel;
    cubemodel = glm::translate(cubemodel, glm::vec3(0.0, 1.0, 0.0));
    cubeshader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);
    cubeshader.SetUniformMatrix4f("proj", glm::value_ptr(proj), 1);
    cubeshader.SetUniformMatrix4f("cubemodel", glm::value_ptr(cubemodel), 1);

    

    cubeshader.SetUniform3f("lcolor", lightColor.x, lightColor.y, lightColor.z);
    cubeshader.SetUniform3f("lpos", lightPos.x, lightPos.y, lightPos.z);




    window.SetClearColor(glm::vec3(0.0,0.0,0.0));
    while (!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        window.Update();
        camera.Update();

        tex.Bind(0);
        shader.SetUniform1i("ourTexture", 0);
        texcube.Bind(1);
        cubeshader.SetUniform1i("cubeourTexture", 1);

        camPos = camera.GetCameraPos();

        //std::cout<< camPos.x << " : " << camPos.y << " : " << camPos.z <<" " << std::endl;
        shader.Bind();
        shader.SetUniform3f("camPos", camPos.x, camPos.y, camPos.z);




       
        shader.Bind();
       // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.05f), glm::vec3(0.5f, 1.0f, 0.0f));
        view = camera.GetViewMatrix();
        shader.SetUniformMatrix4f("view",glm::value_ptr(view),1);
        shader.SetUniformMatrix4f("model", glm::value_ptr(model), 1);

        VAO1.Bind();
        VBO1.Bind();
        //EBO1.Bind();
        //glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,nullptr);
        glDrawArrays(GL_TRIANGLES,0,36);



        //lmodel
        lshader.Bind();
        // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.05f), glm::vec3(0.5f, 1.0f, 0.0f));
        view = camera.GetViewMatrix();
        lshader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);
        lshader.SetUniformMatrix4f("lmodel", glm::value_ptr(lmodel), 1);

        lvao.Bind();
        lvbo.Bind();
        libo.Bind();
        //EBO1.Bind();
        glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,nullptr);
        



        cubeshader.Bind();
        cubevao.Bind();
        cubevbo.Bind();
        cubeshader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);
        cubeshader.SetUniformMatrix4f("cubemodel", glm::value_ptr(model), 1);

        glDrawArrays(GL_TRIANGLES,0,36);


        window.PoolEvents();
    }

    glfwTerminate();
    return 0;
}