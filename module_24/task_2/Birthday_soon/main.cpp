#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

struct person
{
    string name;
    tm birthDate;
};

void addFriend(vector<person>&);
int reminder(vector<person>&);

int main()
{
    vector<person> friends;
    addFriend(friends);
    int index = reminder(friends);
    if(index != -1)
       cout << friends[index].name << "'s birthday is " << put_time(&friends[index].birthDate, "%m/%d") << "!" << endl;

    return 0;
}

void addFriend(vector<person> &vec)
{
    string name;
    time_t t = time(nullptr);
    cout << "Enter your friend's name: ";
    getline(cin, name);
    while(name != "end")
    {
        person tmp;
        tmp.name = name;
        tmp.birthDate = *localtime(&t);
        cout << "Friend's date of birth in format (YYYY/MM/DD): ";
        cin >> get_time(&tmp.birthDate, "%Y/%m/%d");
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        vec.push_back(tmp);
        cout << "Enter your friend's name: ";
        getline(cin, name);
    }
}

int reminder(vector<person> &vec)
{
    time_t td = time(nullptr);
    tm today = *localtime(&td);
    cout << "***** Current date: " << put_time(&today, "%Y/%m/%d") << " *****" << endl;
    size_t indexMin = -1;
    int minMon = INT_MAX, minDay = INT_MAX;
    for(size_t i = 0; i < vec.size(); ++i)
    {
        if(today.tm_mon == vec[i].birthDate.tm_mon && today.tm_mday == vec[i].birthDate.tm_mday)
        {
            cout << "do not forget to wish " << vec[i].name <<" a happy birthday!" << endl;
        }else if(today.tm_mon <= vec[i].birthDate.tm_mon)
        {
            if(minMon > vec[i].birthDate.tm_mon - today.tm_mon)
            {
                minMon = vec[i].birthDate.tm_mon - today.tm_mon;
                indexMin = i;
            }
            if(minMon == vec[i].birthDate.tm_mon - today.tm_mon && minDay > vec[i].birthDate.tm_mday - today.tm_mday)
            {
                minDay = vec[i].birthDate.tm_mday - today.tm_mday;
                indexMin = i;
            }
        }
    }

    return indexMin;
}
