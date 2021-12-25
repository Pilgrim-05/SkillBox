#include <iostream>
#include <string>

class Toy
{
private:
    std::string name;
public:
    Toy(std::string name) : name(name) {std::cout << "Created by " << name << std::endl;};
    Toy() : Toy("someToy"){};

    std::string getName(){return name;}

    ~Toy(){std::cout << "Destroyed " << name << std::endl;}
};

class shared_ptr_toy
{
private:
    Toy* m_toy;
    int counter = 0;
public:
    shared_ptr_toy() : m_toy(nullptr){}
    shared_ptr_toy(Toy* toy)
    {
        m_toy = new Toy(*toy);
        ++counter;
    }

    shared_ptr_toy(const shared_ptr_toy& other)
    {
        m_toy = new Toy(*other.m_toy);
        ++counter;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other)
    {
        if(this == &other)
            return *this;

        if(m_toy != nullptr)
            delete m_toy;

        m_toy = new Toy(*other.m_toy);
        ++counter;
        return *this;
    }

    ~shared_ptr_toy()
    {
        if(counter > 0)
            --counter;
        if(counter == 1 && m_toy != nullptr)
        {
            delete m_toy;
        }
    };
};

int main()
{
    shared_ptr_toy ptr2;
    shared_ptr_toy ptr1(new Toy("doll"));

    {
        shared_ptr_toy ptr(new Toy("ball"));
        ptr1 = ptr;
    }

    return 0;
}
