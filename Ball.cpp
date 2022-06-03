#include "Ball.h"

Ball::Ball(float coorX, float coorY)
{
	ball.setPosition(coorX, coorY);
	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(ballRadius, ballRadius);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(ball, state);
}

void Ball::update()
{
	ball.move(velocity);

	if (left() < 0)
	{
		velocity.x = ballVelocity;
	}
	else if (right() > 800)
	{
		velocity.x = -ballVelocity;
	}
	else if (up() < 0)
	{
		velocity.y = ballVelocity;
	}
	else if (down() > 600)
	{
		velocity.y = -ballVelocity;
	}
}

float Ball::up()
{
	return ball.getPosition().y - ball.getRadius();
}

float Ball::down()
{
	return ball.getPosition().y + ball.getRadius();
}

float Ball::left()
{
	return ball.getPosition().x - ball.getRadius();
}

float Ball::right()
{
	return ball.getPosition().x + ball.getRadius();
}

void Ball::moveUp()
{
	velocity.y = -ballVelocity;
}

void Ball::moveDown()
{
	velocity.y = ballVelocity;
}

void Ball::moveLeft()
{
	velocity.x = -ballVelocity;
}

void Ball::moveRight()
{
	velocity.x = ballVelocity;
}

sf::Vector2f Ball::getPosition()
{
	return ball.getPosition();
}
