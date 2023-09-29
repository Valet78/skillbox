#include <iostream>

enum Bits { One = 1, Two = 2, Three = 4, Four = 8 };

void lamp_output(bool lamps[]) {
   std::cout << "Lamps:\n   "
             << lamps[3] * Bits::Four << "  "
             << lamps[2] * Bits::Three << "  "
             << lamps[1] * Bits::Two << "  "
             << lamps[0] * Bits::One << "\n";
   for (int i = 4; i >= 0; --i) {
       if (lamps[i])
           std::cout << "💡 ";
       else
           std::cout << "   ";
   }
}

int main() {
   bool lamps[4] = {false};
   int number = 1;
   while (number != 0) {
       if(number > 15) {
           std::cout << "Wrong number!";
           continue;
       }

       std::cout << "Decimal number:" << number << "\n";
       lamps[0] = (number & Bits::One);
       lamps[1] = (number & Bits::Two);
       lamps[2] = (number & Bits::Three);
       lamps[3] = (number & Bits::Four);

       lamp_output(lamps);

       std::cout << "\n";
       std::cout << "Input number 1 - 15 (0 - exit):\n";
       std::cin >> number;
   }
   return 0;
}