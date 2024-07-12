// Задание 15.6.3.Ввод чисел в массив и вывод заданного элемента
#include<iostream>

bool ValidNum(std::string);                 // Проверка валидности ввода
std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
int InputNumber(std::string);               // Ввод числа
template<int rc, typename nT>
void InsertValue(nT (&)[rc], int);            // Вставка элемента
template<int rc, typename nT>
void PrintMass(nT (&)[rc]);              // Вывод массива

int main(){
    int mass[5] {2147483647, 2147483647, 2147483647, 2147483647, 2147483647}; 
    int num = 0, inNum = 1;

    std::cout << std::endl;
    std::cout << "Enter the sequence elements. To output the fifth ascending element, enter \"-1\"." << std::endl;
    std::cout << "Exit from the program - \"-2\"." << std::endl << std::endl;
    
    do{
        num = InputNumber("Enter a value: ");
        
        if(num >= 0){
            if(num < mass[4]){
                InsertValue(mass, num);
                inNum++;
            }
        } else if(num == -1 && inNum > 5){
            std::cout << "The fifth element in the array: " << mass[4] << std::endl;
        } else if(num == -1){
            std::cout << "There are fewer than five elements in the array!" << std::endl;
        } else if(num == -2){
            std::cout << "The program completes its work. Good luck!" << std::endl;
        } else{
            std::cerr << "Incorrect data has been entered!" << std::endl;
        }
        
        // PrintMass(mass);
    } while(num != -2);

    system("pause");
    return 0;
}

// *********************

// Проверка валидности ввода
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;    
    
    for(int i = 0; i < inTxt.length(); i++){  
        if(i == 0 && inTxt[i] == '-'){
            res &= true;
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
int InputNumber(std::string inTxt){
    std::string resTxt = "";
    int res = 0;   
    
    do {
        resTxt = CheckInputOfEmpty(inTxt);               

        if(ValidNum(resTxt)){
            res = std::stoi(resTxt);
        } else {            
            std::cerr << "Incorrect data has been entered! Try again." << std::endl;
        }

    } while (!ValidNum(resTxt));
    
    return res;
} 

// Вставка элемента
template<int rc, typename nT>
void InsertValue(nT (&inMass)[rc], int insNum){
    int ind = 0;

    for(int i = 0; i < 5; i++){
        if(insNum < inMass[i]){
            ind = i;
            break;
        }
    }
    
    if(ind < 4){
        for(int i = 4; i >= ind; i--){
            inMass[i] = inMass[i - 1];
        }
    }
    
    inMass[ind] = insNum;    
    
}         

// Вывод массива
template<int rc, typename nT>
void PrintMass(nT (&inMass)[rc]){
    std::cout << "mass => {" ;
    for(int i = 0; i < std::size(inMass); i++){
        std::cout << inMass[i];
        if(i != std::size(inMass) - 1){
            std::cout << ", "; 
        }
    }
    std::cout << "}" << std::endl;
}