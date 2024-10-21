#pragma once
#include "Entity.h"


class State
{
protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::vector<sf::Texture*> textures;
	bool quit;

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;

	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

