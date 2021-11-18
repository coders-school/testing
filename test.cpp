// #include <algorithm>
// #include <string>
// #include <vector>
#include "catch.hpp"

// SCENARIO("Sort function sorts elements in vector", "[sort][vector]") {
    // GIVEN("a vector with items {-3, 2, 1}") {
    //     std::vector v{-3, 2, 1};

    //     WHEN("is sorted") {
    //         std::sort(begin(v), end(v));

    //         THEN("the sorted vector is {-3, 1, 2}") {
    //             std::vector expectedV {-3, 1, 2};
    //             REQUIRE(v == expectedV);
    //             REQUIRE(std::is_sorted(cbegin(v), cend(v)));
    //         }
    //     }
    // }

//     GIVEN("a vector") {
//         auto v = GENERATE(std::vector{1, 2, 3},
//                           std::vector{1, 3, 2},
//                           std::vector{2, 1, 3},
//                           std::vector{2, 3, 1},
//                           std::vector{3, 1, 2},
//                           std::vector{3, 2, 1});

//         WHEN("vector " << v[0] << v[1] << v[2] << "is sorted") {
//             std::sort(begin(v), end(v));

//             THEN("the sorted vector is") {
//                 std::vector expectedV {1, 2, 3};
//                 REQUIRE(v == expectedV);
//                 REQUIRE(std::is_sorted(cbegin(v), cend(v)));
//             }
//         }
//     }

//     GIVEN("a vector with items {'C', 'b', 'a'}") {
//         std::vector v{'C', 'b', 'a'};

//         WHEN("is sorted") {
//             std::sort(begin(v), end(v));

//             THEN("the sorted vector is {'C', 'a', 'b'}") {
//                 std::vector expectedV {'C', 'a', 'b'};
//                 REQUIRE(v == expectedV);
//                 REQUIRE(std::is_sorted(cbegin(v), cend(v)));
//             }
//         }
//     }
// }

// SCENARIO("Sort function sorts elements in string", "[sort][string]") {
//     GIVEN("a string \"baC\"") {
//         std::string s{"baC"};

//         WHEN("is sorted") {
//             std::sort(begin(s), end(s));

//             THEN("the sorted string is \"Cab\"") {
//                 std::string expectedString {"Cab"};
//                 REQUIRE(s == expectedString);
//                 REQUIRE(std::is_sorted(cbegin(s), cend(s)));
//             }
//         }
//     }
// }
