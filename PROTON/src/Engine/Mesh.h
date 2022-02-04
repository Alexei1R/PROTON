#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include "Shader.h"
#include "Texture.h"


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};




class Mesh {
private :
    unsigned int VAO, VBO, EBO;
protected:
    std::vector<Vertex> vertices;
    std::vector<unsigned int > indices;
    std::vector<Texture>texture;
public:
    Mesh(std::vector<Vertex>vertices, std::vector<unsigned int>indices);    
    void Draw(Shader& shader);
private:
    void setupMesh();


};














