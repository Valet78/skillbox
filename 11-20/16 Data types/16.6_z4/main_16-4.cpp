// Зажание 16.6.4. Механическое пианино

# include<iostream>

bool ValidNum(std::string, std::string);    // Проверка валидности ввода
std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
std::string InputNumber(std::string);       // Ввод числа (возвращает строку)
std::string GetNotes(std::string);          // Получение ноты из строки цифр

int main(){
    std::string resNotes = "";

    enum note {DO = 1, RE = 2, MI = 4, FA = 8, SOL = 16, LA = 32, SI = 64};

    std::cout << std::endl << "The program \"Mechanical Piano\"." << std::endl;
    std::cout << "Specify twelve combinations of notes from natural numbers (1..7)," << std::endl;
    std::cout << "where \"1\" is \"do\" and \"7\" is \"si\"." <<std::endl;

    for(int i = 0; i < 12; i++){
        std::string combNotes = InputNumber(std::to_string(i + 1) + " combination of notes: ");
        resNotes.append(GetNotes(combNotes));       
    }
    
    std::cout << "---------------------------------" << std::endl;
    std::cout << resNotes << std::endl << std::endl;  
    
    return 0;
}

// ****************

// Проверка валидности ввода
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;  
        
    for(int i = 0; i < inTxt.length(); i++){  
        res &= inTxt[i] >= '1' && inTxt[i] <= '7';
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
std::string InputNumber(std::string inTxt){
    std::string resTxt = "";      
    
    do {
        resTxt = CheckInputOfEmpty(inTxt);               

        if(!ValidNum(resTxt)){
            std::cerr << "Incorrect data has been entered! Try again." << std::endl;
        }

    } while (!ValidNum(resTxt));
    
    return resTxt;
} 

// Получение ноты из строки цифр
std::string GetNotes(std::string inTxt){
    std::string res = "", tmp = "";    
    int ind = 0;
    enum note {DO = 1, RE = 2, MI = 4, FA = 8, SOL = 16, LA = 32, SI = 64};

    for(int i = 0; i < inTxt.length(); i++){
        ind = 1 << (int) (inTxt[i] - '0') - 1;
        
        switch (ind)
        {
        case note::DO:
            res += "DO ";
            break;
        case note::RE:
            res += "RE ";
            break;
        case note::MI:
            res += "MI ";
            break;    
        case note::FA:
            res += "FA ";
            break;    
        case note::SOL:
            res += "SOL ";
            break; 
        case note::LA:
            res += "LA ";
            break; 
        case note::SI:
            res += "SI ";
            break;          
        }        
    }
    
    return res;
}    