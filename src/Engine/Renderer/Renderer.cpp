#include "Renderer.h"
#include <SDL_render.h>

//Public
Renderer::Renderer(SDL_Window* window)
    : m_renderer{SDL_CreateRenderer(window, -1, 0)} {};

Renderer::~Renderer(){
	SDL_DestroyRenderer(getRenderer());
	setRendererNull();
	delete m_currentColor;
	setCurrentColorNull();
};

void Renderer::setColor(int r = 0, int g = 0, int b = 0, int a = 0){
	currentColor* cc{getCurrentColor()};	

	cc->m_r = r;
	cc->m_g = g;
	cc->m_b = b;
	cc->m_a = a;

	SDL_SetRenderDrawColor(getRenderer(), cc->m_r, cc->m_g, cc->m_b, cc->m_a);

	cc = nullptr;
}


void Renderer::renderBackGround(){
	setColor();
	SDL_RenderClear(getRenderer());
};

void Renderer::render(){
	SDL_RenderPresent(getRenderer());
};


