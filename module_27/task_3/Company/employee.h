#pragma once
#include <iostream>
#include <vector>


enum class Work
{
    A,
    B,
    C
};


class Employee
{
public:
    Employee();
};


//******************************************

class Worker : public Employee
{
private:
    bool busy = false;
    Work work;

public:
    Worker();

    bool isBusy();
    void setWork(const Work &work);

};


//******************************************

class Manager : public Employee
{
private:
    std::vector<Worker> workers;
    int id;
    int orders = 0;
public:
    Manager();
    void setId(int id);
    void setWorkers(int num);
    int getWorkersNum();
    void setTask(int);
    bool isBusy();
};


//******************************************

class Director : public Employee
{
private:
    std::vector<Manager> managers;
public:
    Director();
    void setManagersNum(int num);
    void setManager(int, const Manager&);
    int getManagersNum();
    void setOrder(int order);
    bool isBusy();
};
