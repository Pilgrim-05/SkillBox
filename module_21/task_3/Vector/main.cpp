#include <iostream>
#include <cmath>

struct myVector
{
    double x;
    double y;
};

using namespace std;

myVector add(myVector&, myVector&);
myVector subtract(myVector&, myVector&);
double scale(myVector&, myVector&);
double length(myVector&);
void normalize(myVector &vec);

int main()
{
    cout << "Enter one of the commands(add/subtract/scale/length/normalize): ";
    string command;
    cin >> command;
    if(command == "add")
    {
        myVector vec1, vec2, result;
        cout << "Enter X and Y of vector A: ";
        cin >> vec1.x >> vec1.y;
        cout << "Enter X and Y of vector B: ";
        cin >> vec2.x >> vec2.y;
        result =  add(vec1, vec2);
        cout << result.x << "; " << result.y << endl;

    }else if(command == "subtract")
    {
        myVector vec1, vec2, result;
        cout << "Enter X and Y of vector A: ";
        cin >> vec1.x >> vec1.y;
        cout << "Enter X and Y of vector B: ";
        cin >> vec2.x >> vec2.y;
        result =  subtract(vec1, vec2);
        cout << result.x << "; " << result.y << endl;

    }else if(command == "scale")
    {
        myVector vec1, vec2;
        double result;
        cout << "Enter X and Y of vector A: ";
        cin >> vec1.x >> vec1.y;
        cout << "Enter X and Y of vector B: ";
        cin >> vec2.x >> vec2.y;
        result =  scale(vec1, vec2);
        cout << result << endl;

    }else if(command == "length")
    {
        myVector vec;
        double result;
        cout << "Enter X and Y of vector A: ";
        cin >> vec.x >> vec.y;
        result =  length(vec);
        cout << result << endl;

    }else if(command == "normalize")
    {
        myVector vec;
        cout << "Enter X and Y of vector A: ";
        cin >> vec.x >> vec.y;
        normalize(vec);
        cout << vec.x << "; " << vec.y << endl;
    }else
    {
      cout << "Undefined command!" << endl;
    }
    return 0;
}

myVector add(myVector &vec1, myVector &vec2)
{
    myVector result;
    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;
    return result;
}

myVector subtract(myVector &vec1, myVector &vec2)
{
    myVector result;
    result.x = vec1.x - vec2.x;
    result.y = vec1.y - vec2.y;
    return result;
}

double scale(myVector &vec1, myVector &vec2)
{
    double result;
    result = vec1.x * vec2.x + vec1.y * vec2.y;
    return result;
}

double length(myVector &vec)
{
    double res = fabs(sqrt(vec.x * vec.x + vec.y * vec.y));
    return res;
}

void normalize(myVector &vec)
{
  double invlng = 1/length(vec);
  vec.x *= invlng;
  vec.y *= invlng;
}
