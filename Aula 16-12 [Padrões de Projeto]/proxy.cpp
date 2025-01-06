#include <iostream>
#include <string>
#include <unordered_map>

class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() {}
};

class RealImage : public Image
{
    std::string fileName;

public:
    RealImage(const std::string &name) : fileName(name)
    {
        loadFromDisk(fileName);
    }
    void display() override
    {
        std::cout << "Displaying " << fileName << std::endl;
    }

private:
    void loadFromDisk(const std::string &name)
    {
        std::cout << "Loading " << name << " from disk" << std::endl;
    }
};

class ProxyImage : public Image
{
    std::string fileName;
    RealImage *realImage = nullptr;

public:
    ProxyImage(const std::string &name) : fileName(name) {}
    ~ProxyImage()
    {
        delete realImage;
    }
    void display() override
    {
        if (!realImage)
        {
            realImage = new RealImage(fileName);
        }
        realImage->display();
    }
};

class ImageViewer
{
    std::unordered_map<std::string, Image *> imageCache;

public:
    ~ImageViewer()
    {
        for (auto &pair : imageCache)
        {
            delete pair.second;
        }
    }
    void viewImage(const std::string &fileName)
    {
        if (imageCache.find(fileName) == imageCache.end())
        {
            imageCache[fileName] = new ProxyImage(fileName);
        }
        imageCache[fileName]->display();
    }
};

int main()
{
    ImageViewer viewer;
    viewer.viewImage("image1.jpg");
    viewer.viewImage("image2.jpg");
    viewer.viewImage("image1.jpg");
}
