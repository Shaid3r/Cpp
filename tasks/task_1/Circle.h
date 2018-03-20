#pragma once
#include "Utils.h"
#include <cmath>
#include "cstdlib"

class Circle {
public:
    ~Circle() {
        if (pixels) delete [] pixels;
    }

    void setRadius(float radius) {
        if (pixels) delete [] pixels;
        m_radius = radius;
        m_width = static_cast<unsigned int>(radius * 2);
        m_height = static_cast<unsigned int>(radius * 2);

        pixels = new sf::Uint8[m_width * m_height * 4];
    }

    void update(float percent) {

        for (unsigned int x = 0; x < m_width; ++x) {
            for (unsigned int y = 0; y < m_height; ++y) {
        		
        		RandomCalculations();
                
                float x2 = x - m_width / 2.0f;
                float y2 = y - m_height / 2.0f;
                float r = sqrtf(x2 * x2 + y2 * y2);

                if (r <= m_radius) {
                    double phi = std::atan2(y2, -x2) * 0.5 / M_PI + 0.5;

                    sf::Color color = calc(phi, r / m_radius, percent);

                    color_pixel(x, y, color.r, color.g, color.b);
                }
            }
        }
    }
private:

    virtual void RandomCalculations() const = 0;
    virtual sf::Color calc(float phi, float r, float percent) const = 0;

    void color_pixel(unsigned int x, unsigned int y, sf::Uint8 r, sf::Uint8 g,
                     sf::Uint8 b) {
        pixels[4 * (y * m_width + x) + 0] = r;
        pixels[4 * (y * m_width + x) + 1] = g;
        pixels[4 * (y * m_width + x) + 2] = b;
        pixels[4 * (y * m_width + x) + 3] = 255;
    }

    float m_radius;
    unsigned int m_width;
    unsigned int m_height;
    sf::Uint8 *pixels = nullptr;
};