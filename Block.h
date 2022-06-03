#pragma once
#include <SFML\Graphics.hpp>

class Block: public sf::Drawable
{
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape rectShape;
	bool destroyed{ false };
public:
	Block(float coorX, float coorY, float width, float height);
	Block() = delete;
	~Block() = default;

	void update();
	sf::Vector2f getPosition();

	float left();
	float right();
	float up();
	float down();

	bool isDestroyed();
	void destroy();
	sf::Vector2f getSize();
};
