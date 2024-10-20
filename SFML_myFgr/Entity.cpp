#include "Entity.h"

Entity::Entity()
{
	shape.setSize(sf::Vector2f(50.f, 50.f));
	shape.setFillColor(sf::Color::White);
	movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	shape.move(dir_x * movementSpeed * dt, dir_y * movementSpeed * dt);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
