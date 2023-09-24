#include "catch_amalgamated.hpp"

SCENARIO("All game strikes") //1
{
    GIVEN("X|X|X|X|X|X|X|X|X|X||XX")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 300 points") {}
        }
    }
}

SCENARIO("Miss all turns") //2
{
    GIVEN("-|-|-|-|-|-|-|-|-|-|")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 0 points") {}
        }
    }
}

SCENARIO("All game first shoot with 1 and second Spare") //3
{
    GIVEN("1/|1/|1/|1/|1/|1/|1/|1/|1/|1/||")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 109 points") {}
        }
    }
}

SCENARIO("One shoot score") //4
{
    GIVEN("-|-|-|-|-|-|-|-|-|-1|")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 1 points") {}
        }
    }
}

SCENARIO("More than 10 turns") //5
{
    GIVEN("13 turns")
    {
        WHEN("calculate Point")
        {
            THEN("Error::More than 10 turns") {}
        }
    }
}

SCENARIO("Less than 10 turns") //6
{
    GIVEN("7 turns")
    {
        WHEN("calculate Point")
        {
            THEN("Error::Less than 10 turns") {}
        }
    }
}

SCENARIO("First score then miss") //7
{
    GIVEN("1-|2-|3-|4-|5-|6-|7-|8-|9-|X||12")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 56") {}
        }
    }
}

SCENARIO("First miss then score") //8
{
    GIVEN("-X|-9|-8|-7|-6|-5|-4|-3|-2|-1||")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 64") {}
        }
    }
}

SCENARIO("Last shoot strike") //9
{
    GIVEN("-|-|-|-|-|-|-|-|-|X||XX")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 30") {}
        }
    }
}

SCENARIO("Lukasz example") //10
{
    GIVEN("X|7/|9-|X|-8|8/|-6|X|X|X||81")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 167") {}
        }
    }
}

SCENARIO("Ball is not given to player") //11
{
    GIVEN("No ball throwing")
    {
        WHEN("calculate Point")
        {
            THEN("Error::No Ball") {}
        }
    }
}

SCENARIO("First 5 shoot spare than 5 shoot strike") //12
{
    GIVEN("1/|2/|3/|4/|5/|X|X|X|X|X||XX")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 238") {}
        }
    }
}

SCENARIO("First 5 shoot strike than 5 shoot spare") //13
{
    GIVEN("X|X|X|X|X|5/|4/|3/|2/|1/||")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 210") {}
        }
    }
}

SCENARIO("Mix shoot") //14
{
    GIVEN("X|23|4/|1-|-6|5/|X|12|21|0/||")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 91") {}
        }
    }
}

SCENARIO("mix Shoot") //15
{
    GIVEN("4/|71|X|-4|7-|-|27|X|7|X||43")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 114") {}
        }
    }
}

SCENARIO("No bowling throw") //16
{
    GIVEN("No bowling")
    {
        WHEN("calculate Point")
        {
            THEN("error::no Bowling") {}
        }
    }
}

SCENARIO("MIX shoot") //17
{
    GIVEN("16|8-|2/|-4|X|X|-|9-|4/|X||55")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 128") {}
        }
    }
}

SCENARIO("MIX SHOOT") //18
{
    GIVEN("X|2/|5-|32|6-|X|63|-8|X|6/||")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 141") {}
        }
    }
}

SCENARIO("First miss then Spare") //19
{
    GIVEN("-/|-/|-/|-/|-/|-/|-/|-/|-/|-/||")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 100") {}
        }
    }
}

SCENARIO("mix shoot") //20
{
    GIVEN("-/|45|X|8-|X|X|72|35|2/|X||3X")
    {
        WHEN("calculate Point")
        {
            THEN("Result is 181") {}
        }
    }
}

