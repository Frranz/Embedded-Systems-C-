#include "../include/PreAllocString.h"

#include <iostream>
#include <stdio.h>
#include <cstring>

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

template<size_t Stringsize>
PreAllocString<Stringsize>& PreAllocString<Stringsize>::operator=(char* const rhs) {
    unsigned int i = 0;

    while(rhs[i] != '0' && i < Stringsize - 1) {
        myString[i] = rhs[i];
        i++;
    }

    myString[i] = '\0';

    return *this;
}

template<size_t Stringsize>
PreAllocString<Stringsize>& PreAllocString<Stringsize>::operator+=(char rhs) {
    unsigned int iMyString = static_cast<unsigned int>(GetLength());

    myString[iMyString] = rhs;
    iMyString++;
    myString[iMyString] = '\0';
    return *this;
}

template<size_t Stringsize>
PreAllocString<Stringsize>& PreAllocString<Stringsize>::operator+=(char const * rhs) {
    unsigned int iMyString = static_cast<unsigned int>(GetLength());
    unsigned int jRhs = 0;

    while(iMyString < Stringsize - 1 && rhs[jRhs] != '\0') {
        myString[iMyString] = rhs[jRhs];
        iMyString++;
        jRhs++;
    }

    myString[iMyString] = '\0';
    return *this;
}


int main() {
    PreAllocString<20> myNiceString;
    myNiceString = 'a';
    std::cout << myNiceString[0];

    const char* bla = "hallo ich bins";
    myNiceString = bla;
    printf("string: %s\n", &myNiceString[0]);

// testing char* const
    char blub[] = "na du";
    myNiceString = reinterpret_cast<char* const>(blub);
    printf("string2: %s\n", myNiceString);
    //printf("mein String: %s\n", myNiceString[0]);

    myNiceString += 'k';
    printf("string2: %s\n", myNiceString);


    return 0;
}
