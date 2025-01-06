#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

class Pipeline
{
    std::vector<std::function<std::vector<int>(const std::vector<int> &)>> stages;

public:
    void addStage(std::function<std::vector<int>(const std::vector<int> &)> stage)
    {
        stages.push_back(stage);
    }

    std::vector<int> execute(const std::vector<int> &input) const
    {
        std::vector<int> result = input;
        for (const auto &stage : stages)
        {
            result = stage(result);
        }
        return result;
    }
};

int main()
{
    Pipeline pipeline;

    pipeline.addStage([](const std::vector<int> &data)
                      {
        std::vector<int> filtered;
        for (int x : data) {
            if (x % 2 == 0) filtered.push_back(x);
        }
        return filtered; });

    pipeline.addStage([](const std::vector<int> &data)
                      {
        std::vector<int> doubled;
        for (int x : data) {
            doubled.push_back(x * 2);
        }
        return doubled; });

    pipeline.addStage([](const std::vector<int> &data)
                      {
        std::vector<int> result;
        int sum = std::accumulate(data.begin(), data.end(), 0);
        result.push_back(sum);
        return result; });

    std::vector<int> input = {1, 2, 3, 4, 5, 6};
    std::vector<int> output = pipeline.execute(input);

    for (int x : output)
    {
        std::cout << x << " ";
    }

    return 0;
}
