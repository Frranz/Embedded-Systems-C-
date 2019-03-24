#include "../include/Printf.h"

char* Printf(char* dst, const void* end, const char* fmt...) {
    //strncpy(dst, fmt, TeststringLength - 1);
    char* startBuff = dst;
    bool lastWasPercent = false;
    va_list args;
    va_start(args, fmt);

    int i;
    char* stringHelper;
    int loopCounter;
    std::string s;

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
                        i = va_arg(args, int);
                        s = std::to_string(i);

                        loopCounter = 0;
                        while(s[loopCounter] != '\0' && dst < end && loopCounter < MAX_INT_AS_STRING_LENGTH) { // biggest 32bit integer has 10 digits
                            *dst = s[loopCounter];
                            dst++;
                            loopCounter++;
                        }
                        break;
                    case 'c':
                        i = va_arg(args, int);
                        *dst = static_cast<char>(i); // char is promoted to int when passed
                        dst++;
                        break;
                    case 's':
                        stringHelper = va_arg(args, char*);

                        loopCounter = 0;
                        while(stringHelper[loopCounter] != '\0' && dst < end) {
                            *dst = stringHelper[loopCounter];
                            dst++;
                            loopCounter++;
                        }
                        break;
                    case 'x':

                        break;
                    case 'b':
                        break;
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

    return startBuff;
}

int main() {
    printf("turnup hier gehts los\n");
    char printHere[TeststringLength];
    char* formattedString = Printf(printHere, printHere + TeststringLength, "int: %d\nunsginedint: %u\ncharacter: %c\nstring: %s\nhexaminus: %x\nhexaplus: %x\nbinaryminus: %b\nbinaryplus: %b\nprozentzeichen: %%", -74, 3, 'e', "ripx", -3064, 4603,-37, 37);
    std::cout << formattedString;

    return 0;
}

char* intToHexString(int num, char* c, char* cEnd) {
    *cEnd = '\0';
    unsigned int remainder;

    while(num != 0) {
        cEnd--;
        remainder = num % 16;
        num = num / 16;

        *cEnd = 97 + remainder;
    }

    return cEnd;
}
