#include "Vec2D.h"
#include "iostream"

// Public
Vec2D::Vec2D(int x, int y) : m_xPos{x}, m_yPos{y} {};

Vec2D::Vec2D(Vec2D& other) : m_xPos{other.m_xPos}, m_yPos{other.m_yPos} {};

Vec2D Vec2D::operator=(const Vec2D& other){
	return Vec2D{other.m_xPos, other.m_yPos};
};

Vec2D Vec2D::operator+(const Vec2D& other){
	return Vec2D{m_xPos + other.m_xPos, m_yPos + other.m_yPos};
};

Vec2D Vec2D::operator-(const Vec2D& other){
	return Vec2D{m_xPos - other.m_xPos, m_yPos - other.m_yPos};
};


Vec2D Vec2D::operator*(const Vec2D& other){
	return Vec2D{m_xPos * other.m_xPos, m_yPos + other.m_yPos};
}

void Vec2D::printVec(){
	std::cout << "X: " << getX() << "\n";
	std::cout << "Y: " << getY() << "\n\n";
};

