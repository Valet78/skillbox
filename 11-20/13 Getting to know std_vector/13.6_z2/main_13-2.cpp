// Задание 13.6.2. Программа расчёта итоговой стоимости покупок (векторы).

#include<iostream>
#include<vector>

int main(){
    std::vector<float> prices {2.5f, 4.25f, 3.0f, 10.0f};
    std::vector<int> items {1, 1, 0, 3};
    float sum = 0.0f;
    
    std::cout << "The program for calculating the total cost of purchases." << std::endl;

    for(int i = 0; i < items.size(); i++){
        if(items[i] >= 0 && items[i] < prices.size()){
            sum += prices[items[i]];            
        } else {
            std::cout << "The \"purchase vector\" contains incorrect data! The program will be completed." << std::endl;
            return -1;
        }
    }

    std::cout << "Total cost of purchases: " << std::to_string(sum) << std::endl;
    // std::cout << "Total cost of purchases: " << sum << std::endl;
    
    return 0;
}