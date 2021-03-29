#pragma once
class Texture
{
public:
	Texture(const char* FileName, const char* Type);
	void Activate();
	void Delete();
private:
	unsigned int TextureID;
	int width;
	int height;
	int channels;
};

