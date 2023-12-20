#include "Entity.h"
#include <iostream>

//Private

//Protected

void Entity::deletePos(){
	delete m_Pos;
	m_Pos = nullptr;
};

void Entity::setPos(Vec2D* vec){
	deletePos();	
	m_Pos = vec;
};

//Public

Entity::Entity(int x, int y) : m_Pos{new Vec2D{x, y}} {};

Entity::~Entity() { delete m_Pos; }

Entity::Entity(const Entity* other)
    : m_Pos{new Vec2D{other->m_Pos->getX(), other->m_Pos->getY()}} {};

Entity Entity::operator=(const Entity* other){
	return Entity(other->m_Pos->getX(), other->m_Pos->getY());
};

