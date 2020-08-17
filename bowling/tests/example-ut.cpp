#include "catch.hpp"

#include "example.hpp"

TEST_CASE("Function returns values increased by 2", "[testRet]")
{
    REQUIRE(testRet(3) == 5);
    REQUIRE(testRet(5) == 7);
    REQUIRE(testRet(11) == 13);
    REQUIRE(testRet(4) == 6);
    REQUIRE(testRet(55) == 57);
}
