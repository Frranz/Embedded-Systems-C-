#include "../include/Printf.h"

#include <cstdarg>
#include <string>

#define MAX_INT_AS_STRING_LENGTH 10
#define MAX_INT_AS_HEXSTRING_LENGTH 8
#define MAX_INT_AS_BINARYSTRING_LENGTH 32

char* intToBaseString(int num, int base, char* c, char* cEnd) {
    *cEnd = '\0';
    unsigned int remainder;

    unsigned int numUns = static_cast<unsigned int>(num);

    if(numUns == 0) {
        cEnd--;
        *cEnd = '0';
        return cEnd;
    }

    while(numUns != 0 && c < cEnd) {
        cEnd--;
        remainder = numUns % base;
        numUns = numUns / base;

        if(remainder <= 9) {
            *cEnd = '0' + remainder;
        } else {
            *cEnd = 'a' + remainder - 10; // 10 lower a is 10
        }
    }

    return cEnd;
}

char* Printf(char* dst, const void* end, const char* fmt...) {
    if(dst == nullptr || end == nullptr || fmt == nullptr || dst >= end) {
        return nullptr;
    }

    char* startBuff = dst;
    bool lastWasPercent = false;
    va_list args;
    va_start(args, fmt);

    char conversionBuffer[MAX_INT_AS_BINARYSTRING_LENGTH];

    while(dst < end && *fmt != '\0') {
        if(*fmt == '%') {
            if(lastWasPercent) {
                *dst = '%';
                dst++;
                lastWasPercent = false;
            } else {
                lastWasPercent = true;
            }
        } else {
            if(lastWasPercent) {
                switch(*fmt) {
                    case 'd':
                    case 'u':
                        {
                            int i = va_arg(args, int);
                            std::string s = std::to_string(i);

                            int loopCounter = 0;
                            while(s[loopCounter] != '\0' && dst < end && loopCounter < MAX_INT_AS_STRING_LENGTH) {
                                *dst = s[loopCounter];
                                dst++;
                                loopCounter++;
                            }
                            break;
                        }
                    case 'c':
                        {
                            int i = va_arg(args, int);
                            *dst = static_cast<char>(i); // char is promoted to int when passed
                            dst++;
                            break;
                        }
                    case 's':
                        {
                            char* stringHelper = va_arg(args, char*);

                            int loopCounter = 0;
                            while(stringHelper[loopCounter] != '\0' && dst < end) {
                                *dst = stringHelper[loopCounter];
                                dst++;
                                loopCounter++;
                            }
                            break;
                        }
                    case 'x':
                        {
                            // add 0x to string
                            *dst = '0';
                            dst++;
                            if(dst < end) {
                                *dst = 'x';
                                dst++;
                            } else {
                                //end is reached. can't break out of here, but will fail at while condition
                                continue;
                            }

                            int i = va_arg(args, int);

                            char* stringHelper = intToBaseString(i, 16, conversionBuffer, conversionBuffer + MAX_INT_AS_BINARYSTRING_LENGTH -1);

                            int loopCounter = 0;
                            while(stringHelper[loopCounter] != '\0' && dst < end && loopCounter < MAX_INT_AS_HEXSTRING_LENGTH) { //hier vielleicht lieber prüfen, das string helper nicht über ende von conversion buffer hinaus l#uft
                                *dst = stringHelper[loopCounter];
                                dst++;
                                loopCounter++;
                            }

                            break;
                        }
                    case 'b':
                        {
                            // add 0b to string
                            *dst = '0';
                            dst++;
                            if(dst < end) {
                                *dst = 'b';
                                dst++;
                            } else {
                                //end is reached. can't break out of switch/case, but will fail at while condition
                                continue;
                            }

                            int i = va_arg(args, int);
                            char* stringHelper = intToBaseString(i, 2, conversionBuffer, conversionBuffer + MAX_INT_AS_BINARYSTRING_LENGTH -1);

                            int loopCounter = 0;
                            while(stringHelper[loopCounter] != '\0' && dst < end && loopCounter < MAX_INT_AS_BINARYSTRING_LENGTH) {
                                *dst = stringHelper[loopCounter];
                                dst++;
                                loopCounter++;
                            }
                            break;
                        }
                    default:
                        // return nullptr if unspecified %{character}
                        return nullptr;
                }
                lastWasPercent = false;
            } else {
                *dst = *fmt;
                dst++;
            }
        }

        fmt++;
    }

    //terminate string
    *dst = '\0';

    va_end(args);
    return startBuff;
}
