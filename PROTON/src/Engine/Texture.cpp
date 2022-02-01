#include "Texture.h"

Texture::Texture(const char* path)
	:textureID(0), filepath(path), data(nullptr), tex_w(0), tex_h(0), tex_ch(0)
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(1);
	data = stbi_load(filepath, &tex_w, &tex_h, &tex_ch, 0);

	unsigned int colorMode = 0;
	if (tex_ch = 1) { colorMode = GL_RGB;  }
	if (tex_ch = 3) { colorMode = GL_RGB;  }
	if (tex_ch = 4) { colorMode = GL_RGBA;  }

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, colorMode, tex_w, tex_h, 0, colorMode, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}





}

Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}

void Texture::Bind(unsigned int slot)
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

