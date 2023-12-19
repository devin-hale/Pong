#ifndef VEC2D_H
#define VEC2D_H

class Vec2D {
   private:
    int m_xPos{0};
    int m_yPos{0};

   public:
    Vec2D();

    Vec2D(int x, int y);

    Vec2D(Vec2D& other);

    Vec2D operator=(const Vec2D& other);

    Vec2D operator+(const Vec2D& other);

    Vec2D operator-(const Vec2D& other);

    Vec2D operator*(const Vec2D& other);

    int getX() { return m_xPos; };

    void setX(int num) { m_xPos = num; };

    int getY() { return m_yPos; };

    void setY(int num) { m_yPos = num; };
};

#endif
