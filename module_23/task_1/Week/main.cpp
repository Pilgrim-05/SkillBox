#include <iostream>

#define MACR(s) (((s) == 1) ?  "MONDAY" : (((s) == 2) ?  "TUESDAY" : (((s) == 3) ?  "WEDNESDAY" : (((s) == 4) ?  \
"THURSDAY" : (((s) == 5) ?  "FRIDAY" : (((s) == 6) ?  "SATURDAY" : (((s) == 7) ?  "SUNDAY" : ("ERROR"))))))))

using std::cin;
using std::cout;

int main() {
  std::cout << "Enter the day of the week: ";
  int day;
  cin >> day;
  cout << MACR(day);  
}