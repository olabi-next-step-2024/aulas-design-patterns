#include <iostream>
#include <memory>

class Renderer
{
public:
    virtual void renderCircle(double x, double y, double radius) = 0;
    virtual void renderRectangle(double x, double y, double width, double height) = 0;
    virtual ~Renderer() {}
};

class SVGRenderer : public Renderer
{
public:
    void renderCircle(double x, double y, double radius) override
    {
        std::cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << radius << "\" />\n";
    }
    void renderRectangle(double x, double y, double width, double height) override
    {
        std::cout << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" />\n";
    }
};

class ConsoleRenderer : public Renderer
{
public:
    void renderCircle(double x, double y, double radius) override
    {
        std::cout << "Console: Circle at (" << x << ", " << y << ") with radius " << radius << "\n";
    }
    void renderRectangle(double x, double y, double width, double height) override
    {
        std::cout << "Console: Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
};

class Shape
{
protected:
    std::shared_ptr<Renderer> renderer;

public:
    Shape(std::shared_ptr<Renderer> r) : renderer(r) {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
    double x, y, radius;

public:
    Circle(std::shared_ptr<Renderer> r, double x, double y, double radius)
        : Shape(r), x(x), y(y), radius(radius) {}
    void draw() override
    {
        renderer->renderCircle(x, y, radius);
    }
};

class Rectangle : public Shape
{
    double x, y, width, height;

public:
    Rectangle(std::shared_ptr<Renderer> r, double x, double y, double width, double height)
        : Shape(r), x(x), y(y), width(width), height(height) {}
    void draw() override
    {
        renderer->renderRectangle(x, y, width, height);
    }
};

int main()
{
    auto svgRenderer = std::make_shared<SVGRenderer>();
    auto consoleRenderer = std::make_shared<ConsoleRenderer>();

    Circle circle(svgRenderer, 10, 20, 15);
    Rectangle rectangle(consoleRenderer, 5, 5, 40, 30);

    circle.draw();
    rectangle.draw();

    Circle consoleCircle(consoleRenderer, 0, 0, 5);
    consoleCircle.draw();
}
