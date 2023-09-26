#include <iostream>
#include <algorithm>

void print_sequence(int(& seq)[8]) {
    for(auto&& item: seq)
    std::cout << item << " ";
std::cout << std::endl;
}

bool partial_sort(int(& a)[8], size_t part_size){
    size_t size = sizeof(a)/sizeof(a[0]);
    if(part_size > size)
        return false;
    std::sort(std::begin(a), std::end(a) - part_size);
    return true;
}

int main() {
    int sequence[8] = {8,7,6,5,4,3,2,1};
    std::cout << "Initial number sequence:\n";
    print_sequence(sequence);

size_t input_part = 0;
std::cout << "Input how many numbers in sequence you need to sort:\n";
std::cin >> input_part;

if(!partial_sort(sequence, input_part)) {
    std::cout << "Sorting error!\n";
    return 0;
}

std::cout << "Sorting result:\n";
print_sequence(sequence);
return 0;
}