#include "Ball.h"

#include <math.h>

#include <cmath>
#include <thread>

#include "SDL_render.h"
#include <iostream>

constexpr double pi = 3.14;

// Private

void Ball::setPosNull() {
    deletePos();

    delete m_bR;
    delete m_tL;
    delete m_tR;

    m_bR = nullptr;
    m_tL = nullptr;
    m_tR = nullptr;
};

// Calculates X/Y velocity based on degrees
int Ball::getXVel() {
    double angle{
        static_cast<double>(getDirection() == 0 ? 360 : getDirection())};
    double radians{(angle * pi) / 180};
    double xVel = cos(radians) * getVel();
    return round(xVel);
};

int Ball::getYVel() {
    double angle{static_cast<double>(getDirection() == 0 ? 360 : getDirection())};
    double radians{(angle * pi) / 180};
    double yVel = sin(radians) * getVel();
    return round(yVel);
};

// Public
// TODO: Get rid of magic number 20 on constructors
Ball::Ball() : Entity(0, 0) {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() - 20};
};

Ball::Ball(int velocity) : Entity(0, 0), m_velocity{velocity} {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() - 20};
}

Ball::Ball(int xPos, int yPos, int velocity)
    : Entity{xPos, yPos}, m_velocity{0} {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() - 20};
};

Ball::Ball(int xPos, int yPos, int width, int height) : Entity(xPos, yPos) {
    m_bR = new Vec2D{getPos()->getX() + width, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - height};
    m_tR = new Vec2D{getPos()->getX() + width, getPos()->getY() - height};
};

Ball::Ball(int xPos, int yPos, int width, int height, int velocity)
    : Entity(xPos, yPos), m_velocity{velocity} {
    m_bR = new Vec2D{getPos()->getX() + width, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - height};
    m_tR = new Vec2D{getPos()->getX() + width, getPos()->getY() - height};
};

Ball::~Ball() {
    delete m_bR;
    delete m_tL;
    delete m_tR;

    m_bR = nullptr;
    m_tL = nullptr;
    m_tR = nullptr;
};

void Ball::movePos() {
    using namespace std::chrono_literals;

    Vec2D vecMove{getXVel(), getYVel()};

    Vec2D* newBL{new Vec2D{*getPos() + vecMove}};
    Vec2D* newBR{new Vec2D{*m_bR + vecMove}};
    Vec2D* newTL{new Vec2D{*m_tL + vecMove}};
    Vec2D* newTR{new Vec2D{*m_tR + vecMove}};

    // TODO find a different way to set pace
    std::this_thread::sleep_for(50ms);

    setPosNull();
    setPos(newBL);
    m_bR = newBR;
    m_tL = newTL;
    m_tR = newTR;
};

void Ball::render(int (*renderPtr)(SDL_Renderer* renderer, int sx, int sy,
                                   int ex, int ey),
                  SDL_Renderer* r) {
    // BL to BR
    renderPtr(r, getPos()->getX(), getPos()->getY(), m_bR->getX(),
              m_bR->getY());
    // BR to TR
    renderPtr(r, m_bR->getX(), m_bR->getY(), m_tR->getX(), m_tR->getY());
    // TR to TL
    renderPtr(r, m_tR->getX(), m_tR->getY(), m_tL->getX(), m_tL->getY());
    // TL to BL
    renderPtr(r, m_tL->getX(), m_tL->getY(), getPos()->getX(),
              getPos()->getY());
};
