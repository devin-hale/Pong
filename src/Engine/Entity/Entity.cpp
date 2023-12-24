#include "Entity.h"

#include <iostream>

// Private

// Protected

void Entity::deletePos() {
    delete m_Pos;
    m_Pos = nullptr;
};

void Entity::setPos(Vec2D* vec) {
    deletePos();
    m_Pos = vec;
};

// Public

Entity::Entity(int x, int y, EntityType type)
    : m_Pos{new Vec2D{x, y}}, m_type{type} {};

Entity::~Entity() { delete m_Pos; }

Entity::Entity(const Entity* other)
    : m_Pos{new Vec2D{other->m_Pos->getX(), other->m_Pos->getY()}},
      m_type{other->m_type} {};

Entity Entity::operator=(const Entity* other) {
    return Entity{other->m_Pos->getX(), other->m_Pos->getY(), other->m_type};
};

void Entity::movePos(int x, int y) {
    Vec2D* moveVec{new Vec2D{*getPos() + Vec2D{x, y}}};
    setPos(moveVec);
};

void Entity::move(int maxW, int maxH){};
void Entity::setDirection(int angle){};
void Entity::setVel(int vel){};
void Entity::handlePaddleCollide(class Paddle* paddle){};

void Entity::render(int (*renderPtr)(SDL_Renderer* renderer, int sx, int sy,
                                     int ex, int ey),
                    SDL_Renderer* r){};
