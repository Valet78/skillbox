// Задание 12.5.2. Сортировка

#include <iostream>

std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
std::string CheckInputNumber(std::string); // Ввод элемента массива
bool ValidNumber(std::string); // Проверка чисел

int main(){
    std::string inMassive [15];

    std::cout << "A program for sorting an array of floating-point numbers." << std::endl;
    std::string inputTxt = CheckInputOfEmpty("Enter 15 fractional numbers separated by a space: ");

    bool valid = true;
    int indNull = 0, ind = 0;

    do {
        indNull = inputTxt.find(' ');
        inMassive[ind] = inputTxt.substr(0, indNull);
        valid &= (ValidNumber(inMassive[ind]));
        
        inputTxt = inputTxt.substr(indNull + 1, inputTxt.length() - indNull);
        ind++;        
    } while (indNull > 0 && ind < 15);
   
    // Проверка правильности ввода
    if(!valid || ind < 15 || indNull > 0){
        std::cout << std::endl << "Error! The program is waiting for the input of 15 fractional numbers. " << 
                     "The program will be completed." << std::endl << std::endl;
        return 0;
    }
    
    float flMass[15]; 
    float flNum = 0.0f;
    int start = -1, stop = -1; 

    for(int i = 0; i < 15; i ++){   // Проход по внешнему массиву строк
        flNum = std::stof(inMassive[i]);
        start = -1;
        stop = -1;
        
        if(i == 0){
            flMass[i] = flNum; 
        } else {
            
            for(int k = 0; k < i; k++){ // проход                 

                if(flNum > flMass[k]){
                    start = k;
                    stop = i;
                    break;
                }                
            }

            if(start != -1 && stop != -1){
                for (int s = stop; s > start; s--){
                    flMass[s] = flMass[s-1];
                }
                flMass[start] = flNum;
            } else {
                flMass[i] = flNum;
            }      
        }     
    }    

    std::cout << "The resulting sorted array: ";

    // Результат
    for(int i = 0; i < 15; i++){
        std::cout << flMass[i] << " ";
    }
    std::cout << std::endl;    

    return 0;
} 

// Проверка ввода строки и пустого ввода
std::string CheckInputOfEmpty(std::string inTxt){
  std::string result = "";
   do{
    std::cout << inTxt;
    getline(std::cin, result);
    if (result == ""){
      std::cout << "You forgot to enter the value! Try again." << std::endl;
    } 
  } while(result == ""); 

  return result;
}

// Ввод элемента массива
std::string CheckInputNumber(std::string inTxt){
    std::string res = "";
    bool valid = true;
    do {
        res = CheckInputOfEmpty(inTxt);
        if (ValidNumber(res)){
            valid = true;
        } else {
            valid = false;
            std::cout << "Incorrect data has been entered! Try again." << std::endl; 
        }
    } while (!valid);
    
    return res;
} 

// Проверка чисел
bool ValidNumber(std::string inTxt){
    bool res = true;
    int point = 0;

    if(inTxt.length() == 1 && inTxt[0] == '0'){
        res = true;
    } else {
        for(int i = 0; i < inTxt.length(); i++){
            point += (inTxt[i] == '.') ? 1 : 0;
            res &= ((inTxt[i] >= '0' && inTxt[i] <= '9') || inTxt[i] == '.' || inTxt[0] == '-');         
        }

        res &= (point == 1);
    }    
    
    return res;
} 