#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "imgui.h"

static sf::Vector2f ToSfVector(const Physics2D::Vector2& vec) 
{
	return sf::Vector2f(vec.X, vec.Y);
}

static Physics2D::Vector2 ToEngineVector(const sf::Vector2f& vec)
{
	return Physics2D::Vector2(vec.x, vec.y);
}

static sf::Color ImVec4ToSFMLColor(ImVec4 imColor)
{
    // Scale the ImVec4 color values to the range [0, 255]
    unsigned char r = static_cast<sf::Uint8>(imColor.x * 255.0f);
    unsigned char g = static_cast<sf::Uint8>(imColor.y * 255.0f);
    unsigned char b = static_cast<sf::Uint8>(imColor.z * 255.0f);
    unsigned char a = static_cast<sf::Uint8>(imColor.w * 255.0f);

    // Create and return an sf::Color object
    return sf::Color(r, g, b, 255);
}

static ImVec4 SFMLColorToImVec4(const sf::Color& sfmlColor) 
{
    // Scale the sf::Color values to the range [0.0, 1.0]
    float r = static_cast<float>(sfmlColor.r) / 255.0f;
    float g = static_cast<float>(sfmlColor.g) / 255.0f;
    float b = static_cast<float>(sfmlColor.b) / 255.0f;
    float a = static_cast<float>(sfmlColor.a) / 255.0f;

    // Create and return an ImVec4 object
    return ImVec4(r, g, b, 1.0f);
}