#ifndef GLImage_H
#define GLImage_H
#include <string>
#include <vector>
#include <SDL2/SDL.h>


class GLImage {
public:
	GLImage();
	~GLImage();

	//Initializing Functions
	void Initialize(const int xSize, const int ySize, SDL_Renderer* pRenderer);

	//Function to set the color of a pixel
	void setPixel(const int x, const int y, const double red, const double green, const double blue);
	
	//Function to return the image for display
	void Display();

private:
	Uint32 ConvertColor(const double red, const double green, const double blue);
	void InitTexture();

private:
	//Arrays to store image data
	std::vector<std::vector<double>> m_rChannel;
	std::vector<std::vector<double>> m_gChannel;
	std::vector<std::vector<double>> m_bChannel;

	//store dimension of image
	int m_xSize, m_ySize;

	//SDL2 stuff
	SDL_Renderer *m_pRenderer;
	SDL_Texture* m_pTexture;
};



#endif