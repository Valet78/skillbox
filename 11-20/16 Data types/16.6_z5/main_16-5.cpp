// Задание 16.6.5. Умный дом.

#include <iostream>
#include <string>

enum Switches {
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16
};
std::string InputText(std::string);         // Ввод команд и проверка
bool ValidNum(std::string, std::string);    // Проверка валидности ввода
template<int col>
bool ParseText (std::string, std::string (&)[col]);     // Разбор строки
void StateLightIns (std::string, int, int &);           // Статус освещения внутри
void StateLightOut (std::string, int, int &);           // Статус освещение снаружи
void StateHeaters (int, int &);                         // Статус обогревателя (вкл/выкл)  
void StatePipHeating (int, int &);                      // Статус обогревателя водопровода
void StateConditioner (int, int &);                     // Статус работы кондиционера
int TempLightIn (int, bool);                            // Установка температуры освещения

int main(){
    
    std::string inText = "";
    std::string parse[4];      
    int switchStat = 0;
    int dayNow = 0, timeNow = 0, tempIn = 0, tempOut = 0, lightTemp = 5700;

    std::cout << "A \"Smart Home\" simulation program." << std::endl;
    std::cout << "Enter readings every hour in the following format:" << std::endl;
    std::cout << "\"Temperature inside, temperature outside, movement, lights\"" << std::endl;
    std::cout << "-------------------------------------------------------------" <<std::endl;
    
    for(int i = 0; i < 48; i++){ 
        dayNow = i / 24;
        timeNow = i % 24;
        std::cout << "Day: " << std::to_string(dayNow) << " Time: " << std::to_string(timeNow) + ":00" << std::endl; 
        inText = InputText("Temperature inside, temperature outside, movement, lights: ");
        if(ParseText(inText, parse)){
            tempIn = std::stoi(parse[0]);   // температура воздуха внутри дома
            tempOut = std::stoi(parse[1]);  // температура воздуха вне дома
            std::cout << std::endl;


            
            StateLightIns (parse[3], timeNow, switchStat);  // Статус освещения внутри
            StateLightOut (parse[2], timeNow, switchStat);  // Статус освещение снаружи
            StateHeaters (tempIn, switchStat);              // Статус обогревателя
            StatePipHeating (tempOut, switchStat);          // Статус обогревателя водопровода
            StateConditioner (tempIn, switchStat);          // Статус работы кондиционера
                        
        } else {
            std::cout << std::endl << "Incorrect data has been entered! Try again." << std::endl << std::endl;
            i--;
        }
    }

    system("pause");
    return 0;
}

// ****************

// Проверка валидности ввода числа
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;  
        
    for(int i = 0; i < inTxt.length(); i++){  
        if(i == 0 && inTxt[0] == '-'){
            res &= true;
            continue;
        } 
        res &= inTxt[i] >= '0' && inTxt[i] <= '9';               
    }

    return res;
}

// Ввод команд и проверка
std::string InputText(std::string inTxt){
    std::string resTxt = "";      
    
    do{
    std::cout << inTxt;
    getline(std::cin, resTxt);
    
    if (resTxt.empty()){
      std::cerr << "You forgot to enter the value! Try again." << std::endl;
    } 
  } while(resTxt.empty()); 
    
    return resTxt;
} 

// Разбор строки
template<int col>
bool ParseText (std::string inTxt, std::string (&inPars)[col]){
    bool res = true; 
    int ind = 0;
       
   for(int i = 0; i < 4; i++){
        ind = inTxt.find(' ');
        inPars[i] = (ind != std::string::npos) ? inTxt.substr(0, ind): inTxt;  
        
        if(i == 0 || i == 1) {
            res &= ValidNum(inPars[i]);
        } else if (i == 2 && (inPars[i] == "yes" || inPars[i] == "no")) {
            res &= true;
        } else if (i == 3 && (inPars[i] == "on" || inPars[i] == "off")) {
            res &= true;
        } else {
            res &= false;
        }     

        inTxt.erase(0, ++ind);
                
    } 

    return res;
}         

// Установка температуры освещения
int TempLightIn(int inTime, bool inState){     

    int tmp = (inTime >= 16 && inTime <= 20) ? 5000 - (2300 / 5 * (inTime - 15)) : (inTime >= 0 && inTime < 16) ? 5000 : 2700;
    
    return (inState) ? tmp : 5000;
}

// Статус освещения внутри
void StateLightIns (std::string inTxt, int inTime, int &inState){    
    int lightTemp = TempLightIn(inTime, inState);    // Установка температуры освещения

    if(!(inState & LIGHTS_INSIDE) && inTxt == "on"){
        inState |= LIGHTS_INSIDE;     // включить 
        std::cout << "Lights inside ON!" << std::endl << std::endl;                    
        
    } else if((inState & LIGHTS_INSIDE) && inTxt == "off"){
        
        if(inTxt == "off"){
            inState &= ~LIGHTS_INSIDE;    // выключить
            std::cout << "Lights inside OFF!" << std::endl << std::endl;
        }         
    }    

    if(inState & LIGHTS_INSIDE){
        std::cout << "Color temperature: " << lightTemp << "K" << std::endl << std::endl;
    } 

}                      

// Статус освещение снаружи
void StateLightOut (std::string inTxt, int inTime, int &inState){
   
    if(!(inTime > 5 && inTime < 16)){
        if(!(inState & LIGHTS_OUTSIDE) && inTxt == "yes"){
            inState |= LIGHTS_OUTSIDE;    // включить
            std::cout << "Lights outside ON!" << std::endl << std::endl;
        
        } else if((inState & LIGHTS_OUTSIDE) && inTxt == "no"){
            inState &= ~LIGHTS_OUTSIDE;    // выключить
            std::cout << "Lights outside OFF!" << std::endl << std::endl;
        } 
    } else if(inState & LIGHTS_OUTSIDE){
        inState &= ~LIGHTS_OUTSIDE;    // выключить
        std::cout << "Lights outside OFF!" << std::endl << std::endl;
    }  
}          

// Статус обогревателя
void StateHeaters (int inTemp, int &inState){
    
    if(!(inState & HEATERS) && inTemp < 22){
        inState |= HEATERS;    // включить
        std::cout << "Heaters ON!" << std::endl << std::endl;
    } else if ((inState & HEATERS) && inTemp >= 25){
        inState &= ~HEATERS;    // выключить
        std::cout << "Heaters OFF!" << std::endl << std::endl;
    }
}                           

// Статус обогревателя водопровода
void StatePipHeating(int inTemp, int &inState){

    if(!(inState & WATER_PIPE_HEATING) && inTemp < 0){
        inState |= WATER_PIPE_HEATING;    // включить
        std::cout << "Water pipe heating ON!" << std::endl << std::endl;
    } else if ((inState & WATER_PIPE_HEATING) && inTemp > 5){
        inState &= ~WATER_PIPE_HEATING;    // выключить
        std::cout << "Water pipe heating OFF!" << std::endl << std::endl;
    }
}

// Статус работы кондиционера
void StateConditioner(int inTemp, int &inState){
    
    if(!(inState & CONDITIONER) && inTemp >= 30){
        inState |= CONDITIONER;           // включить
        std::cout << "Conditioner ON!" << std::endl << std::endl;
    } else if ((inState & CONDITIONER) && inTemp < 25){
        inState &= ~CONDITIONER;         // выключить
        std::cout << "Conditioner OFF!" << std::endl << std::endl;
    }
}                      

