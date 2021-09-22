#include <iostream>
#include <map>

using namespace std;

bool is_anagram(const string &, const string &);

int main() {
    string str1;
    string str2;;
    cout << "Enter the first word: ";
    cin >> str1;
    cout << "Enter the second word: ";
    cin >> str2;

  cout << (is_anagram(str1, str2)? "Anagrams": "Not anagrams") << endl;
}

bool is_anagram(const string &str1, const string &str2)
{
  if(str1.length() != str2.length()) return false;
  else {
      map<char, int> str1Map;
      map<char, int> str2Map;

      for(size_t i = 0; i < str1.length(); ++i)
      {
          int counter = 0;
          if(str1Map.find(str1[i]) == str1Map.end())
          {
            str1Map.insert(make_pair(str1[i], 0));
          }else {
            counter = str1Map.find(str1[i])->second;
            ++counter;
            str1Map[str1[i]] = counter;
          }

          counter = 0;
          if(str2Map.find(str2[i]) == str2Map.end())
          {
            str2Map.insert(make_pair(str2[i], 0));
          }else {
            counter = str2Map.find(str2[i])->second;
            ++counter;
            str2Map[str2[i]] = counter;
          }
      }
      if(str1Map.size() != str2Map.size())
      {
          return false;
      }else
      {   auto it2 = str2Map.begin();
          for(auto it1 = str1Map.begin(); it1 != str1Map.end(); ++it1, ++ it2)
          {
              if(it1->first != it2->first || it1->second != it2->second) return false;
          }
      }
  }

  return true;
}
