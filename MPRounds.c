/*
	Description: This file contains the functions to execute the three rounds of Jeopardy.
	Programmed by: Mikaela Nicole B. Amon S21B
	Last modified: November 23, 2023
	Version: 1.0
	Acknowledgements:
		I would like to give thanks for the following sources, as they have helped me understand and how to utilize functions that I have yet to learn.
		- Portfolio Courses on YouTube, for helping me understand how to use the sleep() function.
			- Video Link: https://youtu.be/SjOPUr7Bkmo
*/

#include <stdio.h>
#include <unistd.h>
#include "MPheader.h"

/*
	This function will start and execute the Jeopardy Round.
	Precondition:
		1. nCategorySet is an integer from 1 to 4
		2. nRound is an integer from 1 to 3
		3. nPlayers is an integer from 1 to 2
		4. The values stored in *nScore1 and *nScore2 are nonnegative integers.
	@param nCategorySet  - The chosen set of categories at the start of the round.
						- 1 = Categories 1, 2, and 3 are chosen for the game.
						- 2 = Categories 1, 3, and 4 are chosen for the game.
						- 3 = Categories 1, 2, and 4 are chosen for the game.
						- 4 = Categories 2, 3, and 4 are chosen for the game.
	@param nRound - To determine the round the game is currently in.
		- 1 = The game is currently at the Jeopardy Round.
		- 2 = The game is currently at the Double  Round.
		- 3 = The game is currently at the Final Jeopardy.
	@param nPlayers - The number of players participating in the game.
	@param *nScore1 - Pointing towards the address of Player 1's score.
	@param *nScore2 - Pointing towards the address of Player 2's score.
*/
void startJeopardyRound(int nCategorySet, int nRound, int nPlayers, int *nScore1, int *nScore2)
{ 
	/* Declare integer variables for: 
		1. i - Loop count
		2. nQuestionCount - To determine how many questions have been asked so far.
		3. nPlayerNum - To determine which player is currently answering or choosing the question.
		4. nChoose1 & nChoose2 - To determine whether or not to let Player 1 or 2 choose a question. (1 is true, 0 is false)
		5. nValue - The chosen value amount of the user.
		6. nPlayer1Score & nPlayer2Score - Temporary variables to store the players' score.
		7. nWager1 & nWager2 - The players' wager amounts.
		8. nAnswered1, nAnswered2, nAnswered3 - The value amount of the answered questions. */
	int i, nQuestionCount = 1, nPlayerNum, nChoose1 = 1, nChoose2 = 1, nValue;
	int nPlayer1Score = *nScore1, nPlayer2Score = *nScore2, nWager1, nWager2;
	int nAnswered1, nAnswered2, nAnswered3;
	
	/* Declare character variables for:
		1. cCategory - the chosen category of the user.
		2. cAnswered1, cAnswered2, cAnswered3 - The category of the answered questions. */
	char cCategory;
	char cAnswered1, cAnswered2, cAnswered3;
	
	/* For loop statement to execute the Jeopardy Round.
		- Expression 1: set i to 1
		- Expression 2: Loop the statement as long as i and nQuestionCount is less than or equal to 4.
		- Expression 3: Increment i by 1. */
	for (i = 1; i <= 4 && nQuestionCount <= 4; i++)
	{
		// In 2 player mode, only display the first gameboard if Player 1 is up to choose the next question.
		if (nPlayers == 1 || (nPlayers == 2 && nChoose1 == 1))
		{
			printf("\n-----------------------------------------------------------------------------");
			// Function call displayGameBoard() to display the game board based on the current values of the parameters.
			displayGameBoard(nCategorySet, nRound, nAnswered1, nAnswered2, nAnswered3, cAnswered1, cAnswered2, cAnswered3);
			printf("\nJeopardy Round\n");
		}
		// If there are only 1 players OR there are 2 players AND Player 1 chooses the next question, execute this statement.
		if (nPlayers == 1 || (nPlayers == 2 && nChoose1 == 1))
		{
			nPlayerNum = 1; // Set nPlayerNum to 1 to let the program know that its Player 1's turn.
			if (nPlayers == 2) // Only display this message if there are 2 players.
				printf("Player 1's turn!\n");
			printf("\nPlayer 1: \n");
			printf("Current score: $%d\n", nPlayer1Score); // Display Player 1's current score.
			
			do // Do-while loop to ask for the category and the value amount.
			{
				cCategory = getCategory(); // Call the function getCategory() and set the returned value to cCategory.
				nValue = getValue(nRound); // Call the function getValue() with nRound as a parameter, and set the returned value to nValue.
				/* If the user's category AND value amount input is the same as the previous answered questions 
				   up to that point, display the message */
				if ((nAnswered1 == nValue && cAnswered1 == cCategory) || (nAnswered2 == nValue && cAnswered2 == cCategory) || (nAnswered3 == nValue && cAnswered3 == cCategory))
				{
					printf("Question already answered!\n");
				} 
			} while ((nAnswered1 == nValue && cAnswered1 == cCategory) || (nAnswered2 == nValue && cAnswered2 == cCategory) || (nAnswered3 == nValue && cAnswered3 == cCategory));
			// Loop the statement until the user's category and value amount input is not same as the previous answered questions. 
			
			// Call the function displayQuestion() with the following parameters to display the chosen question and change the scores.	
			displayQuestion(cCategory, nCategorySet, nRound, nValue, nPlayerNum, &nPlayer1Score, &nPlayer2Score, nWager1, nWager2, &nChoose1, &nChoose2, nPlayers);
			
			// Record the chosen questions' category and value amount after it has been asked.
			if (nQuestionCount == 1) 
			{
				cAnswered1 = cCategory;
				nAnswered1 = nValue;
			}
			if (nQuestionCount == 2)
			{
				cAnswered2 = cCategory;
				nAnswered2 = nValue;
			}
			if (nQuestionCount == 3)
			{
				cAnswered3 = cCategory;
				nAnswered3 = nValue;
			}
			// After a question is asked, add the question count by 1.
			nQuestionCount++;
		}
		
		/* If there are 2 players AND Player 2 chooses the next question 
		   AND the question count is less than or equal to 4, execute this statement. */
		if ((nPlayers > 1 && nChoose2 == 1) && nQuestionCount <= 4)
		{
			nPlayerNum = 2; // Set nPlayerNum to 2 to let the program know that its Player 2's turn.
			printf("\n-----------------------------------------------------------------------------");
			// Function call displayGameBoard() to display the game board based on the current values of the parameters.
			displayGameBoard(nCategorySet, nRound, nAnswered1, nAnswered2, nAnswered3, cAnswered1, cAnswered2, cAnswered3);
			printf("\nJeopardy Round\n");
			
			printf("Player 2's turn!\n");
			printf("\nPlayer 2: \n");
			printf("Current Score: $%d\n", nPlayer2Score); // Display Player 2's score.
		
			do // Do-while loop to ask for the category and the value amount.
			{
				cCategory = getCategory(); // Call the function getCategory() and set the returned value to cCategory.
				nValue = getValue(nRound); // Call the function getValue() with nRound as a parameter, and set the returned value to nValue.
				/* If the user's category AND value amount input is the same as the previous answered questions 
				   up to that point, display the message */
				if ((nAnswered1 == nValue && cAnswered1 == cCategory) || (nAnswered2 == nValue && cAnswered2 == cCategory) || (nAnswered3 == nValue && cAnswered3 == cCategory))
					printf("Question already answered!\n");
			} while ((nAnswered1 == nValue && cAnswered1 == cCategory) || (nAnswered2 == nValue && cAnswered2 == cCategory) || (nAnswered3 == nValue && cAnswered3 == cCategory));
			// Loop the statement until the user's category and value amount input is not same as the previous answered questions.
			
			// Call the function displayQuestion() with the following parameters to display the chosen question and change the scores.	
			displayQuestion(cCategory, nCategorySet, nRound, nValue, nPlayerNum, &nPlayer1Score, &nPlayer2Score, nWager1, nWager2, &nChoose1, &nChoose2, nPlayers);
			
			// Record the chosen questions' category and value amount after it has been asked.			
			if (nQuestionCount == 2)
			{
				cAnswered2 = cCategory;
				nAnswered2 = nValue;
			}
			if (nQuestionCount == 3)
			{
				cAnswered3 = cCategory;
				nAnswered3 = nValue;
			}
			// After a question is asked, add the question count by 1.
			nQuestionCount++;
		}
	}
	// Return the resulting score values from their respective temporary variables.
	*nScore1 = nPlayer1Score;
	*nScore2 = nPlayer2Score;
}

/*
	This function will start and execute the Double Round.
	Precondition:
		1. nCategorySet is an integer from 1 to 4
		2. nRound is an integer from 1 to 3
		3. nPlayers is an integer from 1 to 2
		4. The values stored in *nScore1 and *nScore2 are nonnegative integers.
	@param nCategorySet  - The chosen set of categories at the start of the round.
						- 1 = Categories 1, 2, and 3 are chosen for the game.
						- 2 = Categories 1, 3, and 4 are chosen for the game.
						- 3 = Categories 1, 2, and 4 are chosen for the game.
						- 4 = Categories 2, 3, and 4 are chosen for the game.
	@param nRound - To determine the round the game is currently in.
		- 1 = The game is currently at the Jeopardy Round.
		- 2 = The game is currently at the Double  Round.
		- 3 = The game is currently at the Final Jeopardy.
	@param nPlayers - The number of players participating in the game.
	@param *nScore1 - Pointing towards the address of Player 1's score.
	@param *nScore2 - Pointing towards the address of Player 2's score.
*/
void startDoubleRound(int nCategorySet, int nRound, int nPlayers, int *nScore1, int *nScore2)
{
	/* Declare integer variables for: 
		1. i - Loop count
		2. nQuestionCount - To determine how many questions have been asked so far.
		3. nPlayerNum - To determine which player is currently answering or choosing the question.
		4. nChoose1 & nChoose2 - To determine whether or not to let Player 1 or 2 choose a question. (1 is true, 0 is false)
		5. nValue - The chosen value amount of the user.
		6. nPlayer1Score & nPlayer2Score - Temporary variables to store the players' score.
		7. nWager1 & nWager2 - The players' wager amounts.
		8. nAnswered1, nAnswered2, nAnswered3 - The value amount of the answered questions. */
	int i, nQuestionCount = 1, nPlayerNum, nChoose1 = 1, nChoose2 = 1, nValue;
	int nPlayer1Score = *nScore1, nPlayer2Score = *nScore2, nWager1, nWager2;
	int nAnswered1, nAnswered2, nAnswered3;
	
	/* Declare character variables for:
		1. cCategory - the chosen category of the user.
		2. cAnswered1, cAnswered2, cAnswered3 - The category of the answered questions. */
	char cCategory;
	char cAnswered1, cAnswered2, cAnswered3;
	
	/* For loop statement to execute the Double Round.
		- Expression 1: set i to 1
		- Expression 2: Loop the statement as long as i and nQuestionCount is less than or equal to 2.
		- Expression 3: Increment i by 1. */
	for (i = 1; i <= 2 && nQuestionCount <= 2; i++)
	{
		// Only display this line at the second time this statement loops.
		if (i != 1)
			printf("\n-----------------------------------------------------------------------------");
		// In 2 player mode, only display the first gameboard if Player 1 is up to choose the next question.
		if (nPlayers == 1 || (nPlayers == 2 && nChoose1 == 1))
		{
			// Function call displayGameBoard() to display the game board based on the current values of the parameters.
			displayGameBoard(nCategorySet, nRound, nAnswered1, nAnswered2, nAnswered3, cAnswered1, cAnswered2, cAnswered3);
			printf("\nDouble Round\n");
		}				
		
		// If there are only 1 players OR there are 2 players AND Player 1 chooses the next question, execute this statement.
		if (nPlayers == 1 || (nPlayers == 2 && nChoose1 == 1))
		{
			nPlayerNum = 1; // Set nPlayerNum to 1 to let the program know that its Player 1's turn.
			if (nPlayers == 2) // Only display this message if there are 2 players.
				printf("Player 1's turn!\n");
			printf("\nPlayer 1: \n");
			printf("Current score: $%d\n", nPlayer1Score); // Display Player 1's current score.
			
			do // Do-while loop to ask for the category and the value amount.
			{
				cCategory = getCategory(); // Call the function getCategory() and set the returned value to cCategory.
				nValue = getValue(nRound); // Call the function getValue() with nRound as a parameter, and set the returned value to nValue.
				/* If the user's category AND value amount input is the same as the previous answered question 
				   up to that point, display the message */
				if (nAnswered1 == nValue && cAnswered1 == cCategory)
				{
					printf("Question already answered!\n");
				}
			} while (nAnswered1 == nValue && cAnswered1 == cCategory);
			// Loop the statement until the user's category and value amount input is not same as the previous answered questions. 
			
			// Call the function displayQuestion() with the following parameters to display the chosen question and change the scores.		
			displayQuestion(cCategory, nCategorySet, nRound, nValue, nPlayerNum, &nPlayer1Score, &nPlayer2Score, nWager1, nWager2, &nChoose1, &nChoose2, nPlayers);
			
			// Record the chosen question's category and value amount after it has been asked.			
			if (nQuestionCount == 1)
			{
				cAnswered1 = cCategory;
				nAnswered1 = nValue;
			}
			// After a question is asked, add the question count by 1.
			nQuestionCount++;
		}
		
		/* If there are 2 players AND Player 2 chooses the next question 
		   AND the question count is less than or equal to 2, execute this statement. */
		if ((nPlayers > 1 && nChoose2 == 1) && nQuestionCount <= 2)
		{
			nPlayerNum = 2; // Set nPlayerNum to 2 to let the program know that its Player 2's turn.
			printf("\n-----------------------------------------------------------------------------");
			// Function call displayGameBoard() to display the game board based on the current values of the parameters.
			displayGameBoard(nCategorySet, nRound, nAnswered1, nAnswered2, nAnswered3, cAnswered1, cAnswered2, cAnswered3);
			printf("\nDouble Round\n");	
			printf("Player 2's turn!\n");
			printf("\nPlayer 2: \n"); 
			printf("Current score: $%d\n", nPlayer2Score); // Display Player 2's score.
		
			do // Do-while loop to ask for the category and the value amount.
			{
				cCategory = getCategory(); // Call the function getCategory() and set the returned value to cCategory.
				nValue = getValue(nRound); // Call the function getValue() with nRound as a parameter, and set the returned value to nValue.
				/* If the user's category AND value amount input is the same as the previous answered question 
				   up to that point, display the message */
				if (nAnswered1 == nValue && cAnswered1 == cCategory)
					printf("Question already answered!\n");
			} while (nAnswered1 == nValue && cAnswered1 == cCategory);
			// Loop the statement until the user's category and value amount input is not same as the previous answered questions.
			
			// Call the function displayQuestion() with the following parameters to display the chosen question and change the scores.			
			displayQuestion(cCategory, nCategorySet, nRound, nValue, nPlayerNum, &nPlayer1Score, &nPlayer2Score, nWager1, nWager2, &nChoose1, &nChoose2, nPlayers);
			// After a question is asked, add the question count by 1.
			nQuestionCount++;
		}
	}
	// Return the resulting score values from their respective temporary variables.
	*nScore1 = nPlayer1Score;
	*nScore2 = nPlayer2Score;
}

/*
	This function will start and execute the Final Jeopardy and the Tiebreaker Round.
	Precondition:
		1. nCategorySet is an integer from 1 to 4
		2. nRound is an integer from 1 to 3
		3. nPlayers is an integer from 1 to 2
		4. The values stored in *nScore1 and *nScore2 are nonnegative integers.
	@param nCategorySet  - The chosen set of categories at the start of the round.
						- 1 = Categories 1, 2, and 3 are chosen for the game.
						- 2 = Categories 1, 3, and 4 are chosen for the game.
						- 3 = Categories 1, 2, and 4 are chosen for the game.
						- 4 = Categories 2, 3, and 4 are chosen for the game.
	@param nRound - To determine the round the game is currently in.
		- 1 = The game is currently at the Jeopardy Round.
		- 2 = The game is currently at the Double  Round.
		- 3 = The game is currently at the Final Jeopardy.
	@param nPlayers - The number of players participating in the game.
	@param *nScore1 - Pointing towards the address of Player 1's score.
	@param *nScore2 - Pointing towards the address of Player 2's score.
*/			
void startFinalJeopardy(int nCategorySet, int nRound, int nPlayers, int *nScore1, int *nScore2)
{
	/* Declare integer variables for: 
		1. i - Loop count
		2. nPlayerNum - To determine which player is currently answering or choosing the question.
		3. nChoose1 & nChoose2 - To determine whether or not to let Player 1 or 2 choose a question. (1 is true, 0 is false)
		4. nValue - The chosen value amount of the user.
		5. nPlayer1Score & nPlayer2Score - Temporary variables to store the players' score.
		6. nWager1 & nWager2 - The players' wager amounts. Set both to 0.
		7. nAnswered1, nAnswered2, nAnswered3 - The value amount of the answered questions. */
	int i = 1, nPlayerNum, nChoose1, nChoose2, nValue;
	int nPlayer1Score = *nScore1, nPlayer2Score = *nScore2, nWager1 = 0, nWager2 = 0;
	int nAnswered1, nAnswered2, nAnswered3;
	
	/* Declare character variables for:
		1. cCategory - the chosen category of the user.
		2. cAnswered1, cAnswered2, cAnswered3 - The category of the answered questions. */
	char cCategory;
	char cAnswered1, cAnswered2, cAnswered3;
	printf("Final Jeopardy\n");
	
	// Do-while statement to execute the Final Jeopardy.
	do
	{	
		// Function call displayGameBoard() to display the game board based on the current values of the parameters.
		displayGameBoard(nCategorySet, nRound, nAnswered1, nAnswered2, nAnswered3, cAnswered1, cAnswered2, cAnswered3);
		// Regardless if there are 1 or 2 players, execute this statement.
		if (nPlayers >= 1)
		{
			printf("\nPlayer 1: \n"); 
			printf("Current score: $%d\n", nPlayer1Score); // Display Player 1's current score
			if (nPlayer1Score != 0) // If Player1's score is NOT zero, ask for the wager amount. Otherwise, don't ask for wager.
				getWager(&nWager1, nPlayer1Score); // Function call getWager() with the parameters being Player 1's data.
		}
		
		// If there are 2 players, execute this statement.
		if (nPlayers > 1)
		{
			printf("\nPlayer 2: \n");
			printf("Current score: $%d\n", nPlayer2Score); // Display Player 2's current score
			
			if (nPlayer2Score != 0)  // If Player2's score is NOT zero, ask for the wager amount. Otherwise, don't ask for wager.
				getWager(&nWager2, nPlayer2Score); // Function call getWager() with the parameters being Player 2's data.
		}	
			
		do // Do-while loop to ask for the category and the value amount.
		{
			cCategory = getCategory(); // Call the function getCategory() and set the returned value to cCategory.
			nValue = getValue(nRound); // Call the function getValue() with nRound as a parameter, and set the returned value to nValue.
			/* If the user's category AND value amount input is the same as the previous answered questions 
			   up to that point, display the message */
			if ((nAnswered1 == nValue && cAnswered1 == cCategory) || (nAnswered2 == nValue && cAnswered2 == cCategory) 
			|| (nAnswered3 == nValue && cAnswered3 == cCategory))
			{
				printf("Question already answered!\n");
			}
		} while ((nAnswered1 == nValue && cAnswered1 == cCategory) || (nAnswered2 == nValue && cAnswered2 == cCategory) 
			|| (nAnswered3 == nValue && cAnswered3 == cCategory));
		// Loop the statement until the user's category and value amount input is not same as the previous answered questions. 
		
		// Call the function displayQuestion() with the following parameters to display the chosen question and change the scores.			
		displayQuestion(cCategory, nCategorySet, nRound, nValue, nPlayerNum, &nPlayer1Score, &nPlayer2Score, nWager1, nWager2, &nChoose1, &nChoose2, nPlayers);
		
		// Record the chosen question's category and value amount after it has been asked.
		if (i == 1)
		{
			cAnswered1 = cCategory;
			nAnswered1 = nValue;
		}
		if (i == 2)
		{
			cAnswered2 = cCategory;
			nAnswered2 = nValue;
		}
		if (i == 3)
		{
			cAnswered3 = cCategory;
			nAnswered3 = nValue;
		}
			
		/* If there are 2 players, Player 1's score and Player 2's score is the same, and i is not equal to 4,
		   execute this statement. This announces to the players that the game has resulted to a draw, and thus
		   have to enter a tiebreaker round. */
		if (nPlayers == 2 && (nPlayer1Score == nPlayer2Score) && i != 4)
		{
			printf("\n-----------------------------------------------------------------------------");
			printf("\nHere are the results for this round:\n");
			sleep(1); // Sleep function to pause for 1 second
			printf("Player 1: $%d\n", nPlayer1Score); // Display Player 1's score
			sleep(1); // Sleep function to pause for 1 second
			printf("Player 2: $%d\n", nPlayer2Score); // Display Player 2's score
			sleep(1); // Sleep function to pause for 1 second
			printf("\nIt's a tie!\n");
			sleep(1); // Sleep function to pause for 1 second
			printf("\n-----------------------------------------------------------------------------");
			printf("\nTiebreaker Round\n");
			i++; //Increment i by 1.
		}
	} while ((nPlayers == 2 && (nPlayer1Score == nPlayer2Score)) && i <= 4);
	// Loop this statement until the tie is broken or the tiebreaker round is triggered 3 times.
	
	// Return the resulting score values from their respective temporary variables.
	*nScore1 = nPlayer1Score;
	*nScore2 = nPlayer2Score;
}