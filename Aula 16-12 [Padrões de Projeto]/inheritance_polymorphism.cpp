#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Transaction
{
protected:
    std::string stockName;
    int quantity;
    double price;

public:
    Transaction(const std::string &stock, int qty, double prc)
        : stockName(stock), quantity(qty), price(prc) {}

    virtual ~Transaction() {}
    virtual void process() const = 0;
    virtual double calculateTotal() const = 0;

    const std::string &getStockName() const { return stockName; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
};

class BuyTransaction : public Transaction
{
public:
    BuyTransaction(const std::string &stock, int qty, double prc)
        : Transaction(stock, qty, prc) {}

    void process() const override
    {
        std::cout << "Buying " << quantity << " shares of " << stockName
                  << " at $" << price << " each.\n";
    }

    double calculateTotal() const override
    {
        return quantity * price;
    }
};

class SellTransaction : public Transaction
{
public:
    SellTransaction(const std::string &stock, int qty, double prc)
        : Transaction(stock, qty, prc) {}

    void process() const override
    {
        std::cout << "Selling " << quantity << " shares of " << stockName
                  << " at $" << price << " each.\n";
    }

    double calculateTotal() const override
    {
        return quantity * price;
    }
};

class Portfolio
{
    std::vector<std::unique_ptr<Transaction>> transactions;

public:
    void addTransaction(std::unique_ptr<Transaction> transaction)
    {
        transactions.push_back(std::move(transaction));
    }

    void processTransactions() const
    {
        for (const auto &transaction : transactions)
        {
            transaction->process();
            std::cout << "Total: $" << transaction->calculateTotal() << "\n\n";
        }
    }
};

int main()
{
    Portfolio portfolio;

    portfolio.addTransaction(std::make_unique<BuyTransaction>("AAPL", 50, 150.0));
    portfolio.addTransaction(std::make_unique<SellTransaction>("GOOGL", 20, 2800.0));
    portfolio.addTransaction(std::make_unique<BuyTransaction>("TSLA", 10, 750.0));

    portfolio.processTransactions();

    return 0;
}
