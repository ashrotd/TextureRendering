#include "GLViewNewModule.h"
#include <iostream>
#include <fstream>

//Default Constructor
GLViewNewModule::GLViewNewModule() {
	isRunning = true;
	pWindow = NULL;
	pRenderer = NULL;
}

bool GLViewNewModule :: onInit() {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	//creating SDL Window
	pWindow = SDL_CreateWindow("Ray Tracing Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,SDL_WINDOW_SHOWN);

	if (pWindow != NULL) {
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		m_image.Initialize(1280, 720, pRenderer);
		//Create some color variations
		for (int x = 0; x < 1280; ++x) {
			for (int y = 0; y < 720; ++y) {
				double red = (static_cast<double>(x) / 1280.0) * 255.0;
				double green = (static_cast<double>(y) / 720.0) * 255.0;
				m_image.setPixel(x, y, red, green,0.0 );
			}
		}
	}
	else {
		return false;

	}
	return true;
}
int GLViewNewModule::onExecute() {
	SDL_Event event;
	if (onInit() == false) {
		return -1;
	}
	while (isRunning) {
		while (SDL_PollEvent(&event) != 0) {
			onEvent(&event);
		}
		onLoop();
		onRender();
	}
}
void GLViewNewModule::onEvent(SDL_Event* event) {
	if (event->type == SDL_QUIT)
	{
		isRunning = false;
	}
}
void GLViewNewModule::onLoop() {

}
void GLViewNewModule::onRender() {
	//set the background color to white
	SDL_SetRenderDrawColor(pRenderer,255, 255, 255,255);
	SDL_RenderClear(pRenderer);
	
	//Display the image
	m_image.Display();
	//show the result
	SDL_RenderPresent(pRenderer);


}
void GLViewNewModule::onExit() {
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	SDL_Quit();
}
