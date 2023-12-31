#include "Text.h"

#include <string>
#include <string_view>

#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_ttf.h"

Text::Text(Vec2D* position, SDL_Renderer* renderer, int width, int height,
           TTF_Font* font)
    : m_currentFont{font} {
    m_surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

    SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);

    m_rect->x = position->getX();
    m_rect->y = position->getY();
    m_rect->w = width;
    m_rect->h = height;
};

Text::~Text() {
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);
}

void Text::Draw() { SDL_RenderCopy(m_renderer, m_texture, nullptr, m_rect); };

void Text::RenderText(int num) {
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = TTF_RenderText_Solid(m_currentFont, std::to_string(num).c_str(),
                                     {0xFF, 0xFF, 0xFF, 0xFF});

	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect->w, &m_rect->h);
}

void Text::RenderText(std::string string) {
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = TTF_RenderText_Solid(m_currentFont, string.c_str(),
                                     {0xFF, 0xFF, 0xFF, 0xFF});

	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect->w, &m_rect->h);
}
