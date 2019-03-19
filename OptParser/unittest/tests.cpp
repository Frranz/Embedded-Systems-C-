#include "catch.hpp"
#include "../include/OptParser.h"
#include <stdio.h>

TEST_CASE("Arguments are parsed", "[parsing]") {
    CmdLineOptParser parser;

    const char* arg0 = "programname";
    const char* arg1 = "-a";
    const char* arg2 = "-b";
    const char* arg3 = "-c=test";
    const char* arg4 = "-dbla";
    const char* arg5 = "-e";
    const char* arg6 = "ok123";
    char* args[] = {
        const_cast<char*>(arg0),
        const_cast<char*>(arg1),
        const_cast<char*>(arg2),
        const_cast<char*>(arg3),
        const_cast<char*>(arg4),
        const_cast<char*>(arg5),
        const_cast<char*>(arg6)
    };
    REQUIRE(parser.Parse( 7, args) == true);
}

TEST_CASE("False is returned for bad arguments", "[parsing]") {
    CmdLineOptParser parser;

    SECTION("parse returnes false for bad argument values") {
        const char* arg0 = "programname";
        const char* arg1 = "-a";
        const char* arg2 = "-b";
        const char* arg3 = "-c=test";
        const char* arg4 = "-dbla";
        const char* arg5 = "-";
        char* args[] = {
            const_cast<char*>(arg0),
            const_cast<char*>(arg1),
            const_cast<char*>(arg2),
            const_cast<char*>(arg3),
            const_cast<char*>(arg4),
            const_cast<char*>(arg5)
        };
        REQUIRE(parser.Parse( 6, args) == false);
    }

    SECTION("parse returnes false if a char in option is not representable") {
        const char* arg0 = "programname";
        const char* arg1 = "-a";
        const char* arg2 = "-b\r";
        char* args[] = {
            const_cast<char*>(arg0),
            const_cast<char*>(arg1),
            const_cast<char*>(arg2)
        };
        REQUIRE(parser.Parse( 3, args) == false);
    }


}
