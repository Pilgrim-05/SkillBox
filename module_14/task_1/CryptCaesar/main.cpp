#include <iostream>

using std::cout;
using std::cin;
using std::endl;

char encoder(char currentCh, int shift, char startCh, char finalCh);
std::string encryptCaesar(std::string str, int addition);
std::string decryptCaesar(std::string str, int addition);

int main()
{
    cout << "Enter any English text for encryption" << endl;
    std::string text;
    getline(cin, text);
    cout << "Enter the encryption key-number: ";
    int addition;
    cin >> addition;

    cout << endl << "--- ciphertext ---" << endl;
    cout << encryptCaesar(text, addition);
    cout << endl << "--- decrypted text ---" << endl;
    cout << decryptCaesar(encryptCaesar(text, addition), addition);

    return 0;
}

std::string encryptCaesar(std::string str, int addition){

    addition %=26;
    for(unsigned int i = 0; i < str.length(); i++){        
        if((str[i] >= 'a' && str[i] <= 'z')){
            str[i] = encoder(str[i], addition, 'a', 'z');
        }
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = encoder(str[i], addition, 'A', 'Z');
        }
    }
    return str;
}

std::string decryptCaesar(std::string str, int addition){
    return encryptCaesar(str, -addition);
}

char encoder(char currentCh, int shift, char startCh, char finalCh){

    if(currentCh + shift > finalCh){
        currentCh =  startCh + (currentCh + shift - finalCh - 1);
    }else if(currentCh + shift < startCh){
        currentCh = finalCh - (startCh - (currentCh + shift) - 1);
    }else{
        currentCh +=shift;
    }

    return currentCh;
}
