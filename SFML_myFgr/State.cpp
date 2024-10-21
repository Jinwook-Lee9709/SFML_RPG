#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
	:window(window), quit(false), states(states)
{
}
State::~State()
{
}

const bool& State::getQuit() const
{
	return quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		quit = true;
	}
}
