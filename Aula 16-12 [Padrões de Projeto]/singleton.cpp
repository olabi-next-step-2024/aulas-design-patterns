#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <vector>

class Logger {
private:
    static Logger* instance;
    static std::mutex instanceMutex;
    std::vector<std::string> logs;

    Logger() {}

public:
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(instanceMutex);
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(instanceMutex);
        logs.push_back(message);
    }

    void printLogs() {
        std::lock_guard<std::mutex> lock(instanceMutex);
        for (const auto& log : logs) {
            std::cout << log << std::endl;
        }
    }
};

Logger* Logger::instance = nullptr;
std::mutex Logger::instanceMutex;

void logMessages(const std::string& threadName, int count) {
    Logger* logger = Logger::getInstance();
    for (int i = 0; i < count; ++i) {
        logger->log(threadName + " message " + std::to_string(i + 1));
    }
}

int main() {
    std::thread t1(logMessages, "Thread1", 5);
    std::thread t2(logMessages, "Thread2", 5);

    t1.join();
    t2.join();

    Logger::getInstance()->printLogs();
}
