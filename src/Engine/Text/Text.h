#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>

#include <string>

#include "../Vec2D/Vec2D.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_surface.h"

class Text {
   private:
    TTF_Font* m_currentFont{nullptr};
    SDL_Renderer* m_renderer{nullptr};
    SDL_Surface* m_surface{nullptr};
    SDL_Texture* m_texture{nullptr};
    SDL_Rect* m_rect{new SDL_Rect()};

   public:
	Text();
    Text(Vec2D* position, SDL_Renderer* renderer, int width, int height,
         TTF_Font* font);

    ~Text();
	
    void Draw();

    void RenderText(int num);

    void RenderText(std::string string);
};

#endif
