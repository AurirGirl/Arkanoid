#include "Paddle.h"


Paddle::Paddle(int coorX, int coorY)
{
	rectShape.setPosition(coorX, coorY);
	rectShape.setSize({paddleWidth,paddleHeight});
	rectShape.setFillColor(sf::Color::Green);
	rectShape.setOrigin(paddleWidth / 2.f,paddleHeight/2.f);
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(rectShape, state);
}

void Paddle::update()
{
	rectShape.move(velocity);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
	{
		velocity.x = -paddleVelocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < 800)
	{
		velocity.x = paddleVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}

float Paddle::up()
{
	return rectShape.getPosition().y - rectShape.getSize().y/2.f;
}

float Paddle::down()
{
	return rectShape.getPosition().y + rectShape.getSize().y/2.f;
}

float Paddle::left()
{
	return rectShape.getPosition().x - rectShape.getSize().x/2.f;
}

float Paddle::right()
{
	return rectShape.getPosition().x + rectShape.getSize().x/2.f;
}


sf::Vector2f Paddle::getPosition()
{
	return rectShape.getPosition();
}
