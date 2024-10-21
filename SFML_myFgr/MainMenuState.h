#pragma once
#include "State.h"
#include "Button.h"
#include "GameState.h"


class MainMenuState : public State
{
private:
	sf::RectangleShape background;
	std::map<std::string, Button*> buttons;

	void initVarialbes();
	void initBackground();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~MainMenuState();


	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};

