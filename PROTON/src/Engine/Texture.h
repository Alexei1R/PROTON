#pragma once
#include <iostream>
#include <string>
#include "stb_image.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Texture
{
private:
	unsigned int textureID;
	const char* filepath;
	unsigned char* data;
	int tex_w, tex_h, tex_ch;
	
public:

	 Texture(const char* path);
	
	void Bind(unsigned int slot = 0);
	void UnBind();




	inline int GetWidth() const { return tex_w; }
	inline int GetHight() const { return tex_h; }

public:
	~Texture();
};






