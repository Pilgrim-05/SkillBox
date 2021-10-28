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

public:
    Tree() = default;

    Tree(Tree *parent)
    {
      this->parent = parent;
    }

    std::string getElfName()
    {
      return elfName;
    }

    Tree* getParent()
    {
      return parent;
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
};

int neighborsFinder(Tree * tree, std::string name);
Tree* nullParent(Tree* p);

int main()
{
    std::vector<Tree*> forest(1);

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

    std::cout << "Desired elf name : ";
    std::string name;
    getline(std::cin, name);
    int result = 0;
    for(int i = 0; i < forest.size(); ++i)
    {
        result = neighborsFinder(forest[i], name);
        if(result != -1) break;
    }

    if(result != -1)
    {
        std::cout << "This elf has " << result <<" neighbors " << std::endl;
    }

    return 0;
}

int neighborsFinder(Tree * tree, std::string name)
{
    if(name == "None") return -1;
    int counter = 0;
    for(int i = 0; i < tree->getNumBranchs(); ++i)
    {
        if(tree->getBranch(i)->getElfName() == name)
        {
            for (int j = 0; j < tree->getBranch(i)->getNumBranchs(); ++j)
            {
                if(tree->getBranch(i)->getBranch(j)->getElfName() != "None") ++counter;
            }
            return counter;
        }else
        {
            Tree *tmp;
            for (int j = 0; j < tree->getBranch(i)->getNumBranchs(); ++j)
            {
                if(tree->getBranch(i)->getBranch(j)->getElfName() == name)
                {
                    tmp = nullParent(tree->getBranch(i)->getBranch(j));
                    if(tmp->getElfName() != "None") ++counter;
                    for(int k = 0; k < tmp->getNumBranchs(); ++k)
                    {
                        if(tmp->getBranch(k)->getElfName() != "None" && tmp->getBranch(k)->getElfName() != name)
                            ++counter;
                    }
                    return counter;
                }
            }
        }
    }

    return -1;
}

Tree* nullParent(Tree* p)
{
    if(p->getParent()->getParent() == nullptr) return p;
    return nullParent(p->getParent());
}
