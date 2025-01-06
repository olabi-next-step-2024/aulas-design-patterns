#include <iostream>

// Permite que classes incompatíveis colaborem ao traduzir suas interfaces.

class USPlug {
public:
    virtual void connect() = 0;
};

class USPlugImpl : public USPlug {
public:
    void connect() override { std::cout << "US Plug connected\n"; }
};

class EUPlug {
public:
    void connectToEU() { std::cout << "EU Plug connected\n"; }
};

class PlugAdapter : public USPlug {
private:
    EUPlug* euPlug;
public:
    PlugAdapter(EUPlug* plug) : euPlug(plug) {}
    void connect() override { euPlug->connectToEU(); }
};

int main() {
    EUPlug euPlug;
    PlugAdapter adapter(&euPlug);

    adapter.connect();

    return 0;
}