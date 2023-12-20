#ifndef BALL_H
#define BALL_H

#include "../../Engine/Entity/Entity.h"
#include "../../Engine/Vec2D/Vec2D.h"

class Ball : Entity {
	private:
		//Bottom left point is the original m_Pos from the Entity class
		Vec2D* m_bR{nullptr};
		Vec2D* m_tL{nullptr};
		Vec2D* m_tR{nullptr};
		int m_velocity{0};
		//Direction is stored in degrees
		int m_direction{0};

		int getXVel();

		int getYVel();

	public:
		Ball();

		Ball(int velocity);

		Ball(int xPos, int yPos, int width, int height);

		Ball(int xPos, int yPos, int width, int height, int velocity);

		~Ball();

		int getVel(){return m_velocity;};

		void setVel(int vel){m_velocity = vel;};

		int getDirection(){return m_direction;};

		void setDirection(int newDir){m_direction = newDir;};

		void movePos();	

		void render(int (*render)());

};

#endif
