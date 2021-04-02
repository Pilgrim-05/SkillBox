#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int jump(int);

int main() {
    int n;
    cin >> n;
    cout << jump(n) << endl;
}

int jump(int n){
    if (n < 0) return 0;
    if (n == 0) return 1;
    return jump(n-1) + jump(n-2) + jump(n-3);
}

