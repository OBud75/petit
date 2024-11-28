#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape {
    public:
        virtual float get_area() { return 0; }; // Virtual function for dynamic polymorphism
};

class Rectangle : public Shape {
    float length;
    float height;

    public:
        Rectangle(float length, float height) : length(length), height(height) {}

        float get_area() override {
            return length * height; // Proper area calculation for rectangle
        }
};

class Circle : public Shape {
    float rayon;

    public:
        Circle(float rayon) : rayon(rayon) {}

        float get_area() override {
            return (M_PI * rayon * rayon); // Area of the circle
        }
};

float get_area(Shape* shape) {
    return shape->get_area(); // Calling the appropriate get_area() method
}

int main() {
    Rectangle rect(2, 4);
    Shape* rect_as_shape = &rect; // Shape pointer to a Rectangle object
    printf("%f\n", get_area(rect_as_shape)); // Correctly passing Shape pointer
    
    Circle circ(3);
    Shape* circ_as_shape = &circ; // Shape pointer to a Circle object
    printf("%f\n", get_area(circ_as_shape)); // Correctly passing Shape pointer

    return 0;
}
