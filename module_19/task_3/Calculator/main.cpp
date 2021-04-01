#include <iostream>
#include <sstream>

int main() {
  std::stringstream buff;
  std::string str;
  std::cin >> str;
  buff.str(str);

  double num1;
  double num2;
  char op;

  buff >> num1;
  buff >> op;
  buff >> num2;

  if(op == '+'){
       std::cout << num1 << " " << op << " " << num2 << " = "<< num1 + num2 << std::endl;
  }else if(op == '-'){
       std::cout << num1 << " " << op << " " << num2 << " = "<< num1 - num2 << std::endl;
  }else if(op == '*'){
       std::cout << num1 << " " << op << " " << num2 << " = "<< num1 * num2 << std::endl;
  }else if(op == '/'){
       if(num2 != 0) {
         std::cout << num1 << " " << op << " " << num2 << " = "<< num1 / num2 << std::endl;
       } else{
         std::cout << "division by zero error" << std::endl;
       }
  }
}
