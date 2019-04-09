#include "../include/PreAllocString.h"
#include "../include/Printf.h"

#include <iostream>
#include <stdio.h>

int main() {
    CREATE(peter, 12);
    peter+='a';
    peter+='a';
    peter+='a';
    peter+='a';
    printf("hier ist peter: %s\n", static_cast<const char*>(peter));

    PreAllocString<3> myPreAllocString;
    myPreAllocString += 'e';
    myPreAllocString += 'e';
    myPreAllocString += 'e';
    myPreAllocString += 'e';
    myPreAllocString += 'e';
    myPreAllocString += 'e';
    myPreAllocString += 'e';


    printf("using +=: %s\n", static_cast<const char*>(myPreAllocString));

    PreAllocString<10> myPreAllocString3;
    myPreAllocString3.AddFormat("%s", "1234567890");
    printf("add format: %s\n", static_cast<const char*>(myPreAllocString3));

/*    PreAllocString<11> myNiceString;
    myNiceString = 'a';
    std::cout << myNiceString[0];

    const char* bla = "ha";
    myNiceString = bla;
    printf("string: %s\n", &myNiceString[0]);

/ doesnt compile with because ignored qualifiers
// testing char* const
    char blub = 'n';
    myNiceString = //static_cast<char* const>(&blub);
    printf("string2: %s\n", &myNiceString[0]);
    //printf("mein String: %s\n", myNiceString[0]);/

    myNiceString += 'k';
    printf("string3: %s\n", &myNiceString[0]);

    // testing char const* rhs +=
    char myZ = 'z';
    char const* aNiceLetter = &myZ;
    myNiceString += aNiceLetter;
    printf("string4: %s\n", &myNiceString[0]);

    myNiceString.AddWhiteSpace();
    myNiceString += 'k';
    printf("string5: %s\n", &myNiceString[0]);

    myNiceString.AddFormat("%b kek", 3);
    printf("string5: %s\n", &myNiceString[0]);

    printf("\n\n\n");

    PreAllocString<11> myNiceString3;
    PreAllocString<11> myNiceString2;

    const char* halloString = "Hallo";
    const char* weltString = "Welt";
    myNiceString3 = halloString;
    myNiceString2 = weltString;

    printf("hallo: %s welt: %s", static_cast<const char*>(myNiceString3), static_cast<const char*>(myNiceString2));
*/
    return 0;
}
