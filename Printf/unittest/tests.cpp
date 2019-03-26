#include "catch.hpp"
#include "../include/Printf.h"

#include <cstring>

TEST_CASE("Creates correct string", "") {

    SECTION("complex fmt with all specified replacements") {
        char actualString[300];
        char fmt[] = "0d:%d 12d:%d 0u:%u 13u:%u -13d:%d Qc:%c test123s:%s 0x:%x 37x:%x -208957203x:%x 0b:%b 235234b:%b -3489753b:%b prozent:%%";
        char expectedString[] = "0d:0 12d:12 0u:0 13u:13 -13d:-13 Qc:Q test123s:test123 0x:0x0 37x:0x25 -208957203x:0xf38b90ed 0b:0b0 235234b:0b111001011011100010 -3489753b:0b1111111110010101100000000100111 prozent:%";
        char* pointerResult = Printf(actualString, actualString + 300 - 1, fmt, 0, 12, 0, 13, -13, 'Q', "test123", 0, 37, -208957203, 0, 235234, -3489753);

        REQUIRE(strncmp(pointerResult, expectedString, 170) == 0);
    }

    SECTION("creates normal string without replacements") {
        char actualString[300];
        char stringToPrintf[] = "hallo dies ist ein einfacher tests, ob alles ordnungsgemaes kopiert wird";
        char* pointerResult = Printf(actualString, actualString + 300 - 1, stringToPrintf);
        REQUIRE(strncmp(pointerResult, stringToPrintf, 300) == 0);
    }

    SECTION("if string requires more space it stops at end") {
        char actualString[20];
        char* pointerResult = Printf(actualString, actualString + 20 -1, "123456789012345678%d", 395987594);

        REQUIRE(strncmp(pointerResult, "1234567890123456783", 21) == 0);
    }
}

TEST_CASE("Returns nullptr on error") {
    SECTION("unspecified %{character}") {
        // %z is not specified

        char* pointerResult;
        char actualString[40];
        char fmt[] = "0d:%d 12d:%d %z %d";
        pointerResult = Printf(actualString, actualString + 40 - 1, fmt, 0, 12, 4, 3);
        REQUIRE(pointerResult == nullptr);
    }

    SECTION("dst is nullptr") {
        char actualString[40];
        char* pointerResult = Printf(nullptr, actualString + 40 - 1, "%d tes123 %s", 48, "abc");

        REQUIRE(pointerResult == nullptr);
    }

    SECTION("end is nullptr") {
        char actualString[40];
        char* pointerResult = Printf(actualString, nullptr, "%d tes123 %s", 48, "abc");

        REQUIRE(pointerResult == nullptr);
    }

    SECTION("fmt is nullptr") {
        char actualString[40];
        char* pointerResult = Printf(actualString, actualString + 40 - 1, nullptr, 48, "abc");

        REQUIRE(pointerResult == nullptr);
    }

    SECTION("dst > end") {
        char actualString[40];
        char* pointerResult = Printf(actualString + 40, actualString, nullptr, 48, "abc");

        REQUIRE(pointerResult == nullptr);
    }
}
