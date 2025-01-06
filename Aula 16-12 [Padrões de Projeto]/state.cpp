#include <iostream>
#include <string>


class State {
public:
    virtual void insertCard() = 0;
    virtual void enterPin(int pin) = 0;
    virtual void withdrawCash(int amount) = 0;
    virtual ~State() {}
};

class ATMContext {
    State* currentState;
    bool correctPinEntered = false;

public:
    ATMContext(State* state) : currentState(state) {}
    void setState(State* state) { currentState = state; }
    void setCorrectPin(bool isCorrect) { correctPinEntered = isCorrect; }
    bool isCorrectPin() const { return correctPinEntered; }

    void insertCard() { currentState->insertCard(); }
    void enterPin(int pin) { currentState->enterPin(pin); }
    void withdrawCash(int amount) { currentState->withdrawCash(amount); }
};


class NoCardState : public State {
    ATMContext* atm;
public:
    NoCardState(ATMContext* atmContext) : atm(atmContext) {}
    void insertCard() override {
        std::cout << "Card inserted. Please enter your PIN.\n";
        atm->setState(new HasCardState(atm));
    }
    void enterPin(int) override { std::cout << "Insert a card first.\n"; }
    void withdrawCash(int) override { std::cout << "Insert a card first.\n"; }
};

class HasCardState : public State {
    ATMContext* atm;
public:
    HasCardState(ATMContext* atmContext) : atm(atmContext) {}
    void insertCard() override { std::cout << "Card already inserted.\n"; }
    void enterPin(int pin) override {
        if (pin == 1234) {
            std::cout << "Correct PIN. You can withdraw cash now.\n";
            atm->setCorrectPin(true);
            atm->setState(new HasCorrectPinState(atm));
        } else {
            std::cout << "Incorrect PIN. Try again.\n";
        }
    }
    void withdrawCash(int) override { std::cout << "Enter PIN first.\n"; }
};

class HasCorrectPinState : public State {
    ATMContext* atm;
public:
    HasCorrectPinState(ATMContext* atmContext) : atm(atmContext) {}
    void insertCard() override { std::cout << "Card already inserted.\n"; }
    void enterPin(int) override { std::cout << "PIN already entered.\n"; }
    void withdrawCash(int amount) override {
        if (amount <= 1000) {
            std::cout << "Dispensing $" << amount << ". Please take your cash.\n";
            atm->setState(new NoCardState(atm));
        } else {
            std::cout << "Insufficient balance in ATM.\n";
        }
    }
};

int main() {
    ATMContext atm(new NoCardState(nullptr));
    atm.insertCard();
    atm.enterPin(1234);
    atm.withdrawCash(500);
    atm.withdrawCash(600);
}
