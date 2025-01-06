#include <iostream>
#include <vector>
#include <string>

class Memento
{
    std::string state;

public:
    Memento(const std::string &s) : state(s) {}
    std::string getState() const { return state; }
};

class Editor
{
    std::string content;

public:
    void write(const std::string &text)
    {
        content += text;
    }
    Memento save() const
    {
        return Memento(content);
    }
    void restore(const Memento &memento)
    {
        content = memento.getState();
    }
    void display() const
    {
        std::cout << "Content: " << content << std::endl;
    }
};

class History
{
    std::vector<Memento> snapshots;

public:
    void save(const Memento &memento)
    {
        snapshots.push_back(memento);
    }
    Memento undo()
    {
        if (snapshots.empty())
        {
            throw std::runtime_error("No snapshots to undo.");
        }
        Memento last = snapshots.back();
        snapshots.pop_back();
        return last;
    }
};

int main()
{
    Editor editor;
    History history;

    editor.write("Hello, ");
    history.save(editor.save());

    editor.write("world!");
    history.save(editor.save());

    editor.display();

    editor.restore(history.undo());
    editor.display();

    editor.restore(history.undo());
    editor.display();

    return 0;
}
