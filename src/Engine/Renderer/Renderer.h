#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

#include "../Vec2D/Vec2D.h"

struct currentColor {
    int m_r{0};
    int m_g{0};
    int m_b{0};
    int m_a{0};
};

class Renderer {
   private:
    SDL_Renderer* m_renderer{nullptr};
    currentColor* m_currentColor{new currentColor{0, 0, 0, 0}};

    void setRendererNull() { m_renderer = nullptr; };

    void setCurrentColorNull() { m_currentColor = nullptr; };

   public:
    int (*m_drawLinePtr)(SDL_Renderer* renderer, int sx, int sy, int ex, int ey){SDL_RenderDrawLine};

    Renderer() = delete;

    Renderer(SDL_Window* window);

    ~Renderer();

    SDL_Renderer* getRenderer() { return m_renderer; };

    currentColor* getCurrentColor() { return m_currentColor; };

    void setColor(int r, int g, int b, int a);

    void renderBackGround();

    void render();
};

#endif
