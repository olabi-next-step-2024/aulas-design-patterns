#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class Event
{
public:
    virtual void execute() = 0;
    virtual ~Event() {}
};

class PrintEvent : public Event
{
    std::string message;

public:
    PrintEvent(const std::string &msg) : message(msg) {}
    void execute() override
    {
        std::cout << message << std::endl;
    }
};

class MathEvent : public Event
{
    int a, b;

public:
    MathEvent(int x, int y) : a(x), b(y) {}
    void execute() override
    {
        std::cout << "Sum: " << (a + b) << std::endl;
    }
};

class EventQueue
{
    std::queue<Event *> events;
    std::mutex mtx;
    std::condition_variable cv;
    bool running;

    void process()
    {
        while (running)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]()
                    { return !events.empty() || !running; });
            if (!running && events.empty())
                return;
            Event *event = events.front();
            events.pop();
            lock.unlock();
            event->execute();
            delete event;
        }
    }

public:
    EventQueue() : running(true)
    {
        std::thread([this]()
                    { process(); })
            .detach();
    }

    ~EventQueue()
    {
        stop();
    }

    void addEvent(Event *event)
    {
        std::lock_guard<std::mutex> lock(mtx);
        events.push(event);
        cv.notify_one();
    }

    void stop()
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            running = false;
        }
        cv.notify_all();
    }
};

int main()
{
    EventQueue queue;

    queue.addEvent(new PrintEvent("Hello, World!"));
    queue.addEvent(new MathEvent(3, 7));
    queue.addEvent(new PrintEvent("Another Event"));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    queue.stop();
}
