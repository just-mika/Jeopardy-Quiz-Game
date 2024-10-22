/*
	Description: This is the header file which contains all function prototypes for the Jeopardy program.
	Programmed by: Mikaela Nicole B. Amon S21B
	Last modified: November 27, 2023
	Version: 1.1
	Updates:
		1.1 (November 27, 2023)
		- Removed unnecessary parameters in wrongAnswer().
			- Parameters removed: int wager1, int wager2, and int value
		1.0 (November 23, 2023)
		- Finished the program including the comments
*/

int getCategorySet();

void displayTitle();

void displayMainMenu();

char getChar();

void displayHowToPlay();

int getPlayers();

void displayGameBoard(int nCategorySet, int round, int nAnswered1, int nAnswered2, int nAnswered3, char cAnswered1, char cAnswered2, char cAnswered3);

char getCategory();

int getValue(int round);

char getAnswer();

void correctAnswer(int round, int playernumber, int wager1, int wager2, int value, int *score1, int *score2);

void wrongAnswer(int round, int playernumber, int *score1, int *score2);

void getWager(int *nWager, int score);

void displayCategory1Question(int value, int round, int playernumber, int *score1, int *score2, int wager1, int wager2, int *choose1, int *choose2, int players);

void displayCategory2Question(int value, int round, int playernumber, int *score1, int *score2, int wager1, int wager2, int *choose1, int *choose2, int players);

void displayCategory3Question(int value, int round, int playernumber, int *score1, int *score2, int wager1, int wager2, int *choose1, int *choose2, int players);

void displayCategory4Question(int value, int round, int playernumber, int *score1, int *score2, int wager1, int wager2, int *choose1, int *choose2, int players);

void displayQuestion(char category, int nCategorySet, int round, int value, int playernumber, int *nScore1, int *nScore2, int nWager1, int nWager2, int *nChoose1, int *nChoose2, int nPlayers);

void startJeopardyRound(int nCategorySet, int nRound, int nPlayers, int *nScore1, int *nScore2);

void startDoubleRound(int nCategorySet, int nRound, int nPlayers, int *nScore1, int *nScore2);

void startFinalJeopardy(int nCategorySet, int nRound, int nPlayers, int *nScore1, int *nScore2);

void endGame(int nPlayers, int *nScore1, int *nScore2, char *cEnd, char *cSelect, int round);

void answerIs(char answer, char answerlowercase, char playeranswer, char playeranswer2, int round, int playernumber, int players, int wager1, int wager2, int value, int *score1, int *score2, int *choose1, int *choose2);
