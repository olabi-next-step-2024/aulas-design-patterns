#include <iostream>
#include <vector>
#include <memory>
#include <string>

class FileSystemEntity
{
public:
    virtual void display(int indent = 0) const = 0;
    virtual ~FileSystemEntity() {}
};

class File : public FileSystemEntity
{
    std::string name;

public:
    File(const std::string &name) : name(name) {}
    void display(int indent = 0) const override
    {
        for (int i = 0; i < indent; ++i)
            std::cout << "  ";
        std::cout << "- " << name << "\n";
    }
};

class Folder : public FileSystemEntity
{
    std::string name;
    std::vector<std::shared_ptr<FileSystemEntity>> contents;

public:
    Folder(const std::string &name) : name(name) {}
    void add(const std::shared_ptr<FileSystemEntity> &entity)
    {
        contents.push_back(entity);
    }
    void display(int indent = 0) const override
    {
        for (int i = 0; i < indent; ++i)
            std::cout << "  ";
        std::cout << "+ " << name << "\n";
        for (const auto &entity : contents)
        {
            entity->display(indent + 1);
        }
    }
};

int main()
{
    auto root = std::make_shared<Folder>("root");
    auto folder1 = std::make_shared<Folder>("folder1");
    auto folder2 = std::make_shared<Folder>("folder2");

    auto file1 = std::make_shared<File>("file1.txt");
    auto file2 = std::make_shared<File>("file2.txt");
    auto file3 = std::make_shared<File>("file3.txt");

    folder1->add(file1);
    folder1->add(file2);

    folder2->add(file3);

    root->add(folder1);
    root->add(folder2);

    root->display();
}
