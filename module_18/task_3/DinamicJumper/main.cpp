#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int jump(int, int);

int main() {
    int n;
    int k;
    cin >> n >> k;
    cout << jump(n, k) << endl;
}

int jump(int n, int k = 1){
    if (n < 0) return 0;
    if (n == 0) return 1;
    int summ = 0;
    for(int i = 1; i <= k; ++i){
        summ += jump(n-i, k);
    }
    return summ;
}

