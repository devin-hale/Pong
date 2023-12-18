#include "Vec2D.h"

// Public
Vec2D::Vec2D(int x, int y) : m_xPos{x}, m_yPos{y} {};

Vec2D::Vec2D(Vec2D& other) : m_xPos{other.m_xPos}, m_yPos{other.m_yPos} {};

Vec2D Vec2D::operator=(Vec2D& other){
	return Vec2D{other.m_xPos, other.m_yPos};
};

Vec2D Vec2D::operator+(Vec2D& other){
	return Vec2D{m_xPos + other.m_xPos, m_yPos + other.m_yPos};
};

Vec2D Vec2D::operator-(Vec2D& other){
	return Vec2D{m_xPos - other.m_xPos, m_yPos - other.m_yPos};
};


Vec2D Vec2D::operator*(Vec2D& other){
	return Vec2D{m_xPos * other.m_xPos, m_yPos + other.m_yPos};
}
