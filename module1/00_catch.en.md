<!-- .slide: data-background="#111111" -->

# Testing

## `Catch2`framework

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Useful assertions

* <!-- .element: class="fragment fade-in" --> <code>REQUIRE( expression )</code>
* <!-- .element: class="fragment fade-in" --> <code>CHECK( expression )</code>
* <!-- .element: class="fragment fade-in" --> <code>REQUIRE_FALSE( expression )</code>
* <!-- .element: class="fragment fade-in" --> <code>CHECK_FALSE( expression )</code>
* <!-- .element: class="fragment fade-in" --> <code>REQUIRE_NOTHROW( expression )</code>
* <!-- .element: class="fragment fade-in" --> <code>CHECK_NOTHROW( expression )</code>
* <!-- .element: class="fragment fade-in" --> <code>REQUIRE_THROWS_AS( expression, exception type )</code>
* <!-- .element: class="fragment fade-in" --> <code>CHECK_THROWS_AS( expression, exception type )</code>
* <!-- .element: class="fragment fade-in" --> <code>REQUIRE_THAT( lhs, matcher expression )</code>
* <!-- .element: class="fragment fade-in" --> <code>CHECK_THAT( lhs, matcher expression )</code>

___

## Useful matchers

* <!-- .element: class="fragment fade-in" --> String matchers
  * <!-- .element: class="fragment fade-in" --> <code>StartsWith</code>
  * <!-- .element: class="fragment fade-in" --> <code>EndsWith</code>
  * <!-- .element: class="fragment fade-in" --> <code>Contains</code>
  * <!-- .element: class="fragment fade-in" --> <code>Equals</code>
  * <!-- .element: class="fragment fade-in" --> <code>Matches</code>
* <!-- .element: class="fragment fade-in" --> Vector matchers
  * <!-- .element: class="fragment fade-in" --> <code>Contains</code> which checks whether a specified vector is present in the result
  * <!-- .element: class="fragment fade-in" --> <code>VectorContains</code> which checks whether a specified element is present in the result
  * <!-- .element: class="fragment fade-in" --> <code>Equals</code> which checks whether the result is exactly equal (order matters) to a specific vector
  * <!-- .element: class="fragment fade-in" --> <code>UnorderedEquals</code> which checks whether the result is equal to a specific vector under a permutation

___

## Exercise

Test the algorithm `std::sort()`.

In this task, it is important to cover as many scenarios of this algorithm as possible.

___

## Organization of tests

* <!-- .element: class="fragment fade-in" --> <code>TEST_CASE( test name [, tags ] )</code>
* <!-- .element: class="fragment fade-in" --> <code>SECTION( section name )</code>

Or
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>SCENARIO( scenario name [, tags ] )</code>
* <!-- .element: class="fragment fade-in" --> <code>GIVEN( something )</code>
* <!-- .element: class="fragment fade-in" --> <code>WHEN( something )</code>
* <!-- .element: class="fragment fade-in" --> <code>THEN( something )</code>

Where `SCENARIO` maps to `TEST_CASE`, while `GIVEN`, `WHEN` and `THEN` on `SECTION`.
<!-- .element: class="fragment fade-in" -->

___

## Generators

Thanks to data generators, one test scenario can be run on different test data.

[Link to documentation](https://github.com/catchorg/Catch2/blob/master/docs/generators.md#top)
