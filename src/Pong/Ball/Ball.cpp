#include "Ball.h"

#include <cmath>

// Private

//Calculates X/Y velocity based on degrees
int Ball::getXVel() {
    int degrees{getDirection() == 0 ? 360 : getDirection()};
    return cos((degrees * 3.14) / 180) * getVel();
};

int Ball::getYVel() {
    int degrees{getDirection() == 0 ? 360 : getDirection()};
    return sin((degrees * 3.14) / 180) * getVel();
};

// Public
Ball::Ball() : Entity(0, 0) {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() + 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() + 20};
};

Ball::Ball(int velocity) : Entity(0, 0), m_velocity{velocity} {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() + 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() + 20};
}

Ball::Ball(int xPos, int yPos, int width, int height) : Entity(xPos, yPos) {
    m_bR = new Vec2D{getPos()->getX() + width, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() + height};
    m_tR = new Vec2D{getPos()->getX() + width, getPos()->getY() + height};
};

Ball::Ball(int xPos, int yPos, int width, int height, int velocity)
    : Entity(xPos, yPos), m_velocity{velocity} {
    m_bR = new Vec2D{getPos()->getX() + width, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() + height};
    m_tR = new Vec2D{getPos()->getX() + width, getPos()->getY() + height};
};

Ball::~Ball() {
    delete m_bR;
    delete m_tL;
    delete m_tR;

    m_bR = nullptr;
    m_tL = nullptr;
    m_tR = nullptr;
};

void Ball::movePos() { Vec2D vecMove{getXVel(), getYVel()}; };

void Ball::render(int (*render)()){};
