#include "Ball.h"

#include <math.h>

#include <cmath>
#include <iostream>
#include <thread>

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
    double angle{
        static_cast<double>(getDirection() == 0 ? 360 : getDirection())};
    double radians{(angle * pi) / 180};
    double yVel = sin(radians) * getVel();
    return round(yVel);
};

// Public
// TODO: Get rid of magic number 20 on constructors

Ball::Ball() : Entity{0, 0, EntityType::Ball} {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() - 20};
};

Ball::Ball(int velocity)
    : Entity(0, 0, EntityType::Ball), m_velocity{velocity} {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() - 20};
}

Ball::Ball(int xPos, int yPos, int velocity)
    : Entity{xPos, yPos, Entity::Ball}, m_velocity{0} {
    m_bR = new Vec2D{getPos()->getX() + 20, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - 20};
    m_tR = new Vec2D{getPos()->getX() + 20, getPos()->getY() - 20};
};

Ball::Ball(int xPos, int yPos, int width, int height)
    : Entity(xPos, yPos, EntityType::Ball) {
    m_bR = new Vec2D{getPos()->getX() + width, getPos()->getY()};
    m_tL = new Vec2D{getPos()->getX(), getPos()->getY() - height};
    m_tR = new Vec2D{getPos()->getX() + width, getPos()->getY() - height};
};

Ball::Ball(int xPos, int yPos, int width, int height, int velocity)
    : Entity(xPos, yPos, EntityType::Ball), m_velocity{velocity} {
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

void Ball::movePos(int maxW, int maxH, class Paddle* playerPaddle, class Paddle* cpuPaddle) {
    using namespace std::chrono_literals;

    handleXCollide(maxW);
    handleYCollide(maxH);
	//handlePaddleCollide(playerPaddle);
	//handlePaddleCollide(cpuPaddle);

    int xVel{getXVel()};
    int yVel{getYVel()};

    Vec2D vecMove{xVel, yVel};

    if (vecMove.getX() + getPos()->getX() < 0) {
        vecMove.setX(getPos()->getX() * -1);
    }
    if (vecMove.getX() + getPos()->getX() > maxW) {
        vecMove.setX((getPos()->getX() - maxW) * -1);
    }
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

void Ball::render(int (*renderPtr)(SDL_Renderer* renderer, int x1, int y1,
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

void Ball::handlePaddleCollide(class Paddle* paddle) {
    int x = getPos()->getX();
    int y = getPos()->getY();
    int xVel = getXVel();
    int yVel = getYVel();

    bool xCollidePlayerPaddle = x <= paddle->getBR()->getX();
    bool yCollidePlayerPaddle =
        (y <= paddle->getBR()->getY() || y >= paddle->getTR()->getY()) &&
        (m_tL->getY() <= paddle->getBR()->getY() ||
         m_tL->getY() >= paddle->getTR()->getY());

    bool xCollideCPUPaddle = m_bR->getX() >= paddle->getPos()->getX();
    bool yCollideCPUPaddle = (m_bR->getY() <= paddle->getPos()->getY() ||
                              y >= paddle->getTL()->getY()) &&
                             (m_tR->getY() <= paddle->getTL()->getY() ||
                              m_tR->getY() >= paddle->getTL()->getY());

    if (xCollidePlayerPaddle && yCollidePlayerPaddle) {
        if (yVel > 0) {
            // Ball is moving downward, adjust the direction
            m_direction = (m_direction + 270) % 360;
        } else if (yVel < 0) {
            // Ball is moving upward, adjust the direction
            m_direction = (m_direction + 90) % 360;
        } else {
            // Ball is moving horizontally, reverse x direction
            m_direction = (180 - m_direction) % 360;
        }

    } else if (xCollideCPUPaddle && yCollideCPUPaddle) {
        if (yVel > 0) {
            // Ball is moving downward, adjust the direction
            m_direction = (m_direction + 90) % 360;
        } else if (yVel < 0) {
            // Ball is moving upward, adjust the direction
            m_direction = (m_direction + 270) % 360;
        } else {
            // Ball is moving horizontally, reverse x direction
            m_direction = (180 - m_direction) % 360;
        }
    };
};

void Ball::handleXCollide(int maxW) {
    int x = getPos()->getX();
    int y = getPos()->getY();
    int xVel = getXVel();
    int yVel = getYVel();

    // Check for left wall collision
    if (x <= 0 && xVel < 0) {
        if (yVel > 0) {
            // Ball is moving downward, adjust the direction
            m_direction = (m_direction + 270) % 360;
        } else if (yVel < 0) {
            // Ball is moving upward, adjust the direction
            m_direction = (m_direction + 90) % 360;
        } else {
            // Ball is moving horizontally, reverse x direction
            m_direction = (180 - m_direction) % 360;
        }
    }

    // Check for right wall collision
    if (x >= maxW && xVel > 0) {
        if (yVel > 0) {
            // Ball is moving downward, adjust the direction
            m_direction = (m_direction + 90) % 360;
        } else if (yVel < 0) {
            // Ball is moving upward, adjust the direction
            m_direction = (m_direction + 270) % 360;
        } else {
            // Ball is moving horizontally, reverse x direction
            m_direction = (180 - m_direction) % 360;
        }
    }
}

void Ball::handleYCollide(int maxH) {
    if (getPos()->getY() <= 0 || m_bR->getY() >= maxH) {
        m_direction = m_direction * -1;
    }
};

void Ball::handleVCollide(Vec2D* vec, int maxW, int maxH) {
    if (vec->getX() < 0) {
        vec->setX(0);
    }
    if (vec->getX() > maxW) {
        vec->setX(maxW);
    }
    if (vec->getY() < 0) {
        vec->setY(0);
    }
    if (vec->getY() > maxH) {
        vec->setY(maxH);
    }
};
