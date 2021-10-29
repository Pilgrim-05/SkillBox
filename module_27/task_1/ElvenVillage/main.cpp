#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Tree
{
private:
    std::string elfName;
    Tree *parent = nullptr;
    std::vector<Tree*> branchs;

    void setElfName(std::string name)
    {
      elfName = name;
    }

    std::string getElfName()
    {
      return elfName;
    }

public:
    Tree() = default;

    Tree(Tree *parent)
    {
      this->parent = parent;
    }

    int getNumBranchs()
    {
        return branchs.size();
    }

    Tree* getBranch(int i)
    {
        return branchs[i];
    }

    void treeGenerator(int begin, int finish)
    {
        srand(time(nullptr));
        int count = rand() % (finish - begin) + begin;
        branchs.resize(count);
        for(int i = 0; i < count; ++i)
        {
            Tree *tmp = new Tree(this);
            branchs[i] = tmp;
            std::string name;
            std::cout << "Enter the name of the elf: ";
            getline(std::cin, name);
            branchs[i]->setElfName(name);
        }
    }

    int neighborsFinder(const std::string& name)
    {
        int counter = 0;
        bool status = false;
        if(branchs.empty()) return -1;
        else
        {
            for(int i =0; i < branchs.size(); ++i)
            {
                if(branchs[i]->getElfName() == name) status = true;
                if(branchs[i]->getElfName() != "None"
                        && branchs[i]->getElfName() != name) ++counter;
                for(int j =0; j < branchs[i]->getNumBranchs(); ++j)
                {
                    if(branchs[i]->getBranch(j)->getElfName() == name) status = true;
                    if(branchs[i]->getBranch(j)->getElfName() != "None"
                            && branchs[i]->getBranch(j)->getElfName() != name) ++counter;
                }

                if(status) return counter;
                else counter = 0;
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<Tree*> forest(5);

    for(int k = 0; k < forest.size(); ++k)
    {
        forest[k] = new Tree(nullptr);
        forest[k]->treeGenerator(3, 5);

        for(int i = 0; i < forest[k]->getNumBranchs(); ++i)
        {
            forest[k]->getBranch(i)->treeGenerator(2, 3);
        }
    }

    std::cout << "*********************************" << std::endl;

    std::cout << "Desired elf name: ";
    std::string name;
    getline(std::cin, name);
    int result = 0;
    for(int i = 0; i < forest.size(); ++i)
    {
        result = forest[i]->neighborsFinder(name);
        if(result != -1)
        {
            std::cout << "This elf has " << result <<" neighbors " << std::endl;
            break;
        }
    }

    return 0;
}
