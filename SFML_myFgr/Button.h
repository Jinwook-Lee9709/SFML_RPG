#pragma once
#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "InputManager.h"
#include "ResourceManager.h"

enum button_states{ BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height,
		std::string font, std::string text, 
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();
	//Accessors
	const bool isPressed() const;
	//Functions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};

