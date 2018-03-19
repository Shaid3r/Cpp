#include <iostream>

// class Shape {
// public:
//     virtual void draw() = 0;
// };

// class Circle : public Shape {
// public:
//     void draw() {
//         std::cout << "Circle" << std::endl;
//     }
// };

// class Triangle : public Shape {
// public:
//     void draw() {
//         std::cout << "Triangle" << std::endl;
//     }
// };

// Curiously recurring template pattern
template<typename Derived>
class Shape {
public:
    // methods within Shape can use template to access members of Derived
    void draw() {
        static_cast<Derived *>(this)->draw();
    }
};

class Circle : public Shape<Circle> {
public:
    void draw() {
        std::cout << "Circle" << std::endl;
    }
};

class Triangle : public Shape<Triangle> {
public:
    void draw() {
        std::cout << "Triangle" << std::endl;
    }
};

int main() {
    Circle c; c.draw();
    Triangle t; t.draw();    
    Shape<Circle> staticCircle;
    staticCircle.draw();
    Shape<Triangle> staticTriangle;
    staticTriangle.draw();

    // Shape<null>* shape = &staticCircle; // Nie da się, bo nie mają wspólnej klasy bazowej
    // shape = &staticTriangle;
}