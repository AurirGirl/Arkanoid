#pragma once
#include<SFML/Graphics.hpp>

class Ball : public sf::Drawable
{
private:
    sf::CircleShape ball;
	const float ballRadius{ 10.0f };
	const float ballVelocity{ 3.0f };
	sf::Vector2f velocity{ ballVelocity,ballVelocity };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Ball() = delete;
	Ball(float coorX, float coorY);
	~Ball() = default;
	void update();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	sf::Vector2f getPosition();

	float up();
	float down();
	float left();
	float right();
};

