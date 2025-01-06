#include <iostream>
#include <string>
#include <memory>
#include <vector>

class PaymentStrategy
{
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CreditCardPayment : public PaymentStrategy
{
    std::string name;
    std::string cardNumber;
    std::string cvv;
    std::string expiryDate;

public:
    CreditCardPayment(const std::string &name, const std::string &cardNumber,
                      const std::string &cvv, const std::string &expiryDate)
        : name(name), cardNumber(cardNumber), cvv(cvv), expiryDate(expiryDate) {}
    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using Credit Card: " << cardNumber << std::endl;
    }
};

class PayPalPayment : public PaymentStrategy
{
    std::string email;
    std::string password;

public:
    PayPalPayment(const std::string &email, const std::string &password)
        : email(email), password(password) {}
    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using PayPal: " << email << std::endl;
    }
};

class BitcoinPayment : public PaymentStrategy
{
    std::string walletAddress;

public:
    BitcoinPayment(const std::string &walletAddress)
        : walletAddress(walletAddress) {}
    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using Bitcoin wallet: " << walletAddress << std::endl;
    }
};

class ShoppingCart
{
    std::vector<std::pair<std::string, int>> items;
    std::unique_ptr<PaymentStrategy> paymentMethod;

public:
    void addItem(const std::string &name, int price)
    {
        items.emplace_back(name, price);
    }
    void setPaymentMethod(std::unique_ptr<PaymentStrategy> strategy)
    {
        paymentMethod = std::move(strategy);
    }
    void checkout()
    {
        int total = 0;
        for (const auto &item : items)
        {
            total += item.second;
            std::cout << "Item: " << item.first << ", Price: " << item.second << std::endl;
        }
        std::cout << "Total: " << total << std::endl;
        if (paymentMethod)
        {
            paymentMethod->pay(total);
        }
        else
        {
            std::cout << "No payment method set." << std::endl;
        }
    }
};

int main()
{
    ShoppingCart cart;
    cart.addItem("Book", 50);
    cart.addItem("Pen", 5);

    cart.setPaymentMethod(std::make_unique<CreditCardPayment>(
        "John Doe", "1234-5678-9101-1121", "123", "12/25"));
    cart.checkout();

    cart.setPaymentMethod(std::make_unique<PayPalPayment>(
        "john.doe@example.com", "securepassword"));
    cart.checkout();

    cart.setPaymentMethod(std::make_unique<BitcoinPayment>(
        "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa"));
    cart.checkout();

    return 0;
}
