#include <iostream>
#include <cstdlib>
#include "Array.hpp"

int main() {
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    Array<char> alphabet(26);

    for (int i = 0; i < 26; i++) {
        alphabet[i] = a[i];
    }

    // compare alphabets in a and in Array
    std::cout << std::endl;
    std::cout << a << std::endl;
    for (int i = 0; i < 26; i++) {
        std::cout << alphabet[i];
    }
    std::cout << std::endl;

    alphabet[0] = 'A';
    for (int i = 0; i < 26; i++) {
        std::cout << alphabet[i];
    }
    std::cout << std::endl;

    // change something in Array
    std::cout << std::endl;
    try
    {
        alphabet[-1] = 'A';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error:" << e.what() << '\n';
    }

    // Not valid index exeption
    try
    {
        alphabet[26] = 'A';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error:" << e.what() << '\n';
    }

    std::cout << std::endl;
    return 0;
}