#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"


SCENARIO("You get strike every frame") //1
{
    GIVEN("X|X|X|X|X|X|X|X|X|X||XX")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 300 points") {}
        }
    }
}

SCENARIO("You miss every turn")  //2
{
    GIVEN("-|-|-|-|-|-|-|-|-|-|")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 0 points") {}
        }
    }
}


SCENARIO("Spare every turn you always miss first ball") //3
{
    GIVEN("-/|-/|-/|-/|-/|-/|-/|-/|-/|-/||-")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 100 points") {}
        }
    }
}

SCENARIO("You get strike every frame, no bonus ball hit") //4
{
    GIVEN("X|X|X|X|X|X|X|X|X|X||--")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 270 points") {}
        }
    }
}

SCENARIO("No balls avaliable") //5
{
    GIVEN("no balls")
    {
        WHEN("calculatePoints is called")
        {
            THEN("error::NoBall") {} //"+1"
        }
    }
}

SCENARIO("Spare every turn you, extra ball strike") //6
{
    GIVEN("-/|-/|-/|-/|-/|-/|-/|-/|-/|-/||X")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 110 points") {}
        }
    }
}

SCENARIO("Always 5 in first, spare in second, bonus miss") //7
{
    GIVEN("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||-")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 145 points") {}
        }
    }
}

SCENARIO("Always 5 in first, second miss") //8
{
    GIVEN("5-|5-|5-|5-|5-|5-|5-|5-|5-|5-|")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 45 points") {}
        }
    }
}

SCENARIO("Each throw is better, never throw a strike or spare") //9
{
    GIVEN("-|-1|-2|-3|-4|-5|-6|-7|-8|-9|")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 54 points") {}
        }
    }
}

SCENARIO("Each is better, last is spare, bonus miss") //10
{
    GIVEN("-1|-2|-3|-4|-5|-6|-7|-8|-9|-/|-")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 55 points") {}
        }
    }
}

SCENARIO("Too many rounds") //11
{
    GIVEN("11 rounds")
    {
        WHEN("calculatePoints is called")
        {
            THEN("error::TooManyRounds") {}
        }
    }
}

SCENARIO("Not enough rounds") //12
{
    GIVEN("6 rounds")
    {
        WHEN("calculatePoints is called")
        {
            THEN("error::NotEnoughRounds") {}
        }
    }
}

SCENARIO("Always 5 in first, spare in second, bonus strike") //13
{
    GIVEN("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||X")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 155 points") {}
        }
    }
}

SCENARIO("Each is better, bonus is strike") //14
{
    GIVEN("-1|-2|-3|-4|-5|-6|-7|-8|-9|-/||X")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 65 points") {}
        }
    }
}

SCENARIO("All miss, last round strike, bonus miss") //15
{
    GIVEN("-|-|-|-|-|-|-|-|-|X|--")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 10 points") {}
        }
    }
}

SCENARIO("Points out of range ") //16
{
    GIVEN("X|X|X|X|X|X|X|X|X|X||XX")
    {
        WHEN("calculatePoints is called")
        {
            THEN("error::OutOfRange") {}
        }
    }
}

SCENARIO("Never misses and spares and never strikes") //17
{
    GIVEN("11|11|11|11|11|11|11|11|11|11|")
    {
        WHEN("calculatePoints is called")
        {
            THEN("Points = 20") {}
        }
    }
}

SCENARIO("Negative points") //18
{
    GIVEN("X|X|X|X|X|X|X|X|X|X||XX")
    {
        WHEN("calculatePoints is called")
        {
            THEN("error::NegativePoints") {}
        }
    }
}

SCENARIO("One turn miss, one strike, bonus strikes") //19
{
    GIVEN("-|X|-|X|-|X|-|X|-|X||XX")
    {
        WHEN("calculatePoints is called")
        {
            THEN("Points = 70") {}
        }
    }
}

SCENARIO("Each is worse") //20
{
    GIVEN("X|-9|-8|-7|-6|-5|-4|-3|-2|-1|")
    {
        WHEN("calculatePoints is called")
        {
            THEN("result = 64 points") {}
        }
    }
}
