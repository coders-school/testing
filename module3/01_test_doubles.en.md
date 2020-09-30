<!-- .slide: data-background="#111111" -->

# Test doubles

___

## Types of test doubles

* dummy
* fake
* stub
* spy
* mock

___

## Dummy

* <!-- .element: class="fragment fade-in" --> the simplest test doubles
* <!-- .element: class="fragment fade-in" --> does nothing, empty functions
* <!-- .element: class="fragment fade-in" --> it is only intended to meet function signature requirements and may not be used at all

### Original functions
<!-- .element: class="fragment fade-in" -->

```cpp
double Car::accelerate(int) { /* complicated implementation */ }
void sayHello(std::string name) { std::cout << "Hello " << name << '\n'; }
```
<!-- .element: class="fragment fade-in" -->

### Dummy implementation
<!-- .element: class="fragment fade-in" -->

```cpp
double DummyCar::accelerate(int) { return 0.0; }
void dummyHello(std::string name) {}
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Stub

* <!-- .element: class="fragment fade-in" --> a little more advanced test double
* <!-- .element: class="fragment fade-in" --> it may have logic or minimal implementation
* <!-- .element: class="fragment fade-in" --> returns the values ​​defined by us

### Original function
<!-- .element: class="fragment fade-in" -->

```cpp
double Car::accelerate(int) { /* complicated implementation */ }
void sayHello(std::string name) { std::cout << "Hello " << name << '\n'; }
```
<!-- .element: class="fragment fade-in" -->

### Stub implementation
<!-- .element: class="fragment fade-in" -->

```cpp
double StubCar::accelerate(int value) {
    return value < 0 ? -10.0 : 10.0;
}
void stubHello(std::string name) {
    if (name == "anonymous") {
        throw std::logic_error("anonymous not allowed");
    }
}
```
<!-- .element: class="fragment fade-in" -->

___

## Fake

* <!-- .element: class="fragment fade-in" --> models more complex interactions than a stub
* <!-- .element: class="fragment fade-in" --> in practice in C++ it does not even stand out as a separate entity
* <!-- .element: class="fragment fade-in" --> often fake == stub

Fake objects actually have working implementations, but usually take some shortcut which makes them not suitable for production (an InMemoryTestDatabase is a good example).
<!-- .element: class="fragment fade-in" -->

___

## Mock

* <!-- .element: class="fragment fade-in" --> verifies the behavior of the tested object
* <!-- .element: class="fragment fade-in" --> checks if it called expected functions on the mock in expected way

### Original function
<!-- .element: class="fragment fade-in" -->

```cpp
double Car::accelerate(int) { /* complicated implementation */ }
```
<!-- .element: class="fragment fade-in" -->

### Mock implementation
<!-- .element: class="fragment fade-in" -->

```cpp
class MockCar : public Car {
    MOCK_METHOD(double, accelerate, (int), (override));
};
```
<!-- .element: class="fragment fade-in" -->

Mocks are pre-programmed with expectations which form a specification of the calls they are expected to receive. They can throw an exception if they receive a call they don't expect and are checked during verification to ensure they got all the calls they were expecting.
<!-- .element: class="fragment fade-in" -->

___

### Mocking functions outside of the class

* <!-- .element: class="fragment fade-in" --> Usually stubs or dummy are used
* <!-- .element: class="fragment fade-in" --> GMock can be used, but it is complicating the code

See [GoogleMock CookBook](https://github.com/google/googletest/blob/master/googlemock/docs/cook_book.md#mocking-free-functions)
<!-- .element: class="fragment fade-in" -->

___

## Spy

* <!-- .element: class="fragment fade-in" --> mock, which additionally counts the number of function calls
* <!-- .element: class="fragment fade-in" --> in GMock spy == mock

Spies are stubs that also record some information based on how they were called. One form of this might be an email service that records how many messages it was sent.
<!-- .element: class="fragment fade-in" -->

___

## In brief

* <!-- .element: class="fragment fade-in" --> Dummy
  * Its purpose is to "satisfy the signature."
  * No interactions are performed on it.
* <!-- .element: class="fragment fade-in" --> Stub
  * Minimal implementation for interactions between objects.
  * Void methods are empty.
  * Values ​​returned by members are either type-specific or hard-coded.
* <!-- .element: class="fragment fade-in" --> Fake
  * Includes an implementation of logic that imitates production code, but in the simplest possible way.
* <!-- .element: class="fragment fade-in" --> Mock
  * Verifies behavior by logging whether an interaction has been performed.
* <!-- .element: class="fragment fade-in" --> Spy
  * Verifies behavior by recording the number of interactions performed.

Source: [TDD course part 19](https://dariuszwozniak.net/posts/kurs-tdd-19-mock-stub-fake-spy-dummy)
<!-- .element: class="fragment fade-in" -->

___

## In practice

In C++ we will meet this simplification:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> dummy ~= stub
  * test double without logic
* <!-- .element: class="fragment fade-in" --> stub == fake
  * test double with logic
* <!-- .element: class="fragment fade-in" --> mock == spy
  * test double with action logging

We implement dummy and stub objects ourselves. They are so simple that you don't need any frameworks for them.
<!-- .element: class="fragment fade-in" -->

The GMock library is most often used for mock objects.
<!-- .element: class="fragment fade-in" -->

[See examples of dummy items in the Pizzas repo](https://github.com/coders-school/pizzas/blob/master/test/mocks/PizzaMock.hpp)
<!-- .element: class="fragment fade-in" -->
