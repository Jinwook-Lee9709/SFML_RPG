#include "Player.h"

void Player::initVarialbes()
{
}

void Player::initComponenets()
{
	createMovementComponent(200.f);
}

Player::Player(float x, float y, const sf::String tex)
{
	initVarialbes();
	initComponenets();
	createSprite(tex);
	setPosition(x, y);   
}

Player::~Player()
{
}
