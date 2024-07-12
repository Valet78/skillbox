// Задание 11.6.1 "Шифр цезаря"

#include <iostream>

// Проверка ввода строки и пустого ввода
std::string InputTxt(std::string inTxt){
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

// Является ли числом
bool IsDigit(std::string inTxt){  
  int ind = 0;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (i == 0 && inTxt[i] == '-'){
      ind++;
    } else if (int(inTxt[i]) >= 48 && int(inTxt[i] <= 57)){
      ind++;
    }  else {
      ind--;
    }
  }     
  
  if (ind == inTxt.length()){
    return true;
  }  
  return false;
}

// Проверка ввода числа и вывод его
int ValidNum(std::string request){
  int result = 0;
  std::string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = std::stoi(numTxt);
      result = (result > 26 || result < -26) ? result % 26 : result;
      err = false;      
    } else {
      std::cout << "Enter an integer! Try again." << std::endl;
    }  
  } while (err);
  
  return result;
}

// Проверяем символ, является ли он символом латиницы
bool isLat(char inChar){
    // return (((int) inChar >= 65 && (int) inChar <= 90) || 
    //         ((int) inChar >= 97 && (int) inChar <= 122));
    return ((inChar >= 'A' && inChar <= 'Z') || (inChar >= 'a' && inChar <= 'z'));
}

// Вычисляем индекс символа после смещения
int indChar (int min, int max, int ind, int sht){
    ind = ind - min + sht;
    ind = (ind < 0) ? ind + 26 : (ind > 25) ? ind - 26 : ind;
    ind += min;
    return ind;
}

// Функция шифрования
std::string encrypt_caesar (std::string inTxt, int shift){
    std::string resTxt = "";    
    int ind = 0;

    for(int i = 0; i < inTxt.length(); i++){
        if(isLat(inTxt[i])){
            if (inTxt[i] >= 'A' && inTxt[i] <= 'Z'){
                ind = indChar(65, 90, (int) inTxt[i], shift);
            } else {
                ind = indChar(97, 122, (int) inTxt[i], shift);
            }
            resTxt.push_back((char) ind);
        } else {
            resTxt.push_back(inTxt[i]);
        }
    }
    return resTxt;
}

// Функция дешифрования
std::string decrypt_caesar(std::string inTxt, int shift){
    return encrypt_caesar(inTxt, -shift);
}

int main(){
    std::cout << "A program for encrypting text with a Caesar cipher." << std::endl;
    std::string inText = InputTxt("Enter the encryption text: ");
    int shiftValue = ValidNum("Enter the shift value: ");
    std::string encryptText = encrypt_caesar (inText, shiftValue);

    // Выводим результат шифрования
    std::cout << "\n\tEncryption result:" << std::endl << encryptText  << std::endl;

    // Дешифровка
    std::string decryptText = decrypt_caesar (encryptText, shiftValue);
    std::cout << "\n\tDecryption result:" << std::endl << decryptText  << std::endl << std::endl;

    return 0;
}

