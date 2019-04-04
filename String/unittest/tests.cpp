#include "catch.hpp"
#include <cstring>
#include "../include/PreAllocString.h"
#include "../include/Printf.h"

TEST_CASE("Test implemented Operators") {
    SECTION("testing =operator with char") {
        PreAllocString<11> myPreAllocString;
        char myChar = 'a';
        myPreAllocString = myChar;

        REQUIRE(myPreAllocString[0] == 'a');
        REQUIRE(myPreAllocString[1] == '\0');
    }

    SECTION("testing =operator with const char*") {
        PreAllocString<11> myPreAllocString;
        char myChar = 'z';
        const char* myConstCharPointer = &myChar;
        myPreAllocString = myChar;

        REQUIRE(myPreAllocString[0] == 'z');
        REQUIRE(myPreAllocString[1] == '\0');
    }

    SECTION("testing =operator with char* const") {
        /*
        dont know how to tes for char* const, because static cast throws warning, that fails compilation because -Werror

        PreAllocString<11> myPreAllocString;
        char myChar = 'w';
        const char* myConstCharPointer = static_cast<char* const>(myChar);
        myPreAllocString = myChar;

        REQUIRE(myPreAllocString[0] == 'z');
        REQUIRE(myPreAllocString[1] == '\0');*/
    }

    SECTION("testing += operator with char") {
        PreAllocString<11> myPreAllocString;
        myPreAllocString = 't';
        myPreAllocString += 'e';
        myPreAllocString += 's';
        myPreAllocString += 't';

        REQUIRE(myPreAllocString[0] == 't');
        REQUIRE(myPreAllocString[1] == 'e');
        REQUIRE(myPreAllocString[2] == 's');
        REQUIRE(myPreAllocString[3] == 't');
        REQUIRE(myPreAllocString[4] == '\0');
    }
}
