#include "Paddle.h"

#include <math.h>

#include <cmath>
#include <iostream>
#include <thread>

constexpr double pi {3.14};

// Private

void Paddle::setPosNull() {
    deletePos();

    delete m_bR;
    delete m_tL;
    delete m_tR;

    m_bR = nullptr;
    m_tL = nullptr;
    m_tR = nullptr;
};

// Calculates X/Y velocity based on degrees
int Paddle::getXVel() {
    double angle{
        static_cast<double>(getDirection() == 0 ? 360 : getDirection())};
    double radians{(angle * pi) / 180};
    double xVel = cos(radians) * getVel();
    return round(xVel);
};

int Paddle::getYVel() {
    double angle{
        static_cast<double>(getDirection() == 0 ? 360 : getDirection())};
    double radians{(angle * pi) / 180};
    double yVel = sin(radians) * getVel();
    return round(yVel);
};

// Public
// TODO: Get rid of magic number 20 on constructors

Paddle::Paddle(bool isPlayer,int maxW, int maxH)
    : Entity{isPlayer ? 20 : maxW - 40, maxH/2 + 60, EntityType::Paddle}, m_isPlayer{isPlayer} {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - 120};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() - 120};
};

Paddle::~Paddle() {
    delete m_bR;
    delete m_tL;
    delete m_tR;

    m_bR = nullptr;
    m_tL = nullptr;
    m_tR = nullptr;
};

void Paddle::movePos(int maxW, int maxH) {
    using namespace std::chrono_literals;

    int yVel{getYVel()};

    Vec2D vecMove{0, yVel};

    if (vecMove.getY() + getPos()->getY() < 0) {
        vecMove.setY(getPos()->getY() * -1);
    }
    if (vecMove.getY() + getPos()->getY() > maxH) {
        vecMove.setY((getPos()->getY() - maxH) * -1);
    }

    Vec2D* newBL{new Vec2D{*getPos() + vecMove}};

    Vec2D* newBR{new Vec2D{*m_bR + vecMove}};

    Vec2D* newTL{new Vec2D{*m_tL + vecMove}};
    Vec2D* newTR{new Vec2D{*m_tR + vecMove}};

    // TODO find a different way to set pace
    std::this_thread::sleep_for(10ms);

    setPosNull();
    setPos(newBL);
    m_bR = newBR;
    m_tL = newTL;
    m_tR = newTR;
};

void Paddle::render(int (*renderPtr)(SDL_Renderer* renderer, int x1, int y1,
                                     int x2, int y2),
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
