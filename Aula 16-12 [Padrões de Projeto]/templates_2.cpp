#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class MathOperation
{
public:
    virtual T compute(const T &a, const T &b) const = 0;
    virtual ~MathOperation() = default;
};

template <typename T>
class Addition : public MathOperation<T>
{
public:
    T compute(const T &a, const T &b) const override
    {
        return a + b;
    }
};

template <typename T>
class Multiplication : public MathOperation<T>
{
public:
    T compute(const T &a, const T &b) const override
    {
        return a * b;
    }
};

template <typename T>
void processOperations(const std::vector<std::unique_ptr<MathOperation<T>>> &operations, const T &a, const T &b)
{
    for (const auto &op : operations)
    {
        std::cout << op->compute(a, b) << std::endl;
    }
}

int main()
{
    std::vector<std::unique_ptr<MathOperation<double>>> operations;
    operations.push_back(std::make_unique<Addition<double>>());
    operations.push_back(std::make_unique<Multiplication<double>>());

    processOperations(operations, 3.5, 2.0);
    return 0;
}
