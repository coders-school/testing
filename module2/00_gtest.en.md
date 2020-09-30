<!-- .slide: data-background="#111111" -->

# Testing

## Framework `GTest`

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## GTest documentation

* [Repo GTest](https://github.com/google/googletest)
* [Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
* [Advanced Guide](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md)

___
<!-- .slide: style="font-size: 0.75em" -->

## Useful assertions

| Fatal assertion | Nonfatal assertion | Verifies |
| ------------------------------ | ------------------------------ | --------------------- |
| `ASSERT_TRUE(condition);`      | `EXPECT_TRUE(condition);`      | condition is true |
| `ASSERT_FALSE(condition);`     | `EXPECT_FALSE(condition);`     | condition is false |
| `ASSERT_EQ(val1, val2);`       | `EXPECT_EQ(val1, val2);`       | val1 == val2 |
| `ASSERT_NE(val1, val2);`       | `EXPECT_NE(val1, val2);`       | val1! = val2 |
| `ASSERT_LT(val1, val2);`       | `EXPECT_LT(val1, val2);`       | val1 <val2 |
| `ASSERT_LE(val1, val2);`       | `EXPECT_LE(val1, val2);`       | val1 <= val2 |
| `ASSERT_GT(val1, val2);`       | `EXPECT_GT(val1, val2);`       | val1> val2 |
| `ASSERT_GE(val1, val2);`       | `EXPECT_GE(val1, val2);`       | val1> = val2 |
| `ASSERT_THAT(value, matcher);` | `EXPECT_THAT(value, matcher);` | value matches matcher |

___
<!-- .slide: style="font-size: 0.7em" -->

## Assertions with exceptions

| Fatal assertion | Nonfatal assertion | Verifies |
| ------------------------------------------ | ------------------------------------------ | ----------------------------------------------- |
| `ASSERT_THROW(statement, exception_type);` | `EXPECT_THROW(statement, exception_type);` | statement throws an exception of the given type |
| `ASSERT_ANY_THROW(statement);`             | `EXPECT_ANY_THROW(statement);`             | statement throws an exception of any type |
| `ASSERT_NO_THROW(statement);`              | `EXPECT_NO_THROW(statement);`              | statement doesn't throw any exception |

___

## Organization of tests

* <!-- .element: class="fragment fade-in" --> <code>TEST(TestSuiteName, TestName)</code>
* <!-- .element: class="fragment fade-in" --> <code>TEST_F(TestFixtureName, TestName)</code>

___

## Test case - `TEST`

```cpp
TEST(ClassUnderTestSuite, callMeShouldAlwaysReturn42) {
    // GIVEN
    ClassUnderTest cut{};
    auto expected = 42;

    // WHEN
    auto result = cut.callMe();

    // THEN
    ASSERT_EQ(result, expected);
}
```

___

## Tests with shared data - `TEST_F`

```cpp
struct ClassUnderTestFixture : public ::testing::Test {
    // common data and helper functions
    ClassUnderTest cut{};
}

TEST_F(ClassUnderTestFixture, callMeShouldAlwaysReturn42) {
    // GIVEN
    auto expected = 42;

    // WHEN
    auto result = cut.callMe();

    // THEN
    ASSERT_EQ(result, expected);
}
```

___

## Exercise

Test the algorithm `std::sort()`.

In this task, it is important to cover as many scenarios of this algorithm as possible.

___

## Parametric tests - `TEST_P`

We need 3 things:

1. Fixture class, inheriting from `testing::TestWithParam<T>` where T is the type of input that will be provided to the test
2. Test scenario `TEST_P`
3. Generator `INSTANTIATE_TEST_SUITE_P` which will generate test cases

[Link to documentation](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#value-parameterized-tests)

___

### Example

```cpp
class MyFixture : public testing::TestWithParam<std::pair<int, int>> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
  ClassUnderTest cut;
};

TEST_P(MyFixture, MyTestName) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:
  auto [value, expected] = GetParam();
  EXPECT_EQ(cut.myFunction(value), expected);
}

INSTANTIATE_TEST_SUITE_P(MyInstantiationName,
                         MyFixture,
                         testing::Values({1, 1},
                                         {2, 1},
                                         {3, 2}));
```

___

## Generators

Thanks to data generators, one test scenario can be run on different test data.

* <!-- .element: class="fragment fade-in" --> <code>Range(begin, end [, step])</code>
  * Yields values `{begin, begin+step, begin+step+step, ...}`. The values ​​do not include end. step defaults is 1.
* <!-- .element: class="fragment fade-in" --> <code>Values(v1, v2, ..., vN)</code>
  * Yields values `{v1, v2, ..., vN}`.
* <!-- .element: class="fragment fade-in" --> <code>ValuesIn(container)</code>, <code>ValuesIn(begin,end)</code>
  * Yields values ​​from a C-style array, an STL-style container, or an iterator range [begin, end)
* <!-- .element: class="fragment fade-in" --> <code>Bool()</code>
  * Yields sequence `{false, true}`.
* <!-- .element: class="fragment fade-in" --> <code>Combine(g1, g2, ..., gN)</code>
  * Yields all combinations (Cartesian product) as `std::tuples` of the values ​​generated by the N generators.

[Link to documentation](https://github.com/catchorg/Catch2/blob/master/docs/generators.md#top)
<!-- .element: class="fragment fade-in" -->

___

## Additional task

(If there is time or someone is willing)

Complete repo tasks with fan_controller. We will work on it in Testing lesson #3.
In addition to the README.md command, add the same tests in the GTest framework.

[Repo fan_controller](http://github.com/coders-school/fan_controller)
