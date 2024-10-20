#include "MainMenuState.h"


void MainMenuState::initButtons()
{
	if (ResourceManager<sf::Font>::Instance().Load("fonts/Sansation.ttf")) {
		buttons["GAME_STATE"] = new Button(100, 100, 150, 50, "fonts/Sansation.ttf", "New Game",
			sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
		buttons["EXIT_STATE"] = new Button(100, 300, 150, 50, "fonts/Sansation.ttf", "Quit",
			sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
	}
	
}

MainMenuState::MainMenuState(sf::RenderWindow* window)
	: State(window)
{
	initButtons();

	background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	
	for (auto pair : buttons) {
		delete pair.second;
	}
}

void MainMenuState::endState()
{
	std::cout << "Ending GameStates!!" << std::endl;
}

void MainMenuState::updateInput(const float& dt)
{
	checkForQuit();

}

void MainMenuState::updateButtons()
{
	for (auto pair : buttons) {
		pair.second->update(InputManager::GetMousePosWindow(window));
	}
	//New Game
	if (buttons["GAME_STATE"]->isPressed()) {
		quit = true;
	}
	//QUit the game
	if (buttons["EXIT_STATE"]->isPressed()) {
		quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	updateInput(dt);
	updateButtons();
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto pair : buttons) {
		pair.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = window;
	}
	target->draw(background);
	
	renderButtons(target);
}

