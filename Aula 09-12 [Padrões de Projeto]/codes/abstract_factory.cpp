#include <iostream>
#include <memory>

// Permite criar famílias de objetos relacionados sem depender de suas classes concretas, promovendo flexibilidade e isolamento.

class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};

class DarkButton : public Button {
public:
    void render() override { std::cout << "Rendering Dark Button\n"; }
};

class LightButton : public Button {
public:
    void render() override { std::cout << "Rendering Light Button\n"; }
};

class UIFactory {
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual ~UIFactory() = default;
};

class DarkUIFactory : public UIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<DarkButton>();
    }
};

class LightUIFactory : public UIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<LightButton>();
    }
};

int main() {
    std::unique_ptr<UIFactory> factory;

    bool darkMode = true;
    if (darkMode) {
        factory = std::make_unique<DarkUIFactory>();
    } else {
        factory = std::make_unique<LightUIFactory>();
    }

    auto button = factory->createButton();
    button->render();

    return 0;
}