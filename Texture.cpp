#pragma once
#include "Texture.h"
#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>

Texture::Texture(const char* FileName, const char* Type) {
	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	//stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(FileName, &width, &height, &channels, 0);
	if (data) {
		if (Type == "JPG") {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else if (Type == "PNG") {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}
	else {
		std::cout << "Failed to load texture." << std::endl;
	}
	stbi_set_flip_vertically_on_load(false);
	stbi_image_free(data);
}

void Texture::Activate() {
	glActiveTexture(0x84C0 + TextureID - 1);
	glBindTexture(GL_TEXTURE_2D, TextureID);
}

void Texture::Delete() {
	glDeleteTextures(1, &TextureID);
}