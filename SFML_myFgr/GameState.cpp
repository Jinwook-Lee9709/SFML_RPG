#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window)
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Ending GameStates!!" << std::endl;
}

void GameState::updateInput(const float& dt)
{
	if (InputManager::GetKeyHeld(sf::Keyboard::A))
		player.move(dt, -1.f, 0.f);
	if (InputManager::GetKeyHeld(sf::Keyboard::D))
		player.move(dt, 1.f, 0.f);
	if (InputManager::GetKeyHeld(sf::Keyboard::W))
		player.move(dt, 0.f, -1.f);
	if (InputManager::GetKeyHeld(sf::Keyboard::S))
		player.move(dt, 0.f, 1.f);
	checkForQuit();
}

void GameState::update(const float& dt)
{
	updateInput(dt);
	player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = window;
		player.render(window);
	}
}
	
