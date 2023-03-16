#include "gtest/gtest.h"
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using Data = std::vector<int>;
using SortDataSet = std::tuple<Data, std::function<bool(int, int)>, Data>;

struct SortOnVector : public testing::TestWithParam<SortDataSet> {};

TEST_P(SortOnVector, GivenAVectorWhenSortIsCalledThenVectorIsSorted) {
    // GIVEN
    auto [v, comp, expected] = GetParam();

    // WHEN
    std::sort(v.begin(), v.end(), comp);

    // THEN
    ASSERT_EQ(v, expected);
}

std::vector<int> expectedAscending = {1, 2, 3};
std::vector<int> expectedDescending = {3, 2, 1};

INSTANTIATE_TEST_SUITE_P(ThreeElementsVectorWithLessComp,
                         SortOnVector,
                         testing::Values(std::make_tuple(Data{1, 2, 3}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{1, 3, 2}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{2, 1, 3}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{2, 3, 1}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{3, 1, 2}, std::less<int>{}, expectedAscending),
                                         std::make_tuple(Data{3, 2, 1}, std::less<int>{}, expectedAscending)));

INSTANTIATE_TEST_SUITE_P(ThreeElementsVectorWithGreaterComp,
                         SortOnVector,
                         testing::Values(std::make_tuple(Data{1, 2, 3}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{1, 3, 2}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{2, 1, 3}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{2, 3, 1}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{3, 1, 2}, std::greater<int>{}, expectedDescending),
                                         std::make_tuple(Data{3, 2, 1}, std::greater<int>{}, expectedDescending)));

INSTANTIATE_TEST_SUITE_P(TwoElementsVectorWithLessComp,
                         SortOnVector,
                         testing::Values(std::make_tuple(Data{1, 2}, std::less<int>{}, Data{1, 2}),
                                         std::make_tuple(Data{2, 1}, std::less<int>{}, Data{1, 2})));

TEST(SortOnString, GivenAStringWhenSortIsCalledThenStringIsSorted) {
    // GIVEN
    std::string s = "textTEXT";
    std::string expected = "ETTXettx";

    // WHEN
    std::sort(s.begin(), s.end());

    // THEN
    ASSERT_EQ(s, expected);
}
