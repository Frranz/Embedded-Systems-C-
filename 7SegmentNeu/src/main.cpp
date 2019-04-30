#include "../include/7Segment.h"
#include <stdio.h>

int main() {
    constexpr MultiDigit md{0};
    const char zeroRepresent[] = " - \n| |\n   \n| |\n - \n";
    printf("mein string: \n%s", static_cast<const char*>(md));

    for(int i = 0; i < 200 && static_cast<const char*>(md)[i] != 0; ++i) {
        printf("Zeichen%d:%c\n", i, static_cast<const char*>(md)[i]);
        printf("Zeicrap%d:%c\n", i, zeroRepresent[i]);
    }
    return 0;
}
