#include "Net.h"

Net::Net(int winWidth, int winHeight)
    : Entity(winWidth / 2, 0, EntityType::Net),
      m_bot{new Vec2D{winWidth / 2, winHeight}} {};

Net::~Net(){
	delete m_bot;
};

void Net::render(int (*renderPtr)(SDL_Renderer* renderer, int x1, int y1,
                                  int x2, int y2),
                 SDL_Renderer* r) {
    renderPtr(r, getPos()->getX(), getPos()->getY(), m_bot->getX(),
              m_bot->getY());
};
