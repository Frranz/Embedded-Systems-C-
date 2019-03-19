#include "../include/Printf.h"

char* Printf(char* dst, const void* end, const char* fmt, ...) {
    //strncpy(dst, fmt, TeststringLength - 1);
    const char* startBuff = dst;
    bool lastWasPercent = false;
    va_list args;
    va_start(args, fmt);

    while(dst < end && fmt != '\0') {
        if(fmt == '%') {
            if(lastWasPercent) {
                dst = '%';
                lastWasPercent = false;
            } else {
                lastWasPercent = true;
            }
        } else {
            if(lastWasPercent) {
                switch(fmt) {
                    case 'd':
                        int i = va_args(args, int);
                        break;
                    case 'u':
                        break;
                    case 'c':
                        break;
                    case 's':
                        break;
                    case 'x':
                        break;
                    case 'b':
                        break;
                }
            }
        }

        dst++;
        fmt++;
    }

    return startBuff;
}

int main(int argc, char* argv[]) {
    printf("turnup hier gehts los\n");
    char printHere[TeststringLength];
    char* formattedString = Printf(printHere, printHere + TeststringLength, "int: %d\nunsginedint: %u\ncharacter: %c\nstring: %s\n", -74, 3, "e", "ripx");
    printf(formattedString);

    return 0;
}
