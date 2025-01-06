#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

class Shape {
public:
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }
    void draw() const override {
        std::cout << "Circle with radius " << radius << "\n";
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }
    void draw() const override {
        std::cout << "Rectangle with width " << width << " and height " << height << "\n";
    }
};

class PrototypeFactory {
    std::unordered_map<std::string, std::unique_ptr<Shape>> prototypes;
public:
    void addPrototype(const std::string& key, std::unique_ptr<Shape> prototype) {
        prototypes[key] = std::move(prototype);
    }
    std::unique_ptr<Shape> create(const std::string& key) const {
        if (prototypes.find(key) == prototypes.end()) throw std::invalid_argument("Prototype not found");
        return prototypes.at(key)->clone();
    }
};

int main() {
    PrototypeFactory factory;
    factory.addPrototype("circle", std::make_unique<Circle>(5.0));
    factory.addPrototype("rectangle", std::make_unique<Rectangle>(3.0, 6.0));
    
    auto shape1 = factory.create("circle");
    shape1->draw();

    auto shape2 = factory.create("rectangle");
    shape2->draw();
}
