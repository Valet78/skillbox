// Задание 16.6.2. Сшиватель дробных чисел

# include<iostream>

bool ValidNum(std::string, std::string);                 // Проверка валидности ввода
std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
std::string InputNumber(std::string, std::string);       // Ввод числа (возвращает строку)

int main(){
    std::cout << std::endl << "The program will combine the integer and fractional parts of the number." << std::endl;
    std::string wholePart = InputNumber("Enter the whole part: ", "whole");
    std::string fractPart = InputNumber("Specify the fractional part: ", "fract");
    double inputNum = std::stod(wholePart + "." + fractPart);

    std::cout << "---------------------------------" << std::endl;
    std::cout << "Input number: " << std::to_string(inputNum) << std::endl;

    return 0;
}

// ****************

// Проверка валидности ввода
bool ValidNum(std::string inTxt, std::string type){                    
    bool res = (inTxt.empty()) ? false: true;  
    int point = 0;  
    
    for(int i = 0; i < inTxt.length(); i++){  
        
        if(i == 0 && inTxt[i] == '-'){
           res &= (type == "whole") ? true: false;
            continue;
        } 

        res &= inTxt[i] >= '0' && inTxt[i] <= '9';
    }

    return res;
}

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

// Ввод числа
std::string InputNumber(std::string inTxt, std::string type){
    std::string resTxt = "";      
    
    do {
        resTxt = CheckInputOfEmpty(inTxt);               

        if(!ValidNum(resTxt, type)){
            std::cerr << "Incorrect data has been entered! Try again." << std::endl;
        }

    } while (!ValidNum(resTxt, type));
    
    return resTxt;
} 

