#pragma once
#include "Circle.h"
#include <cmath>

class RGBCircle : public Circle<RGBCircle> {
public:
    sf::Color calc(float phi, float r, float percent) {
        auto red = static_cast<sf::Uint8>(r * 255);
        auto green = static_cast<sf::Uint8>(phi * 255);
        auto blue = static_cast<sf::Uint8>(percent * 255);
        return sf::Color{red, green, blue};
    }
};
