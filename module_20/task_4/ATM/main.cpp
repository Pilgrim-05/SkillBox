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
void withdraw(std::vector <int> &vec, int amount);


int main() {
  const int SIZE = 5;
  std::vector <int> denominations(SIZE, 0); //the number of each denomination in ATM (100/500/1000/2000/5000)
  char operation;
  cout << "Select operation (fill (+) / remove (-)): ";
  cin >> operation;
  if(operation == '+')
  {
    cout << "------Filling ATM------" << endl;

    fillingATM(denominations);
    ArrayToFile(denominations);
    printVec(denominations);
  }else if(operation == '-')
  {
    cout << "--------Withdrawing funds from an ATM--------" << endl;
    if(fileToArray(denominations))
    {
      cout << "Enter the amount: ";
      int amount;
      cin >> amount;
      cout << "bills\t   \tcash" << endl;
      cout << "---------------------" << endl;
      withdraw(denominations, amount);
      ArrayToFile(denominations);
    }else{
      cout << "ATM is empty." << endl;
    }

  }else
  {
    cout << "WARNING: The command is not recognized!" << endl;
  }

  //printVec(denominations);
}


bool fileToArray(std::vector <int> &vec)
{
  std::ifstream fin(pathToFile, std::ios::binary);
  bool status = false;
  if(fin.is_open())
  {
    status = true;
    int index = 0;
    while(!fin.eof()){
      int tmp = 0;
      fin >> tmp;
      vec[index] = tmp;
      ++index;
    }
  fin.close();

  }
  return status;
}

void ArrayToFile(const std::vector <int> &vec)
{
  std::ofstream fout(pathToFile, std::ios::binary);
  if(fout.is_open())
  {
    for(size_t i = 0; i < vec.size(); ++i){
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
  int total = 0;
  if(fileToArray(vec))
  {
     total = totalAmount(vec);
  }
  if(total < MAX_BILL)
  {
      srand(time(nullptr));
      int emptCells = 0;

      emptCells = MAX_BILL - total;

      for(int i = 0; i < emptCells; ++i){
        int bill;
        bill = rand() % 5;
        vec[bill]++;
      }
  }else{
      cout << "Maximum number of banknotes in an ATM!" << endl;
  }
}

int totalAmount(const std::vector <int> &vec)
{
  int summ = 0;
  for(size_t i = 0; i < vec.size(); ++i){
    summ +=vec[i];
  }
  return summ;
}

void printVec(const std::vector <int> &vec)
{
  for(size_t i = 0; i < vec.size(); ++i){
    cout << vec[i] << " ";
  }
  cout << endl;

}

void withdraw(std::vector <int> &vec, int amount)
{
    int banknotes[]={100, 500, 1000, 2000, 5000};
    int summ = 0;
    for(size_t i = 0; i < vec.size(); ++i){
      summ +=vec[i]*banknotes[i];
    }

    if(amount <= 0 || amount > summ || amount%100 != 0)
    {
        cout << "The operation cannot be performed." << endl;
    }else
    {
        for(int i = vec.size()-1; i >= 0; --i){


            if(amount >= banknotes[i])
            {
               int tmp = 0;
               tmp = amount / banknotes[i] <= vec[i]? amount / banknotes[i]: vec[i];
               amount -=banknotes[i] * tmp;
               vec[i] -=tmp;
               cout << banknotes[i] << "\t - \t" << (banknotes[i] * tmp) << endl;

            }

        }
    }

}
