#pragma once
#include <SFML/Graphics.hpp>


class Paddle : public sf::Drawable
{
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape rectShape;
	const float paddleWidth{ 80.0f };
	const float paddleHeight{ 20.0f };
	const float paddleVelocity{ 6.0f };
	sf::Vector2f velocity{ paddleVelocity,0.f };
public:
	Paddle() = delete;
	Paddle(int coorX, int coorY);
	~Paddle() = default;

	void update();
	float up();
	float down();
	float left();
	float right();

	sf::Vector2f getPosition();
};

