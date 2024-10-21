#pragma once
#include "State.h"

class GameState : public State
{
private:
	Player* player;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~GameState();
	 
	void initPlayer();
	void updateInput(const float& dt);
	void update(const float& dt);
;	void render(sf::RenderTarget* target = nullptr);
};

