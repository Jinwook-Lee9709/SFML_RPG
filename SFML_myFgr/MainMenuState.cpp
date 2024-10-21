#include "MainMenuState.h"

void MainMenuState::initVarialbes()
{
}

void MainMenuState::initBackground()
{
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	if (ResourceManager<sf::Texture>::Instance().Load("graphics/background.jpg")) {
		background.setTexture(&ResourceManager<sf::Texture>::Instance().Get("graphics/background.jpg"));
	}
	


}

void MainMenuState::initButtons()
{
	if (ResourceManager<sf::Font>::Instance().Load("fonts/DwarvenAxe.ttf")) {
		buttons["GAME_STATE"] = new Button(window->getSize().x * 0.5f, window->getSize().y * 0.75f, 150, 50, "fonts/DwarvenAxe.ttf", "New Game",
			sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
		buttons["SETTINGS"] = new Button(window->getSize().x * 0.5f, window->getSize().y * 0.75f + 70, 150, 50, "fonts/DwarvenAxe.ttf", "SETTINGS",
			sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
		buttons["EXIT_STATE"] = new Button(window->getSize().x * 0.5f, window->getSize().y * 0.75f + 140, 150, 50, "fonts/DwarvenAxe.ttf", "Quit",
			sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
	}
	
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	initVarialbes();
	initBackground();
	initButtons();

}

MainMenuState::~MainMenuState()
{
	for (auto pair : buttons) {
		delete pair.second;
	}
}

void MainMenuState::updateInput(const float& dt)
{


}

void MainMenuState::updateButtons()
{
	for (auto pair : buttons) {
		pair.second->update(InputManager::GetMousePosWindow(window));
	}
	//New Game
	if (buttons["GAME_STATE"]->isPressed()) {
		states->push(new GameState(window, states));
	}
	//QUit the game
	if (buttons["EXIT_STATE"]->isPressed()) {
		this->endState();
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

