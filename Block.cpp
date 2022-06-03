#include "Block.h"

Block::Block(float coorX, float coorY, float rectWidth, float rectHeight)
{
	rectShape.setPosition(coorX, coorY);
	rectShape.setSize({ rectWidth,rectHeight });
	rectShape.setFillColor(sf::Color::Green);
	rectShape.setOrigin(rectWidth / 2.f, rectHeight / 2.f);
}

void Block::update()
{


}

sf::Vector2f Block::getPosition()
{
	return rectShape.getPosition();
}

float Block::left()
{
	return rectShape.getPosition().x - rectShape.getSize().x / 2.f;
}

float Block::right()
{
	return rectShape.getPosition().x + rectShape.getSize().x / 2.f;
}

float Block::up()
{
	return rectShape.getPosition().y - rectShape.getSize().y / 2.f;
}

float Block::down()
{
	return rectShape.getPosition().y + rectShape.getSize().y / 2.f;
}

bool Block::isDestroyed()
{
	return destroyed;
}

void Block::destroy()
{
	destroyed = true;
}

sf::Vector2f Block::getSize()
{
	return rectShape.getSize();
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(rectShape, state);
}
