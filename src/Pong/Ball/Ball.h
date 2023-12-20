#ifndef BALL_H
#define BALL_H

#include "../../Engine/Entity/Entity.h"
#include "../../Engine/Vec2D/Vec2D.h"
#include <SDL.h>


class Ball : Entity {
	private:
		//Bottom left point is the original m_Pos from the Entity class
		Vec2D* m_bR{nullptr};
		Vec2D* m_tL{nullptr};
		Vec2D* m_tR{nullptr};
		int m_velocity{0};
		//Direction is stored in degrees
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

		int getVel(){return m_velocity;};

		void setVel(int vel){m_velocity = vel;};

		int getDirection(){return m_direction;};

		void setDirection(int newDir){m_direction = newDir;};

		void render(int (*renderPtr)(SDL_Renderer* renderer, int sx, int sy, int ex, int ey), SDL_Renderer* r);

		void movePos();

};

#endif
