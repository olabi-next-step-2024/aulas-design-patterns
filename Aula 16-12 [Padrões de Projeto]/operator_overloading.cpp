#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Stock
{
    std::string ticker;
    int quantity;
    double pricePerShare;

public:
    Stock(const std::string &t, int q, double p) : ticker(t), quantity(q), pricePerShare(p) {}

    double totalValue() const
    {
        return quantity * pricePerShare;
    }

    Stock &operator+=(const Stock &other)
    {
        if (ticker != other.ticker)
        {
            throw std::invalid_argument("Cannot combine different stocks");
        }
        quantity += other.quantity;
        pricePerShare = (pricePerShare + other.pricePerShare) / 2;
        return *this;
    }

    Stock &operator-=(int qty)
    {
        if (qty > quantity)
        {
            throw std::invalid_argument("Not enough shares to sell");
        }
        quantity -= qty;
        return *this;
    }

    bool operator==(const Stock &other) const
    {
        return ticker == other.ticker;
    }

    friend std::ostream &operator<<(std::ostream &os, const Stock &stock)
    {
        os << "Ticker: " << stock.ticker << ", Quantity: " << stock.quantity
           << ", Price/Share: $" << stock.pricePerShare;
        return os;
    }
};

class Portfolio
{
    std::vector<Stock> stocks;

public:
    void buy(const Stock &stock)
    {
        for (auto &s : stocks)
        {
            if (s == stock)
            {
                s += stock;
                return;
            }
        }
        stocks.push_back(stock);
    }

    void sell(const std::string &ticker, int quantity)
    {
        for (auto &s : stocks)
        {
            if (s == Stock(ticker, 0, 0))
            {
                s -= quantity;
                if (s.totalValue() == 0)
                {
                    stocks.erase(std::remove(stocks.begin(), stocks.end(), s), stocks.end());
                }
                return;
            }
        }
        throw std::invalid_argument("Stock not found in portfolio");
    }

    double totalValue() const
    {
        double total = 0;
        for (const auto &s : stocks)
        {
            total += s.totalValue();
        }
        return total;
    }

    friend std::ostream &operator<<(std::ostream &os, const Portfolio &portfolio)
    {
        for (const auto &s : portfolio.stocks)
        {
            os << s << std::endl;
        }
        return os;
    }
};

int main()
{
    Portfolio portfolio;
    portfolio.buy(Stock("AAPL", 10, 150.0));
    portfolio.buy(Stock("GOOG", 5, 2800.0));
    portfolio.buy(Stock("AAPL", 5, 155.0));

    std::cout << "Portfolio after purchases:" << std::endl;
    std::cout << portfolio;

    portfolio.sell("AAPL", 5);

    std::cout << "Portfolio after selling 5 AAPL shares:" << std::endl;
    std::cout << portfolio;

    std::cout << "Total Portfolio Value: $" << portfolio.totalValue() << std::endl;

    return 0;
}
