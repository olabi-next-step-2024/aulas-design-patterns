#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};

class TextEditor
{
    std::string text;

public:
    void append(const std::string &str)
    {
        text += str;
    }
    void erase(size_t count)
    {
        if (count > text.size())
            count = text.size();
        text.erase(text.size() - count);
    }
    std::string getText() const
    {
        return text;
    }
};

class AppendCommand : public Command
{
    TextEditor &editor;
    std::string textToAdd;

public:
    AppendCommand(TextEditor &ed, const std::string &text)
        : editor(ed), textToAdd(text) {}
    void execute() override
    {
        editor.append(textToAdd);
    }
    void undo() override
    {
        editor.erase(textToAdd.size());
    }
};

class EraseCommand : public Command
{
    TextEditor &editor;
    size_t charsToRemove;
    std::string erasedText;

public:
    EraseCommand(TextEditor &ed, size_t count)
        : editor(ed), charsToRemove(count) {}
    void execute() override
    {
        erasedText = editor.getText().substr(editor.getText().size() - charsToRemove);
        editor.erase(charsToRemove);
    }
    void undo() override
    {
        editor.append(erasedText);
    }
};

class CommandInvoker
{
    std::vector<std::unique_ptr<Command>> commandHistory;
    TextEditor &editor;

public:
    CommandInvoker(TextEditor &ed) : editor(ed) {}
    void executeCommand(std::unique_ptr<Command> command)
    {
        command->execute();
        commandHistory.push_back(std::move(command));
    }
    void undo()
    {
        if (!commandHistory.empty())
        {
            commandHistory.back()->undo();
            commandHistory.pop_back();
        }
    }
};

int main()
{
    TextEditor editor;
    CommandInvoker invoker(editor);

    invoker.executeCommand(std::make_unique<AppendCommand>(editor, "Hello, "));
    invoker.executeCommand(std::make_unique<AppendCommand>(editor, "World!"));
    invoker.executeCommand(std::make_unique<EraseCommand>(editor, 6));

    std::cout << "Text after operations: " << editor.getText() << std::endl;

    invoker.undo();
    std::cout << "Text after undo: " << editor.getText() << std::endl;

    invoker.undo();
    std::cout << "Text after second undo: " << editor.getText() << std::endl;

    return 0;
}
