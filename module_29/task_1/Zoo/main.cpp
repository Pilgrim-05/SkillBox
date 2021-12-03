#include <iostream>

class Animal
{
public:
    virtual void voice() = 0;
};

class Dog : public Animal
{
public:

    virtual void voice()
    {
        std::cout << "Bark ";
    }
};

class Cat : public Animal
{
public:
    virtual void voice()
    {
        std::cout << "Meow ";
    }
};

void meeting(Animal* a, Animal* b);

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    meeting(dog, dog);
    meeting(dog, cat);
    meeting(cat, dog);
    meeting(cat, cat);

    return 0;
}

void meeting(Animal* a, Animal* b)
{
    a->voice();
    b->voice();
    std::cout << std::endl;
}


