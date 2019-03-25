#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <cstdarg>
#include <cstring>
#include <string>
#include <iostream>

#define TeststringLength 300
#define MAX_INT_AS_STRING_LENGTH 10
#define MAX_INT_AS_HEXSTRING_LENGTH 8
#define MAX_INT_AS_BINARYSTRING_LENGTH 32

#define ASCII_VALUE_ZERO 48
#define ASCII_VALUE_LOWER_A 97

char* intToBaseString(int num, int base, char* c, char* cEnd);
char* Printf(char* dst, const void* end , const char* fmt , ...);

#endif
