
#include "catch_amalgamated.hpp"

#include <vector>
#include <algorithm>
#include <string>
#include <functional>

SCENARIO("Bowling scenario #0") 
{
    GIVEN("A game of all misses")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 0")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #1") 
{
    GIVEN("A game of all hits")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 300")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #2") 
{
    GIVEN("hit 9 in first throw and nothing in second in every frame")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 90")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #3") 
{
    GIVEN("hit 5 and spare in every frame")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 150")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #4") 
{
    GIVEN("hit hit 9 and spare in every frame")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 190")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #5") 
{
    GIVEN("X|7/|9-|X|-8|8/|-6|X|X|X||81")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 167")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #6") 
{
    GIVEN("3/|9-|X|X|6-|8/|3-|6/|13|7-|")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 111")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #7") 
{
    GIVEN("Hit 3 in first and nothing in second throw in every frame")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 30")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #8") 
{
    GIVEN("4-|4-|4-|4-|4-|4-|4-|4-|4-|4-|")
    {
        WHEN("calculatePoints is called")
        {
            THEN("the result is 40")
            {
            }
        }
    }
}

SCENARIO("Bowling scenario #9") 
{
    GIVEN("6-|6-|6-|6-|6-|6-|6-|6-|6-|6-|")
    {
        WHEN("sort is called")
        {
            THEN("result is 60")
            {                
            }
        }
    }
}

SCENARIO("Bowling scenario #10") 
{
    GIVEN("8-|8-|8-|8-|8-|8-|8-|8-|8-|8-|")
    {
        WHEN("sort is called")
        {
            THEN("result is 80")
            {                
            }
        }
    }
}

SCENARIO("Bowling scenario #11") 
{
    GIVEN("7-|7-|7-|7-|7-|7-|7-|7-|7-|7-|")
    {
        WHEN("sort is called")
        {
            THEN("result is 70")
            {                
            }
        }
    }
}
SCENARIO("Bowling scenario #12") 
{
    GIVEN("1-|1-|1-|1-|1-|1-|1-|1-|1-|1-|")
    {
        WHEN("sort is called")
        {
            THEN("result is 10")
            {                
            }
        }
    }
}
SCENARIO("Bowling scenario #13") 
{
    GIVEN("2-|2-|2-|2-|2-|2-|2-|2-|2-|2-|")
    {
        WHEN("sort is called")
        {
            THEN("result is 20")
            {                
            }
        }
    }
}

SCENARIO("Bowling scenario #14") 
{
    GIVEN("5-|5-|5-|5-|5-|5-|5-|5-|5-|5-|")
    {
        WHEN("sort is called")
        {
            THEN("result is 50")
            {                
            }
        }
    }
}

SCENARIO("Bowling scenario #15") 
{
    GIVEN("-/|-/|-/|-/|-/|-/|-/|-/|-/|-/||X")
    {
        WHEN("sort is called")
        {
            THEN("result is 110")
            {                
            }
        }
    }
}

SCENARIO("Bowling scenario #16") 
{
    GIVEN("-/|-/|-/|-/|-/|-/|-/|-/|-/|-/||-")
    {
        WHEN("sort is called")
        {
            THEN("result is 100")
            {                
            }
        }
    }
}

SCENARIO("Bowling scenario #17") 
{
    GIVEN("X|X|X|X|X|X|X|X|X|X||--")
    {
        WHEN("sort is called")
        {
            THEN("result is 100")
            {                
            }
        }
    }
}

SCENARIO("Bowling scenario #18") 
{
    GIVEN("X|X|-|-|-|-|-|-|-|-| strike on first two shots")
    {
        WHEN("sort is called")
        {
            THEN("result is 30")
            {                
            }
        }
    }
}
SCENARIO("Bowling scenario #19") 
{
    GIVEN("1|-|-|-|-|-|-|-|-|-| strike on first two shots")
    {
        WHEN("sort is called")
        {
            THEN("result is 1")
            {                
            }
        }
    }
}