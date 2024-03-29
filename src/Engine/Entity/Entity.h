#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>

#include "../Vec2D/Vec2D.h"

class Entity {
   public:
    enum EntityType { Blank, Ball, Net, Paddle };

   private:
    EntityType m_type{Blank};
    Vec2D* m_Pos{nullptr};

   protected:
    void deletePos();

    void setPos(Vec2D* vec);

   public:
    Entity() = delete;

    Entity(int x, int y, EntityType type);

    ~Entity();

    Entity(const Entity* other);

    Entity operator=(const Entity* other);

    Vec2D* getPos() { return m_Pos; };

    void movePos(int x, int y);

	virtual void move(int maxW, int maxH);

	virtual void setDirection(int angle);

	virtual void setVel(int vel);

    EntityType getType() { return m_type; };

    virtual void render(int (*renderPtr)(SDL_Renderer* renderer, int sx, int sy,
                                         int ex, int ey),
                        SDL_Renderer* r);

	virtual void handlePaddleCollide(class Paddle* paddle, int paddleType);

	virtual void resetPos();

};

#endif
