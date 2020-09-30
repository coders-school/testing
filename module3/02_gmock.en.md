<!-- .slide: data-background="#111111" -->

# GMock

___

## GMock - documentation

* [GMock for Dummies](https://github.com/google/googletest/blob/master/googlemock/docs/for_dummies.md)
* [GMock cheatsheet](https://github.com/google/googletest/blob/master/googlemock/docs/cheat_sheet.md)
* [GMock cookbook](https://github.com/google/googletest/blob/master/googlemock/docs/cook_book.md)

___

## Creating mocks

1. Writing from scratch
2. [Using the generator script](https://github.com/google/googletest/tree/master/googlemock/scripts/generator)

___

```cpp
class Foo {
  ...
  virtual ~Foo();
  virtual int GetSize() const = 0;
  virtual string Describe(const char* name) = 0;
  virtual string Describe(int type) = 0;
  virtual bool Process(Bar elem, int count) = 0;
};
```

```cpp
#include "gmock/gmock.h"

class MockFoo : public Foo {
  ...
  MOCK_METHOD(int, GetSize, (), (const, override));
  MOCK_METHOD(string, Describe, (const char* name), (override));
  MOCK_METHOD(string, Describe, (int type), (override));
  MOCK_METHOD(bool, Process, (Bar elem, int count), (override));
};
```
<!-- .element: class="fragment fade-in" -->

___

## Setting expectations

```cpp
MockFoo foo;
// ...
EXPECT_CALL(foo, Describe(5))
      .Times(3)
      .WillRepeatedly(Return("Category 5"));
```
<!-- .element: class="fragment fade-in" -->

We expect that there will be called `Describe` function 3 times on `foo` with parameter `5` and it's going to return `std::string` with the text "Category 5" each time.
<!-- .element: class="fragment fade-in" -->

```cpp
EXPECT_CALL(foo, Process(_, 10))
      .WillOnce(Return(true))
      .WillOnce(Return(false));
```
<!-- .element: class="fragment fade-in" -->

We expect that there will be called `Process` function on `foo` with no matter what the first parameter is and 10 as the second parameter. The first time it returns true, the second time it returns false.
<!-- .element: class="fragment fade-in" -->

[More possibilities in GoogleMock CheatSheet](https://github.com/google/googletest/blob/master/googlemock/docs/cheat_sheet.md#setting-expectations-expectcall)
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.85em" -->

## Mock decorators

### Nice Mock
<!-- .element: class="fragment fade-in" -->

```cpp
NiceMock<MockFoo> nice_foo;      // The type is a subclass of MockFoo.
```
<!-- .element: class="fragment fade-in" -->

Ignores extra functions that have been called in addition to expected functions.
<!-- .element: class="fragment fade-in" -->

### Naggy Mock (Default)
<!-- .element: class="fragment fade-in" -->

```cpp
MockFoo foo;
NaggyMock<MockFoo> naggy_foo;    // The type is a subclass of MockFoo.
```
<!-- .element: class="fragment fade-in" -->

Displays warnings about additional functions that have been called in addition to those expected.
<!-- .element: class="fragment fade-in" -->

### Strict Mock
<!-- .element: class="fragment fade-in" -->

```cpp
StrictMock<MockFoo> strict_foo;  // The type is a subclass of MockFoo.
```
<!-- .element: class="fragment fade-in" -->

Calls to additional functions beyond the expected ones are treated as errors which the test does not pass.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.95em" -->

## Exercises

### [Repo Pizzas](https://github.com/coders-school/pizzas)

0. Correct bugs in the program to make the tests pass
1. Correct the PizzaMock class to be written with a newer version of GMock.
2. Remove the time dependency from the tests with a dummy or a stub.

___
<!-- .slide: style="font-size: 0.85em" -->

### 1. Remove time dependency in tests

#### Where do we become dependent on time?
<!-- .element: class="fragment fade-in" -->

`Pizzeria.cpp:52`
`std::this_thread::sleep_for(pizza->getBakingTime());`
<!-- .element: class="fragment fade-in" -->

#### How can you cut this dependency?
<!-- .element: class="fragment fade-in" -->

You must create an interface from which 2 implementations will inherit.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> The first one will actually call the current function <code>std::this_thread::sleep_for()</code> and will be used in normal binary.
* <!-- .element: class="fragment fade-in" --> The second one will do nothing and will be used in testing.

#### How do I inject these dependencies?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> In the class constructor <code>Pizzeria</code> an additional argument should be added - a pointer/reference to the interface.
* <!-- .element: class="fragment fade-in" --> Class <code>Pizzeria</code> should have a new field - also a pointer/reference to the interface.
* <!-- .element: class="fragment fade-in" --> In place of the former function call <code>std::this_thread::sleep_for()</code> one must call the appropriate function from the interface.
