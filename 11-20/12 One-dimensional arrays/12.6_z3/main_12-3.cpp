// Задание 12.5.3. Использование assert

#include <iostream>
#include <cassert>

std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
bool ValidNumber(std::string);  // Проверка чисел
float travelTime(float, float);  // Расчёт времени в пути

int main(){
    float distance = 0.0f, speed = 0.0f, time = 0.0f; 
    std::cout << "The program for demonstrating the operation of the \"assert\" macro." << std::endl;

    std::string distanceText = CheckInputOfEmpty("Specify the distance traveled by the traveler: ");
    std::string speedText = CheckInputOfEmpty("How fast was the traveler moving: ");
    std::cout << "--------------------------------------------------" << std::endl;

    if(ValidNumber(distanceText) && ValidNumber(speedText)){
        distance = std::stof(distanceText);
        speed = std::stof(speedText);

        assert(distance > 0); 
        assert(speed > 0);

        if(distance > 0 && speed > 0){
            time = travelTime(distance, speed);
            std::cout << "The traveler will need " << time << " units of time." << std::endl << std::endl;
        } else {
            std::cout << "Error! The program is waiting for the input of a fractional number greater than zero." << std::endl;
            return -1;
        }

    } else {
        std::cout << "Error! The program is waiting for the input of a fractional number greater than zero." << std::endl;
        return -1;
    }

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

// Расчёт времени в пути
float travelTime(float distance, float speed){
   return distance / speed;
}

