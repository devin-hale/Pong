#ifndef PADDLE_H
#define PADDLE_H

#include "../../Engine/Entity/Entity.h"
#include "../../Engine/Vec2D/Vec2D.h"

class Paddle : public Entity {
   private:
    // Bottom left point is the original m_Pos from the Entity class
    Vec2D* m_bR{nullptr};
    Vec2D* m_tL{nullptr};
    Vec2D* m_tR{nullptr};
    int m_velocity{0};
    // Direction is stored in degrees
    int m_direction{0};
    bool m_isCollision{true};
    bool m_isPlayer{false};

    void setPosNull();

    int getXVel();

    int getYVel();

   public:
    Paddle(bool isPlayer, int maxW, int maxH);

    ~Paddle();

    int getVel() { return m_velocity; };

    Vec2D* getBR() { return m_bR; };
    Vec2D* getTL() { return m_tL; };
    Vec2D* getTR() { return m_tR; };

    virtual void setVel(int vel) override { m_velocity = vel; };

    int getDirection() { return m_direction; };

    virtual void setDirection(int newDir) override { m_direction = newDir; };

    void render(int (*renderPtr)(SDL_Renderer* renderer, int x1, int y1, int x2,
                                 int y2),
                SDL_Renderer* r) override;

    void move(int maxW, int maxH) override;

	virtual void resetPos() override;
};

#endif
