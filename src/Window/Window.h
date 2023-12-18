#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window {
   private:
    int m_width{1280};
    int m_height{720};
    SDL_Window* m_window{nullptr};

   public:
    Window();

    Window(int width, int height);

	~Window();

	Window(const Window& copy);

	Window& operator=(const Window&);

	int getWidth() const {return m_width;};

	int getHeight() const {return m_height;};

	SDL_Window* getWindow() const {return m_window;};
};

#endif
