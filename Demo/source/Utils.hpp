#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"

sf::Vector2f ToSfVector(const Physics2D::Vector2& vec) 
{
	return sf::Vector2f(vec.X, vec.Y);
}

Physics2D::Vector2 ToEngineVector(const sf::Vector2f& vec)
{
	return Physics2D::Vector2(vec.x, vec.y);
}