
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

template<class T1, class T2>bool isIntersecting(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right()
        && A.down() >= B.up() && A.up() <= B.down();
}

bool collisionTest(Paddle& paddle, Ball& ball)
{
    if (!isIntersecting(paddle, ball)) return false;
    
    ball.moveUp();

    if (ball.getPosition().x < paddle.getPosition().x)
    {
        ball.moveLeft();
    }
    else if (ball.getPosition().x > paddle.getPosition().x)
    {
        ball.moveRight();
    }
}

bool collisionTest(Block& block, Ball& ball)
{
    if (!isIntersecting(block, ball)) return false;

    block.destroy();

    float overlapLeft{ ball.right() - block.left() };
    float overlapRight{ block.right() - ball.left() };
    float overlapUp{ ball.down() - block.up() };
    float overlapDown{ block.down() - ball.up() };
    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromUp(abs(overlapUp) < abs(overlapDown));
    float minOverlapX{ ballFromLeft ? overlapLeft: overlapRight };
    float minOverlapY{ ballFromUp ? overlapUp : overlapDown };

    if (abs(minOverlapX) < abs(minOverlapY))
    {
        ballFromLeft ? ball.moveLeft() : ball.moveRight();
    }
    else {
        ballFromUp ? ball.moveUp() : ball.moveDown();
    }
}

int main()
{
    Ball ball(400, 300);
    Paddle paddle(400, 550);
    sf::RenderWindow gameWindow{ sf::VideoMode{800,600},"Arkanoid" };
    gameWindow.setFramerateLimit(60);
    sf::Event event;
    unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };

    std::vector<Block> blocks;

    for (int i = 0; i < blocksY; i++)
    {
        for (int j = 0; j < blocksX; j++)
        {
            blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }
    while (true)
    {
        gameWindow.clear(sf::Color::Black);
        gameWindow.pollEvent(event);

        if (event.type == sf::Event::Closed)
        {
            gameWindow.close();
            break;
        }
        ball.update();
        paddle.update();
        collisionTest(paddle, ball);

        for (auto& block : blocks) if (collisionTest(block, ball)) break;

        auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed(); });
        blocks.erase(iterator,end(blocks));
        

        gameWindow.draw(ball);
        gameWindow.draw(paddle);

        for (auto& block : blocks)
            gameWindow.draw(block);
        gameWindow.display();
    }
}
