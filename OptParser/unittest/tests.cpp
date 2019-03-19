#include "catch.hpp"
#include "../include/OptParser.h"

TEST_CASE("Arguments are parsed", "[]") {
    CmdLineOptParser parser;

    const char* arg1 = "-a";
    const char* arg2 = "-b";
    char* args[] = {const_cast<char*>(arg1), const_cast<char*>(arg2)};
    REQUIRE(parser.Parse( 4, args) == true);
}
