#include "../include/PoolAllocator.h"
#include <iostream>
int main() {
    CREATE(testAlloc, 20, 4);

    char* str = static_cast<char*>(testAlloc.Allocate(2));

    str[0] = 'h';
    str[1] = 'a';
    str[2] = 'l';
    str[3] = 0;

    std::cout << str;
    
    return 0;
}