// Задание 15.6.3.Ввод чисел в массив и вывод заданного элемента
#include<iostream>
#include<vector>

bool ValidNum(std::string);                 // Проверка валидности ввода
std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
int InputNumber(std::string);               // Ввод числа
void InsertVec(std::vector <int> &, int);   // Вставка элемента
void Print(std::vector <int>);              // Вывод вектора

int main(){
    std::vector<int> inVec; 
    int num = 0;

    std::cout << std::endl;
    std::cout << "Enter the sequence elements. To output the fifth ascending element, enter \"-1\"." << std::endl;
    std::cout << "Exit from the program - \"-2\"." << std::endl << std::endl;
    
    do{
        num = InputNumber("Enter a value: ");
        
        if(num >= 0){
            InsertVec(inVec, num);
            Print(inVec);
        } else if(num == -2){
            std::cerr << "Completion of the program!" << std::endl;
        } else if(num == -1 && inVec.size() < 5){            
            std::cerr << "Not enough elements! You need to enter 5 elements." << std::endl;
        } else if(num == -1 && inVec.size() >= 5){
            std::cout << "The fifth element: " << inVec[4] << std::endl;
        } else {
            std::cerr << "Incorrect data has been entered! Try again." << std::endl;
        }
       
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
void InsertVec(std::vector <int> &vec, int insNum){
    int ind = 0;
    bool ins = false;

    if(vec.size() == 0){
        vec.push_back(insNum);
    } else {
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] > insNum){
                ind = i;
                ins = true;
                break;
            }
        }
        
        if(ins){         
            vec.push_back(vec.back());
            for(int k = vec.size() - 1; k > ind; k--){
                vec[k] = vec[k - 1];
            }
            vec[ind] = insNum;
        } else {
            vec.push_back(insNum);
        }
    }
}         

// Вывод вектора
void Print(std::vector <int> vec){
    std::cout << "vector => {" ;
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i];
        if(i != vec.size() - 1){
            std::cout << ", "; 
        }
    }
    std::cout << "}" << std::endl;
}