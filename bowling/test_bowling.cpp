#include <catch2/catch_test_macros.hpp>


SCENARIO( "Frame number <1; 9>", "[rules][frame][1-9]" ) {

    GIVEN( "(1/2) ball in frame" ) 
    {
        WHEN( "knocked down < 0 pins" )
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        } 
        WHEN( "knocked down < 10 pins" ) 
        {
            THEN( "cannot achive STRIKE, possible to achive SPARE, not possible to add sum of 2 next balls, maximum one possible" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down 10 pins" ) 
        {
            THEN( "frame score has added 10 points + sum of 2 next balls [STRIKE][EndOfFrame]" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down > 10 pins" ) 
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }  
        //more???
    }
    GIVEN( "(2/2) ball in frame" ) 
    {
        WHEN( "knocked down < 0 pins" )
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down more than 10 minus 1st ball knocked down pins" )
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down < 10 pins in last 2 balls" ) 
        {
            THEN( "frame score equals knocked down pins from last 2 balls [EndOfFrame]" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down 10 pins in last 2 balls" ) 
        {
            THEN( "frame score equals 10 + sum of 1st next ball [SPARE][EndOfFrame]" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down > 10 pins" ) 
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }            
        //more???
    }
   
}

SCENARIO( "Frame number 10", "[rules][frame][10]" ) {

    GIVEN( "(1/2) normal ball in frame" ) 
    {
        WHEN( "knocked down < 0 pins" )
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        } 
        WHEN( "knocked down < 10 pins" ) 
        {
            THEN( "cannot achive STRIKE, possible to achive SPARE, not possible to add sum of 2 next balls, maximum one possible" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down 10 pins" ) 
        {
            THEN( "frame score has added 10 points + sum of 2 additional balls in frame (3rd and 4th) [10th frame STRIKE][STRIKE][EndOfFrame]" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down > 10 pins" ) 
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }  
        //more???
    }
    GIVEN( "(2/2) normal ball in frame" ) 
    {
        WHEN( "knocked down < 0 pins" )
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down more than 10 minus 1st ball knocked down pins" )
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down < 10 pins in last 2 balls" ) 
        {
            THEN( "frame score equals knocked down pins from last 2 balls [EndOfFrame]" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down 10 pins in last 2 balls" ) 
        {
            THEN( "frame score equals 10 + score of one additional ball (3rd) [10th frame SPARE][SPARE][EndOfFrame]" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN( "knocked down > 10 pins" ) 
        {
            THEN( "throw exception, unexpected program behavior" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }            
        //more???
    }
    GIVEN( "one additional ball (3rd)" ) 
    {
        THEN( "frame score equals sum of score of last 3 balls [EndOfFrame][EndOfGame]" ) 
        {
            REQUIRE( 1 == 1 );
        }
    }
    GIVEN( "two additional balls (3rd and 4th)" ) 
    {
        WHEN("3rd ball")
        {
            THEN("frame score cannot be lower than 10")
            {
                REQUIRE( 1 == 1 );
            }
            AND_THEN("frame score cannot higher than than 20")
            {
                REQUIRE( 1 == 1 );
            }
        }
        WHEN("4th ball")
        {
            THEN("frame score cannot be lower than 10")
            {
                REQUIRE( 1 == 1 );
            }
            AND_THEN("frame score cannot higher than than 30")
            {
                REQUIRE( 1 == 1 );
            }
            AND_THEN( "frame score equals sum of score of last 4 balls [EndOfFrame][EndOfGame]" ) 
            {
                REQUIRE( 1 == 1 );
            }
        }        
    }
}

SCENARIO( "checks based on empirical data", "[examples]" ) {

    GIVEN("-|-|-|-|-|-|-|-|-|-||") //1
    {
        THEN("score == 0")
        {
            //score == 0
        }
    }
    GIVEN("X|X|X|X|X|X|X|X|X|X||XX") //2
    {
        THEN("score == 300")
        {
            //score == 300
        }
    }
    GIVEN("1-|1-|1-|1-|1-|1-|1-|1-|1-|1-||") //3
    {
        THEN("score == 10")
        {
            //score == 10
        }
    }    
    GIVEN("-1|-1|-1|-1|-1|-1|-1|-1|-1|-1||") //4
    {
        THEN("score == 10")
        {
            //score == 10
        }
    }
    GIVEN("9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||") //5
    {
        THEN("score == 90")
        {
            //score == 90
        }
    }
    GIVEN("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5") //6
    {
        THEN("score == 150")
        {
            //score == 150
        }
    }
    GIVEN("X|5/|X|5/|X|5/|X|5/|X|5/||10") //7
    {
        THEN("score == 225")
        {
            //score == 225
        }
    }
    GIVEN("5/|X|5/|X|5/|X|5/|X|5/|X||00") //8
    {
        THEN("score == 210")
        {
            //score == 210
        }
    }
    GIVEN("X|7/|9-|X|-8|8/|-6|X|X|X||81") //9
    {
        THEN("score == 167")
        {
            //score == 167
        }
    }
    GIVEN("-6|5-|1/|X|-/|X|-5|5-|X|--||") //10
    {
        THEN("score == 96")
        {
            //score == 96
        }
    }
    GIVEN("5-|5-|5-|5-|5-|X|X|X|X|X||00") //11
    {
        THEN("score == 190")
        {
            //score == 190
        }
    }
    GIVEN("X|X|X|X|X|5-|5-|5-|5-|5-||") //12
    {
        THEN("score == 155")
        {
            //score == 155
        }
    }
    GIVEN("9/|9/|9/|9/|9/|9/|9/|9/|9/|9/||9") //13
    {
        THEN("score == 190")
        {
            //score == 190
        }
    }
    GIVEN("X|7/|9-|X|-8|8/|-6|X|X|X||X-") //14
    {
        THEN("score == 177")
        {
            //score == 177
        }
    }
    GIVEN("X|X|X|X|X|X|X|X|X|X||9/") //15
    {
        THEN("score == 298")
        {
            //score == 298
        }
    }
    GIVEN("1-|35|X|9/|-7|X|81|X|X|X||35") //16
    {
        THEN("score == 153")
        {
            //score == 153
        }
    }
    GIVEN("X|-/|X|X|7/|X|X|X|-/|X||X") //17
    {
        THEN("score == 204")
        {
            //score == 204
        }
    }
    GIVEN("X|X|X|X|X|X|X|X|X|X||45") //18
    {
        THEN("score == 283")
        {
            //score == 283
        }
    }
    GIVEN("X|X|X|X|X|X|X|X|X|X||X") //19
    {
        THEN("score == 290")
        {
            //score == 290
        }
    }
    GIVEN("4-|4-|4-|4-|4-|4-|4-|4-|4-|4-||") //20
    {
        THEN("score == 40")
        {
            //score == 40
        }
    }
    GIVEN("X|7/|9-|X|-8|8/|-6|X|X|X||5/") //21
    {
        THEN("score == 172")
        {
            //score == 172
        }
    }
}

// SCENARIO( "total points calculations", "[rules][total points][end]" ) {
//     //TOTAL SCORE CANNOT BE < 0 AND > 300
//     //ANY FRAME SCORE CANNOT >30 
// }
