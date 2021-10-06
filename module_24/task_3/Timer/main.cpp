#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    cout << "***Setting timer***" << endl << endl;
    time_t minutes, seconds;

    do
    {
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }while(minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59);

    time_t t_set = time(nullptr);
    t_set += minutes * 60 +seconds;

    time_t t_current = time(nullptr);
    cout << put_time(localtime(&t_current), "%M:%S") << endl;

    while(t_set != t_current){
        t_current = time(nullptr);
    }

    cout << "***DING! DING! DING!***" << endl << put_time(localtime(&t_current), "%M:%S") << endl;

    return 0;
}
