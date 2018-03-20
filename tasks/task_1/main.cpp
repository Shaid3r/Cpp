#include "HSLCircle.h"
#include "HSVCircle.h"
#include "RGBCircle.h"
#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

const int radius = 200;
const int frames = 20;

class App {
public:
    App() {
        m_circles[0] = new HSLCircle;
        m_circles[1] = new HSVCircle;
        m_circles[2] = new RGBCircle;

        for (int i = 0; i < NUMBER_OF_CIRCLES; ++i)
            m_circles[i]->setRadius(radius);
    }

    void run() {
        // Imituje czas trwania aplikacji
        for (int i = 0; i < frames; ++i) {
            // Random imituje zmiane przez użytkownika
            // int input_percent = rand();  0 < x < 1
            float input_percent = 0.5;
            for (int i = 0; i < NUMBER_OF_CIRCLES; ++i)
                m_circles[i]->update(input_percent);
        }
    }
private:
    static const int NUMBER_OF_CIRCLES = 3;
    Circle *m_circles[NUMBER_OF_CIRCLES];
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