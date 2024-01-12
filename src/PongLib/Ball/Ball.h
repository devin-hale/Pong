#ifndef BALL_H
#define BALL_H

#include <SDL_ttf.h>
#include "../../Engine/Game/Game.h"
#include "../../Engine/Entity/Entity.h"
#include "../../Engine/Vec2D/Vec2D.h"
#include "../../Engine/Random/Random.h"
#include "../Paddle/Paddle.h"

class Ball : public Entity {
   private:
    // Bottom left point is the original m_Pos from the Entity class
    Vec2D* m_bR{nullptr};
    Vec2D* m_tL{nullptr};
    Vec2D* m_tR{nullptr};
    int m_velocity{0};
    // Direction is stored in degrees
    int m_direction{0};
    bool m_isCollision{true};

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

    virtual void setVel(int vel) override { m_velocity = vel; };

    int getDirection() { return m_direction; };

    virtual void setDirection(int newDir) override { m_direction = newDir; };

    void render(int (*renderPtr)(SDL_Renderer* renderer, int x1, int y1, int x2,
                                 int y2),
                SDL_Renderer* r) override;

    int handleXCollide(int maxW, Game& game);

    void handleYCollide(int maxH);

	virtual void handlePaddleCollide(class Paddle* paddle, int paddleType) override;

    void movePos(int maxW, int maxH, class Paddle* paddle, class Paddle* cpuPaddle, Game& game);

    void handleVCollide(Vec2D* vec, int maxW, int maxH);

	void randomizeSpeed();
	
	void randomizeDirection();

	virtual void resetPos() override;
};

#endif
