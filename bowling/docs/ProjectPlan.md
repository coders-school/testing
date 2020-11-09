# Full documentation with private methods
# Bowling - project plan  

## Project setup

- Prepare project structure with required directories (src, inc, test, docs (this file to be included + UML)).
- Prepare setup for unit tests in catch2 framework (header file in test directory).
- Prepare CMake setup for building program and unit tests. Include ctest module for test running. 
- Setup continuous integration in GitHub.  

## ArgumentParser class 

- **Constructor** - constructor should take argc and argv values that were previously captured from main() function (main program function). It should then call private function parseArguments() and pass argc and argv to this function. Argc should be stored in argumentsNumber_ private variable.
No default constructor is needed. 
- **parseArguments()** private function - this function is called in the constructor and takes argc and argv values. Reads strings from argv and stores them in a private vector of strings parsedArguments_. Remember that the first element in argv is the program name, so it does not need to be stored in a vector (start from index 1 of the argv array).  
- **checkIfArgumentExist()** public function - this function should check if a given string exists in parsedArguments_ vector and returns true or false. It can be used to check if “--help” exists in argument lists.
- **getArgument()** public function - function should return argument from given position
nice to have: define enum class that would define value: FIRST, SECOND, etc. that could be used as an argument for this function.
- **getArgumentsNumber()** public function - simple getter

## DirectoryHandler class

- **Constructor** - constructor should take a name of the directory storing input files for the program (std::string). Using std::filesystem we should read all the files from the directory and store them in a private vector of strings filesInDirectory_.
No default constructor is needed.
- **getFilesInDirectory()** public function - should return vector of strings with file names.
*Attention: probably shared_ptr could be returned instead of the whole vector, but it has to be checked during implementation.*

## Lane class

- **Constructor** - constructor should take a name of the input file containing bowling game results. It should call private function parseLaneName() and parseFile()
No default constructor is needed.
- **parseLaneName()** private function - it should take the name of the input file from the constructor and cut the name of the lane from this file, e.g. SuperLane123.txt gives SuperLane123 name (trim .txt postfix). Store this name in private variable laneName_.

- **parseFile()** private function - this function should create an object of class FileHandler for input operations. It should read lines from a file in the loop (using readLine() method from FileHandler class) and for each line should create an object of SingleGame class and store it in the private vector gamesInLane_. Each line in file stores scores of one player, e.g. "Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81"
*Attention: Empty files should be properly handled (see example in project definition)*
- **getLaneName**() public function - simple getter
- **operator<<** - operator defining output to the stream operation. In the first line it should “print” the name of lane and game progress information (to be checked if every SingleGame was finished - see isGameFinished() in SingleGame). Then it should walk through the vector of SingleGame objects and call operator<< on each.

## SingleGame class

- **Constructor** - constructor should take input for single game (string) and call parseGameInput() private function. After that it should call countScore() private function.
- **parseGameInput()** private function - calls functions below:
- **readPlayerName()** private function - from the game input it should read player name and store to private string playerName_.
*Attention: player can be defined without name (":X|7/|9-|X|-8|8/|-6|X|X|X||81")*
- **putScoresToVector()** private function - read scores from the game input and store them in rolls_ vector. E.g. input “X|7/|9-|X|-8|8/|-6|X|X|X||81” should be stored in vector: {10,7,3,9,0,10,0,8,8,2,0,6,10,10,10,8,1}
- **checkStatusOfGame()** private function - check if the game started, if the game is in progress or if is ended (analyze somehow the scores - e.g. every finished game should contain “||” characters followed by one, two or none values, depending on the last value before “||”). This information should be also stored in string gameStatus_. (3 options: inProgress, noGame, finished)
- **countScore()** private function - it should count the score of the game based on the values in rolls_ vector and store the score in a private variable named score_.
- **getters** - for playerName_, score_ and gameStatus_.
- **operator<<** - operator defining output to the stream operation. It should print name of the player and score, e.g. “Michael 167”

## FileHandler class

- **Constructor** - constructor should take a path to the file that should be opened and enum class FileAccess that should indicate if file is going to be used for input or output (INPUT - reading from file, OUTPUT - writing to file).
The file should be opened in the constructor and path should be stored in private variable fileName_. After file opening, the file stream handler should be stored in another private variable fileStream_.
No default constructor is needed.
- **Destructor** - in destructor, previously opened file should be closed.
- **readLine()** public function - this function should be used to read one line from the file previously opened. This line should be returned as a string.
Remember to check if the file was opened for output operations.
Consecutive calls of the function should read next lines. If the whole file is read (i.e. readLine() is called, but each line has already been read, the function should indicate such a situation, e.g. by returning an empty string).
*Nice to have: function should skip empty lines and read the next line in such a situation.*
- **write()** public function - this function should write string to previously opened file. Remember to check if the file was opened for output operations.
*Nice to have: instead of this function, it might be useful to implement operator<<. Thanks to this we could use the same operation to store scores in file, or print it to the screen in BowlingGame class.

## BowlingGame class

- **Constructor** - constructor should take argc and argv values that were previously captured from main() function (main program function). Based on that it should create an object of class ArgumentParser.
- **isHelpToBePrinted()** public function - it checks if “--help” or “-h” is in input arguments.
- **printHelp()** public function - prints program help
- **calculateScores()** public function - create object of class DirectoryHandler with directory name read from ArgumentParser object. For every file returned by DirectoryHandler object, create Lane class object and store it in vector.
- **getOutputFileName()** private function - returns output file name (if exists) from ArgumentParser
- **outputScores()** public function - use checkOutputFile() and showScores() functions always and saveScores() function depends on checkOutputFile() return
- **isOutputFileGiven()** private function - checks if the output file was given
- **showScores()** private function - show on screen scores
- **saveScores()** private function - if function checkOutputFile() returns true, create an object of class FileHandler for output and write scores to the file by calling operator<< on every Lane object.
*Nice to have: It would be nice not to implement separate operations for displaying scores and storing them in file, but properly use operator<< instead in cout or fstream.*

  
  

## Main program
- create BowlingGame class object and pass argc and argv to the constructor
- check if only help is to be printed (BowlingGame.isHelpToBePrinted()) and if so return help - BowlingGame.printHelp(). Finish program.
- If not only help should be printed, call the function BowlingGame.calculateScores() and then call the function BowlingGame.scoreOutput(). Scores will be displayed on screen or/and stored in file. Finish program.
