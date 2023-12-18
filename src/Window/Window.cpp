#include "Window.h"

#include <SDL_video.h>

Window::Window() {
    m_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
};

Window::Window(int width, int height) : m_width{width}, m_height{height} {
    m_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
};

Window::~Window() { SDL_DestroyWindow(m_window); };

Window::Window(const Window& other)
    : Window(other.getWidth(), other.getHeight()){

      };
