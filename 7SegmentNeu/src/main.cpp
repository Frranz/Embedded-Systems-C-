#include "../include/7Segment.h"
#include <stdio.h>

int main() {
    constexpr MultiDigit md{1,2,3,5,6,7,7,6,5,4};
    printf("mein string: \n%s", static_cast<const char*>(md));
    return 0;
}
