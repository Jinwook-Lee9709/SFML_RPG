#include "Entity.h"

void Entity::initVariables()
{
	movementComponent = nullptr;
}

Entity::Entity()
{
	initVariables();
	 
}

Entity::~Entity()
{
}

void Entity::createSprite(const std::string tex)
{
	if (ResourceManager<sf::Texture>::Instance().Load(tex)) {
		sprite.setTexture(ResourceManager<sf::Texture>::Instance().Get(tex));
	}
	
}

void Entity::createMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(maxVelocity);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->movementComponent)
	{
		movementComponent->move(dir_x, dir_y);
		sprite.move(movementComponent->getVelocity()*dt);
	}
	
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
