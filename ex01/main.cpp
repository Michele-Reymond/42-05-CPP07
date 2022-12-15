#include <iostream>
#include <cmath>
#include "iter.hpp"

void printInt(int &i) {
    std::cout << i << std::endl;
}

void printUp(char &a) {
    char b = toupper(a);
    std::cout << b << std::endl;
}


int main( void ) {

    int intTab[3] = {1, 2, 3};
    char charTab[3] = {'a', 'b', 'c'};
    char charTabBig[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

    iter(intTab, 3, printInt);
    std::cout << std::endl;
    iter(charTab, 3, printUp);
    std::cout << std::endl;
    iter(&charTabBig[1], 4, printUp);

    return 0;
}