#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"

using framesAndResult = std::pair<std::string,std::pair<size_t, std::string>>;

SCENARIO( "Counting bowling points for 10 frames with the same results - for different ways of counting",  "[string][couting][sameFrames]") {

    GIVEN( "String with scores and expected results" ) {
	    
	    auto j = GENERATE( framesAndResult{"X|X|X|X|X|X|X|X|X|X||XX", {300,'ok'}},
			       framesAndResult{"5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5", {150,'ok'}},
			       framesAndResult{"9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||", {90,'ok'}},
			       framesAndResult{"52|52|52|52|52|52|52|52|52|52||", {70,'ok'}})
	    
        WHEN( "returnResult() function called for " << j.first ) {
	    auto points = j.first;
            auto result  = returnResult(points);  
                                                   
            THEN( "results should be " << j.second.first ) {
                auto expected = j.second;
                REQUIRE(result == expected);
            }
        }
    }
}

SCENARIO( "Counting bowling points for 10 frames - mixed 2 ways of counting points",  "[string][couting][2waysOfCounting]") {

    GIVEN( "String with scores and expected results" ) {

            auto j = GENERATE( framesAndResult{"X|X|6/|X|X|7/|9/|X|X|9/||X", {221,'ok'}},
                               framesAndResult{"9/|5/|53|7/|5/|5/|81|6/|8/|71||", {138,'ok'}},
                               framesAndResult{"9-|X|63|X|X|9-|53|X|71|X||81", {147,'ok'}})

        WHEN( "returnResult() function called for " << j.first ) {
            auto points = j.first;
            auto result  = returnResult(points);  
                                                   
            THEN( "results should be " << j.second.first ) {
                auto expected = j.second;
                REQUIRE(result == expected);
            }
        }
    }
}

SCENARIO( "Counting bowling points for 10 frames - mixed ways of counting points",  "[string][couting][mixedWayOfCounting]") {

    GIVEN( "String with scores and expected results" ) {
            auto j = GENERATE( framesAndResult{"26|X|5/|X|72|5/|X|6/|34|8/||9", {155,"ok"}},
                               framesAndResult{"3-|4-|X|6/|6-|8/|62|9/|72|X||XX", {129,"ok"}},
			                   framesAndResult{"8/|7/|6/|X|8-|1/|X|71|8/|23||", {142,"ok"}},
                               framesAndResult{"X|53|4/|9/|25|7/|9-|X|53|7/||X", {138,"ok"}},
                               framesAndResult{"--|4/|71|X|45|8-|X|9-|54|32||", {103,"ok"}})
            
        WHEN( "returnResult() function called for " << j.first ) {
            auto points = j.first;
            auto result  = returnResult(points);  
                                                   
            THEN( "results should be " << j.second.first ) {
                auto expected = j.second;
                REQUIRE(result == expected);
	        }
        }
    }
}

SCENARIO( "Counting bowling points for unfinished game",  "[string][couting][unfinished-game]") {

    GIVEN( "String with scores and expected results" ) {
            auto j = GENERATE( framesAndResult{"X|15|3/|45|22|", {49,"ok"}},
                               framesAndResult{"71|4/|--|5/|", {28,"ok"}},
                               framesAndResult{"8/|1-|", {12,"ok"}},
                               framesAndResult{"X|X|X|", {60, "ok"}},
            
        WHEN( "returnResult() function called for " << j.first ) {
            auto points = j.first;
            auto result  = returnResult(points);  
                                                   
            THEN( "results should be " << j.second.first ) {
                auto expected = j.second;
                REQUIRE(result == expected);
            }
        }
    }
}

SCENARIO( "Counting bowling points with zero points",  "[string][couting][zero]") {

    GIVEN( "String with scores and expected results" ) {
            auto j = GENERATE( framesAndResult{"--|--|--|--|--|--|--|--|--|X||XX", {30,"ok"}},
                               framesAndResult{"--|--|--|--|--|--|--|--|--|X||11", {12,"ok"}},
                               framesAndResult{"--|--|--|--|--|--|--|--|--|--||", {0,"ok"}},
                               framesAndResult{"--|--|--|--|", {0,"ok"}},
                               framesAndResult{"--|", {0,"ok"}},
            
        WHEN( "returnResult() function called for " << j.first ) {
            auto points = j.first;
            auto result  = returnResult(points);  
                                                   
            THEN( "results should be " << j.second.first ) {
                auto expected = j.second;
                REQUIRE(result == expected);
            }
        }
    }
}

