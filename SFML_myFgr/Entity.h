#pragma once
#include "MovementComponent.h"

class Entity
{
private:
	void initVariables();
protected:

	sf::Sprite sprite;
	            
	MovementComponent* movementComponent;


public:
	Entity();
	virtual ~Entity();

	void createSprite(const std::string tex);
	void createMovementComponent(const float maxVelocity);
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float dir_x, const float dir_y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

