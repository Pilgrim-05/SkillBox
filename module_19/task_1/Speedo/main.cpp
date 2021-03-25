#include <iostream>
#include <string>
#include <cstdio>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  char txtSpeed[20];
  double speed = 0.0;
  double epsilon = 0.01;
  double  delta;

  do{
    // string st = "Speed: ";
    cout << "Delta: ";
    cin >> delta;
    speed +=delta;
    if(speed > 150) speed = 150.0;
    if(speed < 0) speed = 0.0;
    // st = st + std::to_string(speed) + " km/h.";
    // cout << st << endl;
    std::sprintf(txtSpeed, "Speed: %.1f %s", speed, "km/h.");
    cout << txtSpeed << endl;

  }while(speed > epsilon);

  cout << endl << "The movement is stopped." << endl;
}

