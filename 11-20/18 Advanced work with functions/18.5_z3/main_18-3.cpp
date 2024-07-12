// Задание 18.5.3

#include<iostream>

void evendigits(long long, int&);


int main() {
    int ans = 0;
    long long n = 9223372036854775806;

    evendigits(n, ans);

    std::cout << std::endl << "ans = " << ans << std::endl;

    return 0;
}

void evendigits(long long inN, int& inB) {

    if((inN / 10) != 0) {
        if((inN % 10) % 2 == 0) {
            inB++;
        }
        evendigits((inN / 10), inB);
    }
}
