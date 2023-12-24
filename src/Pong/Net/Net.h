#ifndef NET_H
#define NET_H

#include "../../Engine/Entity/Entity.h"
#include "../../Engine/Vec2D/Vec2D.h"

class Net : public Entity {
   private:
    // Top point is the original m_Pos from the Entity class
    Vec2D* m_bot{nullptr};
	bool m_isCollision{false};

    void setPosNull();

   public:
	Net(int winWidth, int winHeigth);

    void render(int (*renderPtr)(SDL_Renderer* renderer, int x1, int y1, int x2,
                                 int y2),
                SDL_Renderer* r) override;
};

#endif
