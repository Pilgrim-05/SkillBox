#include <iostream>

using std::cout;
using std::endl;

void evendigits(long long, int&);

int main() {
  int ans = 0;
  long long n = 9223372036854775806;
  evendigits(n, ans);
  cout << ans << endl;
}

void evendigits(long long n, int& ans){
  if(n/10 == 0) return;
  if(n%10%2 == 0) ++ans;
  evendigits(n/10, ans);
}
