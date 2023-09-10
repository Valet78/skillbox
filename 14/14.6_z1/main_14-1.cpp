// Задание 14.6.1. Банкетный стол

#include<iostream>

template<int rows, int col>

// Функция вывода матрицы (для контроля действий)
void PrintMass(int (&inMass)[rows][col]){
        
    for(int r = 0; r < 2; r++){
        std::cout << "Row " << r + 1 << "\tVip\t1\t2\t3\t4\t5" << std::endl << "\t";
        
        for(int k = 0; k < col; k++){ 
            for(int l = 0; l < 6; l++){                
                std::cout << inMass[r * 6 + l][k] << "\t";
            }    
            
            if(col > 1){
                std::cout << std::endl << "\t";
                }              
        }               
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl; 
}


int main(){
    // Тарелки в следующем порядке: тарелка для первого, для второго и для десерта
    int plates[12][3] = {{1, 1, 1}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0},
                         {1, 1, 1}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}};
    // Столовые приборы: вилка, ложка, нож, вилка для десерта
    int tableware[12][4] = {{1, 1, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0},
                            {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 0},
                            {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0}};
    int chairs [12][1] = {{1}, {1}, {1}, {1}, {1}, {1},
                          {1}, {1}, {1}, {1}, {1}, {1}};

    system("cls");
    std::cout << "Distribution of guests at the table" << std::endl;
    std::cout << "(Размещение гостей за столом)" << std::endl << std::endl;
    PrintMass(chairs);
    system("pause");

    // Ситуации:
    
    // 1. Пришедшая на пятое место первого ряда дама привела с собой ребёнка, 
    //    и поэтому на данное место был приставлен ещё один стул.    
    chairs[5][0] += 1; 
    system("cls");
    std::cout << "Another chair was placed in the fifth place of the first row" << std::endl;
    std::cout << "(На пятое место первого ряда был приставлен ещё один стул)" << std::endl << std::endl;
    PrintMass(chairs);
    system("pause");
    
    // 2. С третьего места во втором ряду в неизвестном направлении была украдена ложка.
    tableware[9][1] -= 1;
    system("cls");
    std::cout << "A spoon was stolen from the third place in the second row" << std::endl;
    std::cout << "(С третьего места второго ряда была украдена ложка)" << std::endl << std::endl;
    PrintMass(tableware);
    system("pause");

    // 3. Одна из VIP-персон (любая) поделилась своей ложкой с тем, кто остался без ложки, 
    // и стала есть суп десертной.
    tableware[6][1] -= 1;
    tableware[9][1] += 1;  
    system("cls");
    std::cout << "One of the VIPs shared her spoon with the one who was left without it" << std::endl;
    std::cout << "(Один из VIP персон поделился своей ложкой с тем, кто лишился её)" << std::endl << std::endl;
    PrintMass(tableware);
    system("pause");


    // 4. За ненадобностью официант забрал у VIP-гостя одну десертную тарелку, ведь есть десерт ложкой, 
    // которая уже побывала в супе, неприлично.
    plates[6][2] -= 1;
    system("cls");
    std::cout << "The waiter took one dessert plate from the VIP guest" << std::endl;
    std::cout << "(Официант убрал у VIP персоны тарелку для десерта)" << std::endl << std::endl;
    PrintMass(plates);
    system("pause");
    
    return 0;
}

