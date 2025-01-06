#include <iostream>
#include <vector>
#include <memory>

// Facilita a manipulação uniforme de objetos individuais e coleções.

class FileSystemEntity {
public:
    virtual void display(int depth = 0) = 0;
    virtual ~FileSystemEntity() = default;
};

class File : public FileSystemEntity {
private:
    std::string name;
public:
    File(const std::string& name) : name(name) {}
    void display(int depth = 0) override {
        std::cout << std::string(depth, '-') << name << std::endl;
    }
};

class Directory : public FileSystemEntity {
private:
    std::string name;
    std::vector<std::unique_ptr<FileSystemEntity>> children;
public:
    Directory(const std::string& name) : name(name) {}

    void add(std::unique_ptr<FileSystemEntity> entity) {
        children.push_back(std::move(entity));
    }

    void display(int depth = 0) override {
        std::cout << std::string(depth, '-') << name << std::endl;
        for (const auto& child : children) {
            child->display(depth + 2);
        }
    }
};

int main() {
    auto root = std::make_unique<Directory>("root");
    root->add(std::make_unique<File>("file1.txt"));
    root->add(std::make_unique<File>("file2.txt"));

    auto subDir = std::make_unique<Directory>("subdir");
    subDir->add(std::make_unique<File>("subfile1.txt"));

    root->add(std::move(subDir));
    root->display();

    return 0;
}