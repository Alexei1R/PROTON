#version 330 core
out vec4 FragColor;
  
  uniform vec3 lcolor;

void main()
{
   FragColor = vec4(lcolor,1.0f);
}