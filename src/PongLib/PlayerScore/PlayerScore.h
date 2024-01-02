#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include "../../Engine/Text/Text.h"

class PlayerScore {
   private:
    int m_playerNo{0};
    Text* m_text{nullptr};
    int m_playerScore{0};

   public:
    PlayerScore() = delete;

    PlayerScore(int playerNo, Text* text);

	int getPlayerNo(){return m_playerNo;};

    void setScore(int score);

	void incrementScore();

    void Render();
};

#endif
