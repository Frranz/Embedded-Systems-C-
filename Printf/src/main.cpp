#include "../include/Printf.h"

int main() {
    char printHere[TeststringLength];
    char* formattedString = Printf(printHere, printHere + TeststringLength, "int: %d\nunsginedint: %u\ncharacter: %c\nstring: %s\nhexaminus: %x\nhexaplus: %x\nbinaryminus: %b\nbinaryplus: %b\nprozentzeichen: %%\n", -74, 3, 'e', "ripx", -3064, 4603,-37, 37);
    std::cout << formattedString;

    return 0;
}
