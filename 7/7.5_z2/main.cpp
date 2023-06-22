#include <iostream>
#include <string>
#include <codecvt>
#include <locale>

int main(){
    auto txt = u8"ппрррррырырырЭ";
    std::cout << txt << std::endl;


    std::u16string str = u"Привет. ****************";
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
    std::cout << converter.to_bytes(str) << std::endl;

    
    


    return 0;
}