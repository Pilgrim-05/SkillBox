#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

using namespace std;

int main() {
  std::cout << "Enter the day of the week: ";
  int day;
  cin >> day;
  if(day == MONDAY)
  {
    cout << "MONDAY" << endl;
  }else if(day == TUESDAY)
  {
    cout << "TUESDAY" << endl;
  }else if(day == WEDNESDAY)
  {
    cout << "WEDNESDAY" << endl;
  }else if(day == THURSDAY)
  {
    cout << "THURSDAY" << endl;
  }else if(day == FRIDAY)
  {
    cout << "FRIDAY" << endl;
  }else if(day == SATURDAY)
  {
    cout << "SATURDAY" << endl;
  }else if(day == SUNDAY)
  {
    cout << "SUNDAY" << endl;
  }else {
    cout << "wrong weekday number!" << endl;
  }
}
