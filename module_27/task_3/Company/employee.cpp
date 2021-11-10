#include "employee.h"
#include <cstdlib>
#include <ctime>

Employee::Employee()
{}
//**************************************

Worker::Worker()
{
    busy = false;
}

bool Worker::isBusy()
{
    return busy;
}

void Worker::setWork(const Work &work)
{
    this->work = work;
    busy = true;
}
//**************************************

Manager::Manager()
{}

void Manager::setId(int id)
{
    this->id = id;
}

void Manager::setWorkers(int num)
{
    workers.resize(num);
}

int Manager::getWorkersNum()
{
    return workers.size();
}

void Manager::setTask(int task)
{
    int counter = 0;
    std::srand(task + id);
    for(auto &w : workers)
    {
        if(!w.isBusy()) ++counter;
    }
    if(counter) {orders = rand() % counter + 1;}
    else {orders = 0;}

    for(int index = 0; index < workers.size() && orders; ++index)
    {       
       if(!workers[index].isBusy())
       {
           std::srand(time(nullptr));
           int workType = rand() % 3;
           switch (workType)
           {
           case 0:
               workers[index].setWork(Work::A);
               break;
           case 1:
               workers[index].setWork(Work::B);
               break;
           case 2:
               workers[index].setWork(Work::C);
               break;
            }
           --orders;
       }
    }
}

bool Manager::isBusy()
{
    for(auto &w: workers)
    {
        if(!w.isBusy()) return false;
    }
    return true;
}
//**************************************

Director::Director(){}

void Director::setManagersNum(int num)
{
    managers.resize(num);
    for(int i = 0; i < num; ++i)
    {
        managers[i].setId(i);
    }
}

void Director::setManager(int index, const Manager &manager)
{
    managers[index] = manager;
}

int Director::getManagersNum()
{
    return managers.size();
}

void Director::setOrder(int order)
{
    for(auto &m : managers)
    {
        m.setTask(order);
    }
}

bool Director::isBusy()
{
    for(auto &m: managers)
    {
        if(!m.isBusy()) return false;
    }
    return true;
}
