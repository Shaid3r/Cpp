#include "HSLCircle.h"
#include "HSVCircle.h"
#include "RGBCircle.h"
#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

const int radius = 200;
const int frames = 500;

class App {
public:
    App() {
        m_hslcircle.setRadius(radius);
        m_hsvcircle.setRadius(radius);
        m_rgbcircle.setRadius(radius);
    }

    void run() {
        // Imituje czas trwania aplikacji
        for (int i = 0; i < frames; ++i) {
            // Random imituje zmiane przez użytkownika
            // int input_percent = rand();  0 < x < 1
            float input_percent = 0.5;
            m_hslcircle.update(input_percent);
            m_hsvcircle.update(input_percent);
            m_rgbcircle.update(input_percent);
        }
    }
private:
    Circle<HSLCircle> m_hslcircle;
    Circle<HSVCircle> m_hsvcircle;
    Circle<RGBCircle> m_rgbcircle;
};

int main() {
    App app;
    auto start = Clock::now();
    app.run();
    auto end = Clock::now();

    std::cout << "Time taken: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
        .count() << " milliseconds" << std::endl;
}