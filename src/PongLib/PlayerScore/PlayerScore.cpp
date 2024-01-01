#include "PlayerScore.h"

PlayerScore::PlayerScore(int playerNo, Text* text)
    : m_playerNo{playerNo}, m_text{text} {};

void PlayerScore::incrementScore(){
	m_playerScore++;
	m_text->RenderText(m_playerScore);
};

void PlayerScore::setScore(int score){
	m_playerScore = score;
	m_text->RenderText(m_playerScore);
};

void PlayerScore::Render(){
	m_text->Draw();
};
