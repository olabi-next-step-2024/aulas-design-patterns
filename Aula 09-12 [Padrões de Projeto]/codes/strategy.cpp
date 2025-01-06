#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

// Permite alternar entre diferentes algoritmos em tempo de execução.

class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
};

class AscendingSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::sort(data.begin(), data.end());
    }
};

class DescendingSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::sort(data.begin(), data.end(), std::greater<int>());
    }
};


int main() {
    std::vector<int> numbers = {5, 3, 8, 1, 9};

    std::unique_ptr<SortStrategy> strategy = std::make_unique<AscendingSort>();
    strategy->sort(numbers);

    std::cout << "Ascending: ";
    for (int name : numbers) std::cout << name << " ";
    std::cout << std::endl;

    strategy = std::make_unique<DescendingSort>();
    strategy->sort(numbers);

    std::cout << "Descending: ";
    for (int name : numbers) std::cout << name << " ";
    std::cout << std::endl;

    return 0;
}