#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>

class Resource
{
    std::string name;

public:
    Resource(const std::string &name) : name(name)
    {
        std::cout << "Resource [" << name << "] created.\n";
    }
    ~Resource()
    {
        std::cout << "Resource [" << name << "] destroyed.\n";
    }
    std::string getName() const { return name; }
};

class Task
{
    std::string taskName;
    std::vector<std::shared_ptr<Resource>> resources;

public:
    Task(const std::string &name) : taskName(name)
    {
        std::cout << "Task [" << taskName << "] created.\n";
    }
    ~Task()
    {
        std::cout << "Task [" << taskName << "] destroyed.\n";
    }

    void addResource(const std::shared_ptr<Resource> &resource)
    {
        resources.push_back(resource);
        std::cout << "Task [" << taskName << "] added resource: "
                  << resource->getName() << "\n";
    }

    void execute()
    {
        std::cout << "Executing Task [" << taskName << "]...\n";
        for (const auto &resource : resources)
        {
            std::cout << "  Using Resource: " << resource->getName() << "\n";
        }
        std::cout << "Task [" << taskName << "] completed.\n";
    }
};

class TaskManager
{
    std::map<std::string, std::shared_ptr<Resource>> resourcePool;
    std::vector<std::unique_ptr<Task>> tasks;

public:
    std::shared_ptr<Resource> acquireResource(const std::string &name)
    {
        if (resourcePool.find(name) == resourcePool.end())
        {
            resourcePool[name] = std::make_shared<Resource>(name);
        }
        return resourcePool[name];
    }

    void addTask(std::unique_ptr<Task> task)
    {
        tasks.push_back(std::move(task));
    }

    void executeAll()
    {
        for (const auto &task : tasks)
        {
            task->execute();
        }
    }
};

int main()
{
    TaskManager manager;

    auto resourceA = manager.acquireResource("Database Connection");
    auto resourceB = manager.acquireResource("File System Access");
    auto resourceC = manager.acquireResource("Network Connection");

    auto task1 = std::make_unique<Task>("Task 1");
    task1->addResource(resourceA);
    task1->addResource(resourceB);

    auto task2 = std::make_unique<Task>("Task 2");
    task2->addResource(resourceB);
    task2->addResource(resourceC);

    auto task3 = std::make_unique<Task>("Task 3");
    task3->addResource(resourceA);
    task3->addResource(resourceC);

    manager.addTask(std::move(task1));
    manager.addTask(std::move(task2));
    manager.addTask(std::move(task3));

    manager.executeAll();

    return 0;
}
