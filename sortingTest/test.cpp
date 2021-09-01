#include "catch_amalgamated.hpp"
#include <algorithm>
#include <string>
#include <vector>

SCENARIO("Testing sort algorithm on 3 elements vector", "[vector][sort]") {
    GIVEN("vector v") {
        auto v = GENERATE(std::vector{1, 2, 3},
                          std::vector{1, 3, 2},
                          std::vector{2, 1, 3},
                          std::vector{2, 3, 1},
                          std::vector{3, 1, 2},
                          std::vector{3, 2, 1});

        WHEN("sort is called on " << v[0] << v[1] << v[2]) {
            std::sort(begin(v), end(v));

            THEN("v is {1, 2, 3}") {
                std::vector expected = {1, 2, 3};
                REQUIRE(v == expected);
            }
        }
    }
}

SCENARIO("Testing sort algorithm with a custom comparator", "[vector][sort][greater]") {
    GIVEN("vector v") {
        auto v = GENERATE(std::vector{1, 2, 3},
                          std::vector{1, 3, 2},
                          std::vector{2, 1, 3},
                          std::vector{2, 3, 1},
                          std::vector{3, 1, 2},
                          std::vector{3, 2, 1});

        WHEN("sort is called with std::greater functor") {
            std::sort(begin(v), end(v), std::greater{});
            // std::sort(begin(v), end(v), [](auto lhs, auto rhs){ return lhs > rhs; });

            THEN("v is {3, 2, 1}") {
                std::vector expected = {3, 2, 1};
                REQUIRE(v == expected);
            }
        }
    }
}

SCENARIO("Testing sort algorithm string", "[string][sort]") {
    GIVEN("A simple string s = textTEXT") {
        std::string s = "textTEXT";

        WHEN("The string is sorted") {
            std::sort(begin(s), end(s));

            THEN("The result is ETTXettx") {
                REQUIRE(s == "ETTXettx");
            }
        }
    }
}