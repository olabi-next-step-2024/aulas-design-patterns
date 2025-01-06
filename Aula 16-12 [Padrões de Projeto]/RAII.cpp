#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>


class LogFile {
    std::ofstream file;
public:
    LogFile(const std::string& filename) {
        file.open(filename, std::ios::out | std::ios::app);
        if (!file) throw std::runtime_error("Failed to open log file");
        std::cout << "Log file opened: " << filename << "\n";
    }
    ~LogFile() {
        if (file.is_open()) {
            file.close();
            std::cout << "Log file closed.\n";
        }
    }
    void write(const std::string& message) {
        if (file.is_open()) {
            file << message << std::endl;
        } else {
            throw std::runtime_error("File is not open");
        }
    }
};

class DataBuffer {
    std::unique_ptr<int[]> buffer;
    size_t size;
public:
    DataBuffer(size_t sz) : size(sz), buffer(std::make_unique<int[]>(sz)) {
        std::cout << "Buffer of size " << size << " allocated.\n";
    }
    ~DataBuffer() {
        std::cout << "Buffer of size " << size << " released.\n";
    }
    int& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return buffer[index];
    }
    size_t getSize() const { return size; }
};

class DatabaseConnection {
    std::string dbName;
    bool connected;
public:
    DatabaseConnection(const std::string& db) : dbName(db), connected(false) {
        connect();
    }
    ~DatabaseConnection() {
        disconnect();
    }
    void connect() {
        if (!connected) {
            std::cout << "Connected to database: " << dbName << "\n";
            connected = true;
        }
    }
    void disconnect() {
        if (connected) {
            std::cout << "Disconnected from database: " << dbName << "\n";
            connected = false;
        }
    }
    void query(const std::string& sql) {
        if (!connected) throw std::runtime_error("Not connected to database");
        std::cout << "Executing query: " << sql << "\n";
    }
};

int main() {
    try {
        // Log file
        LogFile log("logfile.txt");
        log.write("Application started.");

        // Data buffer
        DataBuffer buffer(10);
        for (size_t i = 0; i < buffer.getSize(); ++i) {
            buffer[i] = static_cast<int>(i * 2);
        }
        log.write("Buffer initialized.");

        // Database connection
        DatabaseConnection db("MyDatabase");
        db.query("SELECT * FROM users");
        log.write("Database query executed.");

        log.write("Application finished successfully.");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
