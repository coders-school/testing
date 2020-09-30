<!-- .slide: data-background="#111111" -->

# Dependency injection

___
<!-- .slide: style="font-size: 0.9em" -->

## Problem #1 - network connections

How to test a function that sends data over the network?

```cpp
size_t send(int socket, const void *buffer, size_t length, int flags);
```

* <!-- .element: class="fragment fade-in" --> What if the socket won't be open?
* <!-- .element: class="fragment fade-in" --> What if the flags are set incorrectly?
* <!-- .element: class="fragment fade-in" --> What if the connection has not been established?
* <!-- .element: class="fragment fade-in" --> What if the connection is lost before sending the data?
* <!-- .element: class="fragment fade-in" --> What if the connection is lost while sending data?
* <!-- .element: class="fragment fade-in" --> What if our network buffers are clogged and we don't get information about the number of bytes sent?
* <!-- .element: class="fragment fade-in" --> What if the link delays (lags) are very high?
* <!-- .element: class="fragment fade-in" --> What if we run the tests concurrently and try to make 1000 connections at once?

You can find some answers in the send function manual - `man 2 send`.
<!-- .element: class="fragment fade-in" -->

Network and distributed programming requires testing many untypical scenarios from the point of view of ordinary programming.
<!-- .element: class="fragment fade-in" -->

___

## Problem #2 - database

How do I test a function that queries the database?

```cpp
Response sendQuery(Query q);
```

* <!-- .element: class="fragment fade-in" --> What happens if the database server is inactive?
  * <!-- .element: class="fragment fade-in" --> There will be no connection to the database server. The test will not pass. You must ensure that the server is always active before running the tests.
* <!-- .element: class="fragment fade-in" --> What if the database server is on a different machine?
  * <!-- .element: class="fragment fade-in" --> We may not be connected to the database server. The test will not pass. You must ensure to always be connected to the server.
* <!-- .element: class="fragment fade-in" --> What happens if the database server is busy?
  * <!-- .element: class="fragment fade-in" --> Reply will be returned after a long time. Tests will take a long time to complete or fail due to long waiting times.
* <!-- .element: class="fragment fade-in" --> What if the database stores terabytes of data?
  * <!-- .element: class="fragment fade-in" --> Searching for data may take too long. Tests may fail.

___

## Problem #3 - function with timeout

How do I test a function that waits for a remote procedure to execute for a specified period of time and then reports an error?

```cpp
template <typename T>
Response executeRemotely(IpAddr address, T function, Timeout timeout);
```

* <!-- .element: class="fragment fade-in" --> Is a unit test that takes 2 minutes good?
  * <!-- .element: class="fragment fade-in" --> It is not. UTs should give the programmer a virtually immediate response. Other types of tests (system, integration) may take correspondingly longer.
* <!-- .element: class="fragment fade-in" --> What will happen if we set timeout to 0?
  * <!-- .element: class="fragment fade-in" --> The function will end immediately or will it wait forever and the tests will crash?
* <!-- .element: class="fragment fade-in" --> Will it be okay to change the timeout to 1ms for the test?
  * <!-- .element: class="fragment fade-in" --> What if the machine is overloaded and the test lasts 2ms? Should the test be reported as FAILED?

___
<!-- .slide: style="font-size: 0.85em" -->

## Cutting off and changing dependencies

In order to conduct effective tests for these problems, it is necessary to cut off all dependence on time, databases or network operations.
<!-- .element: class="fragment fade-in" -->

These types of operations should be closed into separate classes, which we will replace during testing with something that will not cause problems. For example, we can use special versions of the above-mentioned functions.
<!-- .element: class="fragment fade-in" -->

```cpp
size_t send(int socket, const void *buffer, size_t length, int flags) {
    return 10;
}

Response sendQuery(Request r) {
    return Response{r};
}

template <typename T>
Response executeRemotely(IpAddr address, T function, Timeout timeout) {
    if (timeout == 0) {
        throw RemoteExecutionTimeout{};
    } else {
        return Response{};
    }
}
```
<!-- .element: class="fragment fade-in" -->

___

## Dependency injection

The technique in which we put our own implementations into tests instead of actual objects to get rid of problems or simplify tests is called **dependency injection**.
<!-- .element: class="fragment fade-in" -->

There are several different types of it, but the most common is the use of dynamic polymorphism to replace dependencies. Using interfaces, you can substitute any other objects that implement a given interface (in C++ they inherit from this interface).
<!-- .element: class="fragment fade-in" -->

___

## We are testing the Player class

```cpp
class Player {
    std::vector<std::shared_ptr<Weapon>> weapons_;
    Weapon& currentWeapon_;
    // ...
public:
    Player(const std::shared_ptr<Weapon> & defaultWeapon)
        : weapons_.emplace_back(defaultWeapon)
        , currentWeapon_(*defaultWeapon)
    {}
    void shoot() { currentWeapon_.shoot(); }
    void reload() { currentWeapon_.reload(); }
    // ...
};

class Weapon {
public:
    virtual void shoot() = 0;
    virtual void reload() = 0;
    virtual ~Weapon() = default;
};

class Machinegun : public Weapon {
    static size_t capacity_ = 40;
    size_t bullets_ = 40;
public:
    void shoot() override { --bullets_; }
    void reload() override { bullets_ = 40; };
};

```

___

### Use of the Player class in your code

```cpp
auto ak47 = std::make_shared<Machinegun>();
Player grzesiek{ak47};
grzesiek.shoot();
// shoot 40 times
grzesiek.reload();
// no possibility to check if mp5 has shoot, no such interface
```

___
<!-- .slide: style="font-size: 0.8em" -->

### Use in tests

We test the `Player` class, we cut the dependence - `Machinegun`. `Machinegun` class is not possible to check whether we have shot or not, because its interface does not allow checking the magazine capacity.
<!-- .element: class="fragment fade-in" -->

```cpp
class TestWeapon : public Weapon {
public:
    void shoot() override { hasShoot = true; }
    void reload() override { hasShoot = false; }
    bool hasShoot = false;
};
```
<!-- .element: class="fragment fade-in" -->

`TestWeapon` class has a public field indicating if a weapon fired. It inherits from the interface `Weapon` so we can use it instead of a real weapon in tests.
<!-- .element: class="fragment fade-in" -->

```cpp
TEST(PlayerTest, shootingAndReloadingWeapon) {
    auto testWeapon = std::make_shared<TestWeapon>;
    Player testPayer{testWeapon};
    EXPECT_FALSE(testWeapon.hasShoot);
    testPlayer.shoot();
    EXPECT_TRUE(testWeapon.hasShoot);
    testPlayer.reload();
    EXPECT_FALSE(testWeapon.hasShoot);
}
```
<!-- .element: class="fragment fade-in" -->

If `Player` class uses `Weapon` class correctly, the test should pass.
<!-- .element: class="fragment fade-in" -->

___

## Dependency injection using interfaces

Dependency injection simplifies your test code. For example, we don't need to call a method `shoot()` 40 times to unload the magazine. If class `Machinegun` needed in constructor object of `Magazine` class and class `Magazine` 40 objects of `Bullet` class, you would have to create them in tests as well.
<!-- .element: class="fragment fade-in" -->

Writing your own `TestWeapon` class is also an overhead, but dependency injection frameworks allow us to do it in one line of code.
<!-- .element: class="fragment fade-in" -->

___

## What to cut?

In **unit tests** everything except the tested class.
<!-- .element: class="fragment fade-in" -->

In **module tests** everything except the tested module (several or a dozen classes implementing one bigger functionality).
<!-- .element: class="fragment fade-in" -->

In **system tests** external systems - databases, network, time dependencies. We test the operation of the entire system.
<!-- .element: class="fragment fade-in" -->

In **integration tests** nothing. We test the system's interaction with real dependencies.
<!-- .element: class="fragment fade-in" -->

___

## Other techniques

* <!-- .element: class="fragment fade-in" --> split backend - injecting dependencies by linking with another implementation. For this purpose, the build system (Makefile, CMakeLists.txt) must be properly configured to compile and link with the replaced implementations when building tests.
* <!-- .element: class="fragment fade-in" --> split header - dependency injection by including other header files for testing.
* <!-- .element: class="fragment fade-in" --> injecting via setters - not very elegant, especially when we need to write a setter especially for testing.
