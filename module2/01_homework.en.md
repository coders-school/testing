<!-- .slide: data-background="#111111" -->

# Testing

## Homework

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Questions from job interviews

* <!-- .element: class="fragment fade-in" --> What are unit tests?
* <!-- .element: class="fragment fade-in" --> Are unit tests white-box or black-box tests?
* <!-- .element: class="fragment fade-in" --> What code coverage is appropriate?
* <!-- .element: class="fragment fade-in" --> What tools do you know that calculate code coverage?
* <!-- .element: class="fragment fade-in" --> What frameworks do you know for testing?
* <!-- .element: class="fragment fade-in" --> Which framework do you consider the most interesting and why?
* <!-- .element: class="fragment fade-in" --> How to test the code that causes an exception?
* <!-- .element: class="fragment fade-in" --> How to test the code that is supposed to crash the application?

___

## Pre-work

* Read [GMock for Dummies](https://github.com/google/googletest/blob/master/googlemock/docs/for_dummies.md)
* Please see the tests in the repository [Pizzas](https://github.com/ziobron/Pizzas). There you will find some mocking code `TEST_F(PizzeriaTest, calculatePriceForPizzaMock)` and the file `test/mocks/PizzaMock.hpp`.
* Add your own tests / mocks as you wish

___

## Bowling 🎳 - new project

Watch [Uncle Bob's video about TDD](https://trello-attachments.s3.amazonaws.com/5b20ebcd819b419f2d65c274/5b5d70bf109bc670f6d8d10d/90fb5c9305b6e8092df116da1c845210/fm_CleanCode2-540.mp4).

To understand the scoring of a bowling game, it is helpful to describe the rules. It is attached at the end of the presentation or available [here](https://github.com/coders-school/testing/blob/master/module2/bowling_rules.txt)

In new groups, write an application that will count points in the bowling alley.

___
<!-- .slide: style="font-size: 0.9em" -->

## Bowling 🎳

### Requirements (+10 XP for each condition met):

* counting partial points (for incomplete frames, e.g. `3-|X|4/|5`)
* counting total points - [description of the rules](https://github.com/coders-school/testing/blob/master/module2/bowling_rules.txt)
* input validation with incomplete frames for several players (see next slide)
* input from multiple files in one directory, each file with multiple players represents a different track ([Filesystem library from C ++ 17](https://en.cppreference.com/w/cpp/filesystem) is recommended)
* displaying the results on the screen with the division into tracks (with game status) and players and saving to one file (next slide)
* program (`main.cpp`) has to take 2 parameters from the command line. The first is the directory where will be txt files with game states on the tracks, the second optional is the output file where the processed results are to be saved. If the second parameter is not given, the results are to be written to the screen. Example of use: `./bowling inputDirectory results.txt`.
* program (`main.cpp`) after giving the parameter `-h` or `--help` has to display short information about what it does and how to use it (i.e. the point above)

#### +20 XP for delivering by the end of August

___
<!-- .slide: style="font-size: 0.8em" -->

### Bowling - input

`lane1.txt`

```text
Name1:X|4-|3
Name2:34|X|0-
:X|22|33
```

`lane2.txt` (empty)

`lane3.txt`

```text
Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81
Radek:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||
```

### Bowling - output

```text
### Lane 1: game in progress ###
Name1 30
Name2 44
34
### Lane 2: no game ###
### Lane 3: game finished ###
Michael 167
Radek 90
```

___

## Organizational requirements

* project board with a division into notes after planning
* Continuous Integration and build system configured
* work through pull requests (each PR needs to have a number and description from the note, must undergo internal Code Review
* the content of the table may change as new requirements are discovered (and surely what you assume will change at the beginning and many things will happen that you did not anticipate)
* try to work in TDD mode from the very beginning
* each functionality must be tested; no tests = requirement not met.
* work on repo forks `coders-school/testing`
* after implementing all requirements PR to `coders-school/testing:master`

___

## Bowling - rules for counting points

```text
Each game, or "line" of bowling, includes ten turns,
or "frames" for the bowler.

In each frame, the bowler gets up to two tries to
knock down all ten pins.

If the first ball in a frame knocks down all ten pins,
this is called a "strike". The frame is over. The score
for the frame is ten plus the total of the pins knocked
down in the next two balls.

If the second ball in a frame knocks down all ten pins,
this is called a "spare". The frame is over. The score
for the frame is ten plus the number of pins knocked
down in the next ball.

If, after both balls, there is still at least one of the
ten pins standing the score for that frame is simply
the total number of pins knocked down in those two balls.

If you get a spare in the last (10th) frame you get one
more bonus ball. If you get a strike in the last (10th)
frame you get two more bonus balls.
These bonus throws are taken as part of the same turn.
If a bonus ball knocks down all the pins, the process
does not repeat. The bonus balls are only used to
calculate the score of the final frame.

The game score is the total of all frame scores.

Examples:

X indicates a strike
/ indicates a spare
- indicates a miss
| indicates a frame boundary
The characters after the || indicate bonus balls

X|X|X|X|X|X|X|X|X|X||XX
Ten strikes on the first ball of all ten frames.
Two bonus balls, both strikes.
Score for each frame == 10 + score for next two
balls == 10 + 10 + 10 == 30
Total score == 10 frames x 30 == 300

9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||
Nine pins hit on the first ball of all ten frames.
Second ball of each frame misses last remaining pin.
No bonus balls.
Score for each frame == 9
Total score == 10 frames x 9 == 90

5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5
Five pins on the first ball of all ten frames.
Second ball of each frame hits all five remaining
pins, a spare.
One bonus ball, hits five pins.
Score for each frame == 10 + score for next one
ball == 10 + 5 == 15
Total score == 10 frames x 15 == 150

X|7/|9-|X|-8|8/|-6|X|X|X||81
Total score == 167
```
