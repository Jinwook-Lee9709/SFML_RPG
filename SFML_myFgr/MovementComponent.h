#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "InputManager.h"
#include "ResourceManager.h"

class MovementComponent
{
private:
	float maxVelocity;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;
public:
	MovementComponent(float maxVelocity);
	virtual ~MovementComponent();

	const sf::Vector2f getVelocity() const;

	void move(const float dir_x, const float dir_y);
	void update(const float& dt);

};

