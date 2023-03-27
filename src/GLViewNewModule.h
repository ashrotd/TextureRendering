#include <SDL2/SDL.h>
#include "GLImage.h"
class GLViewNewModule {
public:
	GLViewNewModule();
	int onExecute();
	bool onInit();
	void onEvent(SDL_Event* event);
	void onLoop();
	void onRender();
	void onExit();

private:
	//Intance of GLImage class to store the image
	GLImage m_image;
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};