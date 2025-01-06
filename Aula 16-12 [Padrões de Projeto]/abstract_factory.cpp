#include <iostream>
#include <memory>
#include <string>

class Document {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual ~Document() {}
};

class WordDocument : public Document {
public:
    void open() override {
        std::cout << "Opening Word document...\n";
    }
    void close() override {
        std::cout << "Closing Word document...\n";
    }
};

class PDFDocument : public Document {
public:
    void open() override {
        std::cout << "Opening PDF document...\n";
    }
    void close() override {
        std::cout << "Closing PDF document...\n";
    }
};

class DocumentFactory {
public:
    virtual std::unique_ptr<Document> createDocument() = 0;
    virtual ~DocumentFactory() {}
};

class WordFactory : public DocumentFactory {
public:
    std::unique_ptr<Document> createDocument() override {
        return std::make_unique<WordDocument>();
    }
};

class PDFFactory : public DocumentFactory {
public:
    std::unique_ptr<Document> createDocument() override {
        return std::make_unique<PDFDocument>();
    }
};

class Application {
    std::unique_ptr<DocumentFactory> factory;
public:
    Application(std::unique_ptr<DocumentFactory> factory) : factory(std::move(factory)) {}

    void run() {
        auto doc = factory->createDocument();
        doc->open();
        doc->close();
    }
};

int main() {
    {
        std::unique_ptr<DocumentFactory> wordFactory = std::make_unique<WordFactory>();
        Application wordApp(std::move(wordFactory));
        wordApp.run();
    }
    {
        std::unique_ptr<DocumentFactory> pdfFactory = std::make_unique<PDFFactory>();
        Application pdfApp(std::move(pdfFactory));
        pdfApp.run();
    }
}
