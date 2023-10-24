// Задание 16.6.1.Спидометр

# include<iostream>
# include<limits>

bool ValidNum(std::string);                 // Проверка валидности ввода
std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
float InputNumberFloat(std::string);               // Ввод числа
bool compare(float, float, float);           // Сравнение чисел с учётом отклонения

int main(){
    float speed = 0.00f, delta = 0.00f, rate = 0.01f;
    std::cout << std::endl << "The program \"Speedometer\"." << std::endl << std::endl; 
    char speedTxt[5];

    do{
        delta = InputNumberFloat("Speed delta: ");
        speed += delta;        

        if(compare(speed, 150.00f, 0.01f) || (speed > 150.00f)){    
            std::cout << "The car's speed has reached the maximum limit of 150 km/h." << std::endl;
            speed -= delta;
        
        } else if(compare(speed, 0.00f, 0.01f) || (speed < 0)){    
            std::cout << "The car stopped." << std::endl;
            speed = 0.00f;
            
        } else {
            sprintf(speedTxt, "%.1f", speed);
            std::cout << "Speed: " << speedTxt << std::endl;
        }

    } while(speed > 0.00f);

    return 0;
}

// *********************

// Проверка валидности ввода
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;  
    int point = 0;  
    
    for(int i = 0; i < inTxt.length(); i++){  
        if(i == 0 && inTxt[i] == '-'){
            res &= true;
            continue;
        } else if(point == 0 && inTxt[i] == '.'){
            res &= true;
            point++;
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
float InputNumberFloat(std::string inTxt){
    std::string resTxt = "";
    float res = 0;   
    
    do {
        resTxt = CheckInputOfEmpty(inTxt);               

        if(ValidNum(resTxt)){
            res = std::stof(resTxt);
        } else {            
            std::cerr << "Incorrect data has been entered! Try again." << std::endl;
        }

    } while (!ValidNum(resTxt));
    
    return res;
} 

// Сравнение чисел с учётом отклонения
bool compare(float value, float reference, float epsilon){
    return (value >= reference - epsilon) && (value <= reference + epsilon);
}