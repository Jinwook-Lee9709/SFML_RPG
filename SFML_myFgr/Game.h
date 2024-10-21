#pragma once
#include "GameState.h"
#include "MainMenuState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event ev;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;


	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//Initialization
	void initVarialbes();
	void initWindow();
	void initStates();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Fucntions

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();
	//Render
	void render();

	//Core
	void run();

};

