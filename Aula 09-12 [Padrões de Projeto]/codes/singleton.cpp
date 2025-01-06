#include <iostream>
#include <mutex>

// Garante que apenas uma instância de uma classe exista e fornece acesso global controlado a ela.
// Resource Acquire is Initialization (RAII)

class Logger {
private:
    static Logger* instance;
    static std::mutex mtx;

    Logger() {}

public:
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};


Logger* Logger::instance = nullptr;
std::mutex Logger::mtx;

int main() {
    Logger* logger = Logger::getInstance();
    logger->log("Singleton pattern in action!");

    return 0;
}