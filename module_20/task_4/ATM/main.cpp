#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

const std::string pathToFile = "../src/atm.bin";

int totalAmount(const std::vector <int> &vec);
void fillingATM(std::vector <int> &vec);
void ArrayToFile(const std::vector <int> &vec);
bool fileToArray(std::vector <int> &vec);
void printVec(const std::vector <int> &vec);

//void fileread(); //test

int main() {
  const int SIZE = 5;
  std::vector <int> denominations(SIZE, 0); //the number of each denomination in ATM (100/500/1000/2000/5000)
    //fileread();
  char operation;
  cout << "Select operation (fill (+) / remove (-)): ";
  cin >> operation;
  if(operation == '+')
  {
    cout << "------Filling ATM------" << endl;
    fillingATM(denominations);
    ArrayToFile(denominations);
  }else if(operation == '-')
  {
    cout << "--------Withdrawing funds from an ATM--------" << endl;
    if(fileToArray(denominations))
    {
      cout << "Enter the amount: ";
      int amount;
      cin >> amount;
    }else{
      cout << "ATM is empty." << endl;
    }

  }else
  {
    cout << "WARNING: The command is not recognized!" << endl;
  }

  printVec(denominations);
}


bool fileToArray(std::vector <int> &vec)
{
  std::ifstream fin(pathToFile, std::ios::binary);
  if(fin.is_open())
  {
    int index = 0;
    while(!fin.eof()){
      int tmp;
      fin >> tmp;
      vec[index] = tmp;
      ++index;
    }
  fin.close();

  }else{
    cout << "File not found!" << endl;
  }
  return totalAmount(vec);
}

void ArrayToFile(const std::vector <int> &vec)
{
  std::ofstream fout(pathToFile, std::ios::binary);
  if(fout.is_open())
  {
    for(int i = 0; i < vec.size(); ++i){
      fout << vec[i] << endl;
    }

  }else{
    cout << "File not found!" << endl;
  }

  fout.close();
}

void fillingATM(std::vector <int> &vec)
{
  const int MAX_BILL = 1000; // Maximum number of notes in ATM
  srand(time(nullptr));
  int emptCells = 0;

  emptCells = MAX_BILL - totalAmount(vec);

  for(int i = 0; i < emptCells; ++i){
    int bill;
    bill = rand() % 5;
    vec[bill]++;
  }
}

int totalAmount(const std::vector <int> &vec)
{
  int summ = 0;
  for(int i = 0; i < vec.size(); ++i){
    summ +=vec[i];
  }
  return summ;
}

void printVec(const std::vector <int> &vec)
{
  for(int i = 0; i < vec.size(); ++i){
    cout << vec[i] << " ";
  }
  cout << endl;
}

//-----------test-------------
void fileread()
{
  std::ifstream fin(pathToFile, std::ios::binary);
  if(fin.is_open())
  {
    while(!fin.eof()){
      int tmp=0;
      fin >> tmp;
      cout << tmp << " ";
    }
  fin.close();

  }else{
    cout << "File not found!" << endl;
  }
}
//----------------------------

