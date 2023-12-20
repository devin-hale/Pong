#ifndef ENTITY_H
#define ENTITY_H

#include "../Vec2D/Vec2D.h"

class Entity {
   private:
    Vec2D* m_Pos{nullptr};

	void deletePos();

	void setPos(Vec2D* vec);

   public:
    Entity() = delete;

    Entity(int x, int y);

    ~Entity();

    Entity(const Entity* other);

    Entity operator=(const Entity* other);

    Vec2D* getPos() { return m_Pos; };

    void movePos(int x, int y);
};

#endif
