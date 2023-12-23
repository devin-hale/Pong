#ifndef BALL_H
#define BALL_H

#include "../../Engine/Entity/Entity.h"
#include "../../Engine/Vec2D/Vec2D.h"

class Ball : public Entity {
   private:
    // Bottom left point is the original m_Pos from the Entity class
    Vec2D* m_bR{nullptr};
    Vec2D* m_tL{nullptr};
    Vec2D* m_tR{nullptr};
    int m_velocity{0};
    // Direction is stored in degrees
    int m_direction{0};

    void setPosNull();

    int getXVel();

    int getYVel();

   public:
    Ball();

    Ball(int velocity);

    Ball(int xPos, int yPos, int velocity = 0);

    Ball(int xPos, int yPos, int width, int height);

    Ball(int xPos, int yPos, int width, int height, int velocity);

    ~Ball();

    int getVel() { return m_velocity; };

    void setVel(int vel) { m_velocity = vel; };

    int getDirection() { return m_direction; };

    void setDirection(int newDir) { m_direction = newDir; };

    void render(int (*renderPtr)(SDL_Renderer* renderer, int x1, int y1, int x2,
                                 int y2),
                SDL_Renderer* r) override;

    void handleXCollide(int maxW);

	void handleYCollide(int maxH);

    void movePos(int maxW, int maxH);

	void handleVCollide(Vec2D* vec, int maxW, int maxH);

};

#endif
