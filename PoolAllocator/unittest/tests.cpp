#include "catch.hpp"
#include "../include/PoolAllocator.h"

TEST_CASE("size smaller than blocksize returns nullptr") {
    CREATE(testAlloc, 2, 4);

    REQUIRE(testAlloc.Allocate(5) == nullptr);
}

TEST_CASE("can only allocate blockCount amount of blocks") {
    SECTION("only with allocations") {
        CREATE(testAlloc, 2, 4);

        testAlloc.Allocate(4);
        testAlloc.Allocate(4);
        REQUIRE(testAlloc.Allocate(4) == nullptr);
    }

    SECTION("only with allocations and then only deallocations") {
        CREATE(testAlloc, 2, 4);

        void* testPtr1 = testAlloc.Allocate(4);
        void* testPtr2 = testAlloc.Allocate(4);
        REQUIRE(testAlloc.Allocate(4) == nullptr);
        testAlloc.Deallocate(testPtr1);
        testAlloc.Deallocate(testPtr2);
        
        testAlloc.Allocate(4);
        testAlloc.Allocate(4);
        REQUIRE(testAlloc.Allocate(4) == nullptr);

    }
}

TEST_CASE("deallocate doesnt crash program") {
    CREATE(testAlloc, 2, 8);
    REQUIRE(testAlloc.Deallocate(nullptr));
}

TEST_CASE("deallocate doesnt clear data outside of its array") {
    CREATE(testAlloc, 2, 8);
    unsigned int test = 27;
    testAlloc.Deallocate(static_cast<void*>(&test));
    REQUIRE(test == 27);
}