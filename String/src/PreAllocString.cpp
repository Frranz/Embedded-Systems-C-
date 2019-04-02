#include "../include/PreAllocString.h"

#include <iostream>
#include <stdio.h>

template<size_t Stringsize>
PreAllocString<Stringsize>::operator const char *() const{
    return myString;
};

template<size_t Stringsize>
PreAllocString<Stringsize>::operator const void *() const{
    return static_cast<const void*>(myString);
};

template<size_t Stringsize>
const char & PreAllocString<Stringsize>::operator [] (const int idx){
    return myString[idx];
}

template<size_t Stringsize>
size_t PreAllocString<Stringsize>::GetLength() const {
    size_t len = 0;

    while(myString[len] != 0 && len < Stringsize) {
        len++;
    }

    return len;
}

template<size_t Stringsize>
PreAllocString<Stringsize>& PreAllocString<Stringsize>::operator=(char rhs) {
    if(Stringsize > 2) {
        myString[0] = rhs;
        myString[1] = '\0';
    }

    return *this;
}

template<size_t Stringsize>
PreAllocString<Stringsize>& PreAllocString<Stringsize>::operator=(const char* rhs) {
    unsigned int i = 0;

    while(rhs[i] != '0' && i < Stringsize - 1) {
        myString[i] = rhs[i];
        i++;
    }

    myString[i] = '\0';

    return *this;
}

int main() {
    PreAllocString<20> myNiceString;
    myNiceString = 'a';
    std::cout << myNiceString[0];

    myNiceString = "kekek123";
    printf("mein String: %s\n", myNiceString[0]);

    return 0;
}
