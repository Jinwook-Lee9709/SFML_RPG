#include "Button.h"

Button::Button(float x, float y, float width, float height, std::string font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));
	shape.setOrigin(shape.getSize().x * 0.5f, shape.getSize().y * 0.5f);
	this->buttonState = BTN_IDLE;

	this->text.setFont(ResourceManager<sf::Font>::Instance().Get(font));
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(30);
	this->text.setOrigin(this->text.getLocalBounds().width * 0.5f, this->text.getLocalBounds().height);
	this->text.setPosition(
		this->shape.getPosition().x,
		this->shape.getPosition().y
	);
	
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{

}

//Accessors
const bool Button::isPressed() const {
	if (buttonState == BTN_ACTIVE)
		return true;
	return false;
}
//Functions
void Button::update(const sf::Vector2f mousePos)
{
	//Idle
	this->buttonState = BTN_IDLE;
	//Hover
	if (shape.getGlobalBounds().contains(mousePos)) {
		this->buttonState = BTN_HOVER;
		//Pressed
		if (InputManager::GetBtnPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_ACTIVE;
		}
	}
	switch (buttonState)
	{
	case BTN_IDLE:
		shape.setFillColor(idleColor);
		break;
	case BTN_HOVER:
		shape.setFillColor(hoverColor);
		break;
	case BTN_ACTIVE:
		shape.setFillColor(activeColor);
		break;
	default:
		shape.setFillColor(sf::Color::Red);
		break;
	}

}

void Button::render(sf::RenderTarget* target)
{
	target->draw(shape);
	target->draw(text);
}
