#include "catch.hpp"
#include "../include/Printf.h"

TEST_CASE("Creates correct string", "") {

    char* pointerResult;
    char actualString[300];
    char fmt[] = "0d:%d 12d:%d 0u:%u 13u:%u -13u:%u Qc:%c test123s:%s 0x:%x 37x:%x -208957203x:%x 0b:%b 235234b:%b -3489753b:%b prozent:%%";
    char expectedString[] = "0d:0 12d:12 0u:0 13u:13 -13u:-13 Qc:Q test123s:test123 0x:0x0 37x:0x25 -208957203x:0x5f76a8dfc 0b:0b0 235234b:0b010001101010010001101001011 -3489753b:0x4b768ad prozent:%";
    pointerResult = Printf(actualString, actualString + 300, fmt, 0, 12, 0, 13, -13, 'Q', "test123", 0, 37, -208957203, 0, 235234, -3489753);

    REQUIRE(strncmp(pointerResult, expectedString, 170));
}

TEST_CASE("Returns nullptr for not specified %{character}", "") {
    // %z is not specified

    char* pointerResult;
    char actualString[40];
    char fmt[] = "0d:%d 12d:%d %z %d";
    pointerResult = Printf(actualString, actualString + 40, fmt, 0, 12, 4, 3);

    REQUIRE(pointerResult == nullptr);
}
