#include <iostream>
#include <vector>
#include <map>

using namespace std;

void filling(vector<int> &);
void analysis(vector<int> &);
void printMap(const map<int, int>&);

#define MACR(s) s

int main() {
  vector<int> wagons(10);
  MACR(filling)(wagons);
  MACR(analysis)(wagons);

  return 0;
}

void filling(vector<int> &wagons)
{
    cout << "Write ten numbers separated by a space." << endl;
  int tmp;
  for(size_t i = 0; i < wagons.size(); ++i)
  {
    cin >> tmp;
    if(tmp < 0) wagons[i] = 0;
    else wagons[i] = tmp;
  }
}

void analysis(vector<int> &wagons)
{
  int total = 0;
  map<int, int> crowded;
  map<int, int> free;

  for(size_t i = 0; i < wagons.size(); ++i)
  {
    total += wagons[i];
    if(wagons[i] > 20) {
      crowded.insert(make_pair(i+1, wagons[i]-20));
    }

    if(wagons[i] < 20) {
      free.insert(make_pair(i+1, 20 - wagons[i]));
    }
  }

  cout << endl << "***overcrowded wagons***" << endl;
  printMap(crowded);
  cout << endl << "***free seats in wagons***" << endl;
  printMap(free);
  cout << endl << "Total number of passengers: " << total << endl;

}

void printMap(const map<int, int> &mp)
{
    if(!mp.empty())
    {
        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
          cout << "Wagon #" << it->first << " : " << it->second << endl;
        }
    }else{
        cout << "Are not available." << endl;
    }
}
