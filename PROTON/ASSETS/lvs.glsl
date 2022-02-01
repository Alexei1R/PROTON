#version 330 core
layout (location = 0) in vec3 lPos;

uniform mat4 lmodel;
uniform mat4 view;
uniform mat4 proj;



void main()
{
    gl_Position = proj * view * lmodel * vec4(lPos, 1.0);
    

}