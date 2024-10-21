#include "MovementComponent.h"

MovementComponent::MovementComponent(float maxVelocity)
{
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f MovementComponent::getVelocity() const
{
	return this->velocity;
}

void MovementComponent::move(const float dir_x, const float dir_y)
{
	this->velocity.x = maxVelocity * dir_x;
	this->velocity.y = maxVelocity * dir_y;
}

void MovementComponent::update(const float& dt)
{
}
