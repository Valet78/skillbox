// Задание 16.6.3. Калькулятор

#include<iostream>
#include<sstream>

std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода

int main(){
    std::string buffer = " ";
    double in_a = 0, in_b = 0, rez = 0;
    char operation = ' ';    
    

    std::cout << std::endl << "The calculator program." << std::endl;
    std::cout << "Specify the action in the format <number-1><action><number-2> (without spaces)." << std::endl;
    std::cout << "To exit the program, enter \"exit\"." << std::endl;
    
    do{
        std::cout << "Enter the expression: ";
        std::cin >> buffer;

        if(buffer != "exit"){          
          std::stringstream inTxt(buffer);
          
          inTxt >> in_a >> operation >> in_b;

          if(in_a != 0 && in_b != 0 && operation != ' '){
            switch (operation)
            {
              case '+':
                rez = in_a + in_b;
                break;

              case '-':
                rez = in_a - in_b;
                break;

              case '*':
                rez = in_a * in_b;
                break;

              case '/':
                rez = in_a / in_b;
                break;       

              default:
                std::cout << "Incorrect data has been entered! The program will be completed." << std::endl; 
                return -1;   
                break;     
            }             
            
            std::cout << std::to_string(in_a) << " " << operation << " " << std::to_string(in_b) << " = " << rez << std::endl;
                    
          } else {
            std::cout << "Incorrect data has been entered! The program will be completed." << std::endl; 
            return -1;            
          }
          
        }

    } while (buffer != "exit");
    

    return 0;
}

// *************

// Проверка ввода строки и пустого ввода
std::string CheckInputOfEmpty(std::string inTxt){
  std::string result = "";
   do{
    std::cout << inTxt;
    getline(std::cin, result);
    
    if (result.empty()){
      std::cerr << "You forgot to enter the value! Try again." << std::endl;
    } 
  } while(result.empty()); 
  return result;
}
