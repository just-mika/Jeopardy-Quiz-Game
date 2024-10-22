/*
	Description: This file contains the user-defined functions that is used for the entirety of the Jeopardy program.
	Programmed by: Mikaela Nicole B. Amon S21B
	Last modified: November 27, 2023
	Version: 1.2
	Updates:
		1.2 (November 27, 2023)
		- Removed unnecessary parameters in wrongAnswer().
			- Parameters removed: int wager1, int wager2, and int value
		1.1 (November 25, 2023)
		- Fixed scoring for the Double Round in correctAnswer()
			- Instead of adding the computed earned amount to the current score, the computed amount WILL be the current score.
		1.0 (November 23, 2023)
		- Finished the program including the comments
	Acknowledgements:
		I would like to give thanks for the following sources, as they have helped me understand and how to utilize functions that I have yet to learn.
		- Portfolio Courses on YouTube, for helping me understand how to use the sleep() function.
			- Video Link: https://youtu.be/SjOPUr7Bkmo
		- LearningLad on YouTube, for helping me understand how to implement a random number generator in C.
			- Video Link: https://youtu.be/oXEDMNXzuo4
			- Video Link (for the RNG witihin a range): https://youtu.be/ZaZxHzRn-AY
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "MPheader.h"

/*
	This function will generate a random number from 1 - 4. This is to choose the set of categories that will 
	be used in the game.
	Precondition: None
	@return a number ranging from 1 to 4.
		- 1 = Categories 1, 2, and 3 are chosen for the game.
		- 2 = Categories 1, 3, and 4 are chosen for the game.
		- 3 = Categories 1, 2, and 4 are chosen for the game.
		- 4 = Categories 2, 3, and 4 are chosen for the game.
*/
int getCategorySet()
{
	/* srand() function is used to set the starting point for the rand() function.
	   time(NULL) function is used as the seed so that the random number generated isn't the same every run. */
	srand(time(NULL));
	/* return the generated random number using the rand() function, get its modulo by 4 and add 1 
	   so that the returned number will only range from 1 to 4. */
	return (rand() % 4) + 1; 
}

/*
	This function will get a character value and returns it.
	Precondition: None
	@return a character value.
*/
char getChar() 
{
	char selection; // Declare character variable for the character.
	scanf(" %c", &selection); // Input character
	return selection; // Return the entered character.
}

/*
	This function will get the amount of players that will participate in the game.
	Precondition: None
	@return the number of players.
*/
int getPlayers() 
{
	int players; // Declare integer variable for the number of players 
	// Do-while loop to ask for the number of players.
	do
	{
		printf("\nHow many players [1-2]: ");
		scanf("%d", &players); // Input number of players 
		if (players <= 0 || players >= 3) // If the number inputted is neither 1 or 2, display message.
			printf("One or two players only!\n");
	} while (players <= 0 || players >= 3); // Loop the statement until the number is either 1 or 2.
	return players; // Return the number of players.
}

/*
	This function will get the chosen category of the player.
	Precondition: None
	@return the letter of the chosen category.
*/
char getCategory()                                           
{
	char category; // Declare character variable for the category.
	do // Do-while loop to select for a category.
	{
		printf("\nSelect a category [A to C]: ");
		// Call the function getChar() to get a character value, and assign the returned value to the variable 'category'.
		category = getChar(); 
		// If user input a lowercase letter, convert it to uppercase.
		if (category == 'a')
			category = 'A';
		if (category == 'b')
			category = 'B';
		if (category == 'c')
			category = 'C';
		// If the category is not A, B, or C, display the error message.
		if (category < 'A' || category > 'C')
			printf("Invalid category!\n");
	} while (category < 'A' || category > 'C'); //Loop the statement until category is A, B, or C.
	return category; //Return the character value of chosen category
}

/*
	This function will get the number corresponding the chosen value amount of the question.
	Precondition: round is an integer from 1 to 3.
	@param round - To determine the round the game is currently in.
		- 1 = The game is currently at the Jeopardy Round.
		- 2 = The game is currently at the Double  Round.
		- 3 = The game is currently at the Final Jeopardy.
	@return the number corresponding to the chosen value amount.
*/
int getValue(int round)
{
	int value; // Declare variable for the number corresponding to the value amount.
	do // Do-while loop to select a value amount.
	{
		printf("Select a value amount ");
		if (round == 1) // If it is currently at Jeopardy Round, set value boundary from 1 to 5.
			printf("[1 to 5]: ");
		if (round == 2) // If it is currently at Double Round, set value boundary from 1 to 3.
			printf("[1 to 3]: ");
		if (round == 3) // If it is currently at Final Round, set value boundary from 1 to 2.
			printf("[1 to 2]: ");
		scanf("%d", &value); // Input the chosen number.
		/* If the following conditions are true:
		   - It is Jeopardy Round and the value is not a number from 1 to 5
		   - It is Double Round and the value is not a number from 1 to 3
		   - It is Final Jeopardy and the value is not a number from 1 to 2
		   Display the invalid message. */
		if (((value <= 0 || value >= 6) && round == 1) || ((value <= 0 || value >= 4) && round == 2) || ((value <= 0 || value >= 3) && round == 3))
			printf("Invalid value amount!\n");
	} while (((value <= 0 || value >= 6) && round == 1) || ((value <= 0 || value >= 4) && round == 2) || ((value <= 0 || value >= 3) && round == 3));
	// Loop the statement if the number is outside the value boundary.
	
	return value; // Return the number corresponding to the value amount.
}

/*
	This function will ask for the answer of the player to their chosen question.
	Precondition: None
	@return the letter corresponding the answer of the player.
*/
char getAnswer()
{
	char answer; // Declare character variable for the answer
	do // Do-while loop to get the answer
	{
		printf("\nType your answer: ");
		answer = getChar(); // Call the function getChar() to get a character value, and assign the returned value to the variable 'answer'.
		if ((answer < 'a' || answer > 'd') && (answer < 'A' || answer > 'D')) // If the answer is not within A to D, display message.
		printf("Invalid Input!\n");
	} while ((answer < 'a' || answer > 'd') && (answer < 'A' || answer > 'D')); // Loop statement until answer is A, B, C, or D.
	return answer; // Return the character value of answer.
}

/*
	This function will get the player's wager amount.
	Precondition: The value in nWager and in the variable 'score' is a nonnegative integer.
	@param *nWager - The pointer variable pointing to the address of a wager variable.
	@param score - The player's current score.
*/
void getWager(int *nWager, int score)
{
	int wager; // Declare integer variable for the wager variable
	char cWager; // Declare character variable for the player's choice
	if (score > 0) // If score is currently greater than 0, execute the statement
	{
		do // Do-while loop to ask for the player's decision to wager.
		{
			printf("\nDo you wager? [Y or N]: ");
			cWager = getChar(); // Call the function getChar() to get a character value, and assign the returned value to cWager.
			if ((cWager!= 'Y' && cWager != 'y') && (cWager != 'n' && cWager != 'N')) // If cWager is neither Y nor N, display message.
				printf("Invalid input!"); 
		} while ((cWager != 'Y' && cWager != 'y') && (cWager != 'n' && cWager != 'N')); // Loop statement until cWager is Y or N.
		
		if (cWager == 'Y' || cWager == 'y') // If cWager is Y (meaning 'Yes')
		{
			do // Do-while loop to ask for the wager amount.
			{
				printf("\nHow much do you wager?: $");
				scanf("%d", &wager); // Input the value for the wager amount.
				if ((wager > score) && (wager != 0)) // If the wager is greater than the current score and it is not equal to zero, display this message.
					printf("Invalid amount! Only wager a portion of your score.");
				if (wager == 0) // If the wager is equal to zero, display message.
					printf("Invalid input!");	
			} while ((wager > score) || wager == 0); // Loop statement until wager is less than the current score and not equal to 0.
		}
		else // Otherwise, set wager amount to 0.
			wager = 0;
	}
	else // else, set the wager amount to 0.
		wager = 0;
		
	*nWager = wager; // Store the wager amount in *nWager 
}

/*
	This function will let the player know that they have correctly answered a question and adds the value amount to their score.
	Precondition: 
		1. round is an integer from 1 to 3
		2. playernumber is either 1 or 2
		3. wager1 and wager2 are nonnegative integers
		4. value is a number from 1 to 5
		5. The values stored in *score1 and *score2 are nonnegative integers.
	@param round - To determine the round the game is currently in.
					- 1 = The game is currently at the Jeopardy Round.
					- 2 = The game is currently at the Double  Round.
					- 3 = The game is currently at the Final Jeopardy.
	@param playernumber - To determine which player has correctly answered the question.
							- 1 = Player 1
							- 2 = Player 2
	@param wager1 - The amount Player 1 wagers.
	@param wager2 - The amount Player 2 wagers.	
	@param value - The value amount of the chosen question.
	@param *score1 - Pointing towards the address of Player 1's score.
	@param *score2 - Pointing towards the address of Player 2's score.
*/
void correctAnswer(int round, int playernumber, int wager1, int wager2, int value, int *score1, int *score2)
{
	int tempscore1 = *score1, tempscore2 = *score2; //Place the score values in temporary variables.
	printf("You got the correct answer! ");

	if (round == 1) // If it is currently Jeopardy Round, multiply the value to 200.
	{
		value *= 200;
	}
	if (round == 2) // If it is currently Double Round, multiply the value to 400.
	{
		value *= 400;
		// Set value amount to the 2 times the sum of the current player's score and the value amount of the question.
		if (playernumber == 1)
			value = 2 * (tempscore1 + value); 
		if (playernumber == 2)
			value = 2 * (tempscore2 + value);
	}
	if (round == 3) // If it is currently the Final Jeopardy,
	{
		/* If the current player's wager is not equal to 0, set the value of the value variable. 
		    to the wager amount. Otherwise, multiply the value amount of the question by 2500. */
		if (playernumber == 1)
		{
			if (wager1 != 0)
				value = wager1;
			else
				value *= 2500;
		}
		if (playernumber == 2)
		{
			if (wager2 != 0)
				value = wager2;
			else
				value *= 2500;
		}
	}	
	sleep(1); //Sleep function to pause for 1 second before displaying the message.
	printf("You earn $%d.", value);
	/* Add/Set the current value to the respective temporary variable of the score and return the added score
	   to the respective variable containing the current score. */
	if (playernumber == 1)
	{
		if (round == 1 || round == 3)
			tempscore1 += value;
		else
			tempscore1 = value;
		*score1 = tempscore1;
	}
	if (playernumber == 2)
	{
		if (round == 1 || round == 3)
			tempscore2 += value;
		else
			tempscore2 = value;
		*score2 = tempscore2;
	}
}

/*
	This function will let the player know that they have incorrectly answered a question. 
	It also deducts the player's score depending on the current round.
	Precondition: 
		1. round is an integer from 1 to 3
		2. playernumber is either 1 or 2
		3. The values stored in *score1 and *score2 are nonnegative integers.
	@param round - To determine the round the game is currently in.
					- 1 = The game is currently at the Jeopardy Round.
					- 2 = The game is currently at the Double  Round.
					- 3 = The game is currently at the Final Jeopardy.
	@param playernumber - To determine which player has correctly answered the question.
							- 1 = Player 1
							- 2 = Player 2
	@param *score1 - Pointing towards the address of Player 1's score.
	@param *score2 - Pointing towards the address of Player 2's score.
*/
void wrongAnswer(int round, int playernumber, int *score1, int *score2)
{
	int tempscore1 = *score1, tempscore2 = *score2; //Place the score values in temporary variables.
	printf("Wrong answer! ");
	
	if (round == 2 || round == 3) //If it is currently Double Round or Final Jeopardy, execute this statement.
	{
		sleep(1); // Sleep function to pause for 1 second.
		/* If the player's score isn't 0, display the message, set the value of the respective 
		   temporary variable to 0 and store it in the respective score variable. */
		if (playernumber == 1 && tempscore1 != 0)
		{
			printf("You lose all of your points!\n");
			tempscore1 = 0;
			*score1 = tempscore1;
		}
		if (playernumber == 2 && tempscore2 != 0) 
		{
			printf("You lose all of your points!\n");
			tempscore2 = 0;
			*score2 = tempscore2;
		}
	}
}

/*
	This function will display the question that the player had chosen.
	Precondition:
		1. category is a letter from A to C
		2. nCategorySet is an integer from 1 to 4.
		3. round is an integer from 1 to 3.
		4. value is an integer from 1 to 5.
		5. playernumber is an integer from 1 to 2.
		6. The values stored in *score1 and *score2 are nonnegative integers.
		7. nWager1 and nWager2 are nonnegative integers.
		8. The values stored in *nChoose1 and *nChoose2 are either 1 or 0.
		9. nPlayers is an integer from 1 to 2.
	@param category - The player's chosen category of the question.
	@param nCategorySet  - The chosen set of categories at the start of the round.
						- 1 = Categories 1, 2, and 3 are chosen for the game.
						- 2 = Categories 1, 3, and 4 are chosen for the game.
						- 3 = Categories 1, 2, and 4 are chosen for the game.
						- 4 = Categories 2, 3, and 4 are chosen for the game.
	@param round - To determine the round the game is currently in.
					- 1 = The game is currently at the Jeopardy Round.
					- 2 = The game is currently at the Double  Round.
					- 3 = The game is currently at the Final Jeopardy.
	@param value - The value amount of the chosen question.
	@param playernumber - To determine which player has correctly answered the question.
							- 1 = Player 1
							- 2 = Player 2
	@param *nScore1 - Pointing towards the address of Player 1's score.
	@param *nScore2 - Pointing towards the address of Player 2's score.
	@param nWager1 - The amount Player 1 wagers.
	@param nWager2 - The amount Player 2 wagers.	
	@param *nChoose1 - To determine whether or not to let Player 1 choose a question.
						- 1 = Let Player 1 choose
						- 0 = Don't let Player 1 choose
	@param *nChoose2 - To determine whether or not to let Player 2 choose a question.
						- 1 = Let Player 2 choose
						- 0 = Don't let Player 2 choose
	@param nPlayers - The number of players participating in the game.
*/
void displayQuestion(char category, int nCategorySet, int round, int value, int playernumber, int *nScore1, int *nScore2, int nWager1, int nWager2, int *nChoose1, int *nChoose2, int nPlayers)
{
	// Store the scores of the players in their respective temporary variables.
	int score1 = *nScore1, score2 = *nScore2;
	// Store the deciding factor whether the player chooses the next question or not in their respective temporary variables
	int tempchoose1 = *nChoose1, tempchoose2 = *nChoose2;
	// Store the wager amount of the players in their respective temporary variables.
	int tempwager1 = nWager1, tempwager2 = nWager2;
	
	printf("\nHere is your question: ");
	if (category == 'A')
	{
		//If chosen category is A, and if the category set for the game is 4, display a question from Category 2.
		if (nCategorySet == 4)
			displayCategory2Question(value, round, playernumber, &score1, &score2, tempwager1, tempwager2, &tempchoose1, &tempchoose2, nPlayers);
		else // Otherwise, display a question from Category 1.
			displayCategory1Question(value, round, playernumber, &score1, &score2, tempwager1, tempwager2, &tempchoose1, &tempchoose2, nPlayers);
	}
	
	if (category == 'B')
	{
		// If chosen category is B, and if the category set for the game is 2 or 4, display a question from Category 3.
		if (nCategorySet == 2 || nCategorySet == 4)
			displayCategory3Question(value, round, playernumber, &score1, &score2, tempwager1, tempwager2, &tempchoose1, &tempchoose2, nPlayers);
		else // Otherwise, display a question from Category 2.
			displayCategory2Question(value, round, playernumber, &score1, &score2, tempwager1, tempwager2, &tempchoose1, &tempchoose2, nPlayers);
	}
	
	if (category == 'C')
	{
		// If chosen category is C, and if the category set for the game is 1, display a question from Category 3.
		if (nCategorySet == 1)
			displayCategory3Question(value, round, playernumber, &score1, &score2, tempwager1, tempwager2, &tempchoose1, &tempchoose2, nPlayers);
		else // Otherwise, display a question from Category 4.
			displayCategory4Question(value, round, playernumber, &score1, &score2, tempwager1, tempwager2, &tempchoose1, &tempchoose2, nPlayers);		
	}
	
	// If there are 2 players, display a summary of their scores.
	if (nPlayers > 1)
	{
		sleep(1);
		printf("\n\nCurrent scores: \n");
		printf("Player 1: $%d\n", score1);
		printf("Player2: $%d\n", score2);
		sleep(1); // Sleep function to pause for 1 second.
	}
	sleep(1); // Sleep function to pause for 1 second.
	
	// Return the values of the scores and the determining factor from their respective temporary variables.
	*nScore1 = score1;
	*nScore2 = score2;
	*nChoose1 = tempchoose1;
	*nChoose2 = tempchoose2;
}

/*
	This function will show the summary of the results at the end of the round, announces the winner of the game, 
	and asks if the player would like to continue or not.
	Precondition:
		1. nPlayers is an integet from 1 to 2.
		2. The value in *nScore1 and *nScore2 is a nonnegative integer.
		3. The value in *cSelect is the letter P
		4. round is an integer from 1 to 3.
	@param nPlayers - The number of players participating in the game.
	@param *nScore1 - Pointing towards the address of Player 1's score.
	@param *nScore2 - Pointing towards the address of Player 2's score.
	@param *cEnd - The deciding factor of whether or not the player/s want to end the game.
	@param *cSelect - The pointer containing the selection for the main menu.
	@param round - To determine the round the game is currently in.
					- 1 = The game is currently at the Jeopardy Round.
					- 2 = The game is currently at the Double  Round.
					- 3 = The game is currently at the Final Jeopardy.
*/
void endGame(int nPlayers, int *nScore1, int *nScore2, char *cEnd, char *cSelect, int round)
{
	printf("\n-----------------------------------------------------------------------------");
	printf("\nHere are the results for this round:\n");
	sleep(1); // Sleep function to pause for 1 second
	if (nPlayers >= 1) // If number of players are 1 or 2, display player 1's score.
	{
		printf("\nPlayer 1: $%d", *nScore1);
	}
	if (nPlayers > 1) // If number of players is 2, display player 2's score too.
	{
		sleep(1); // Sleep function to pause for 1 second
		printf("\nPlayer 2: $%d\n", *nScore2);
	}
	sleep(1); // Sleep function to pause for 1 second
	
	if (round != 3) // Only ask to end game at the end of Jeopardy and Double Jeopardy Rounds.
	{
		do // Do-while loop to ask to end the game.
		{
			printf("\nEnd Game? [Y or N]: ");
			*cEnd = getChar(); // Function call getChar() to get a character and store the value in cEnd.
			// If the value stored in cEnd is neither Y nor N, display this message
			if ((*cEnd != 'Y' && *cEnd != 'y') && (*cEnd != 'n' && *cEnd != 'N'))
				printf("Invalid input!");
		} while ((*cEnd != 'Y' && *cEnd != 'y') && (*cEnd != 'n' && *cEnd != 'N'));
		// Loop statement until the value stored in cEnd is Y or N.
	}
	else // If it is currently Final Jeopardy, store 'Y' in cEnd to trigger the next if statement.
		*cEnd = 'Y';
	// If the value in cEnd is Y, show the final score of the player/s.
	if (*cEnd == 'Y' || *cEnd == 'y')
	{
		printf("\n-----------------------------------------------------------------------------\n");
		// If there is only 1 player, simply display their final score and display the respective message.
		if (nPlayers == 1)
		{
			printf("\nYour final score is $%d. ", *nScore1);
			sleep(1); // Sleep function to pause for 1 second before displaying text.
			if (*nScore1 >= 100) // If player's score is at least 100, display this message
				printf("Congratulations!\n");
			else // Otherwise, display this message.
				printf("Better luck next time!\n");
		}
		else // If there are 2 players, display both of their scores and determine the winner.
		{
			printf("\nPlayer 1's final score is $%d. ", *nScore1);
			sleep(1); // Sleep function to pause for 1 second before displaying player 2's score.
			printf("\nPlayer 2's final score is $%d. \n", *nScore2);
			sleep(1); // Sleep function to pause for 1 second before determining the winner.
			
			/* If Player 1's score is greater than Player 2's score,
			   declare Player 1 as the winner. */
			if (*nScore1 > *nScore2)
			{
				printf("\nPlayer 1 wins! Congratulations!\n");
				sleep(1); // Sleep function to pause for 1 second
				printf("Better luck next time, Player 2!\n");
			}
			/* If Player 2's score is greater than Player 1's score,
			   declare Player 2 as the winner. */
			if (*nScore1 < *nScore2)
			{
				printf("\nPlayer 2 wins! Congratulations!\n");
				sleep(1); // Sleep function to pause for 1 second
				printf("Better luck next time, Player 1!\n");
			}
			/* If Player 1's score is still equal to Player 2's score despite the
			   Tiebreaker Rounds, declare a tie. */
			if (*nScore1 == *nScore2)
			{
				printf("\nIt's a tie. Better luck next time!\n'");
			}
		}
		
		sleep(1); // Sleep function to pause for 1 second before asking to return to the main menu.
		 /* After displaying the final scores, execute this do-while loop to ask if the user wants to 
		    return to the main menu or exit the program. */
		do
		{
			printf("\nReturn to main menu? [Y or N]: ");
			*cSelect = getChar(); // Function call getChar() to get a character and store the value in cSelect.
			// If the value stored in cSelect is neither Y nor N, display this message
			if ((*cSelect != 'Y' && *cSelect != 'y') && (*cSelect != 'n' && *cSelect != 'N'))
				printf("Invalid input!");
		} while ((*cSelect != 'Y' && *cSelect != 'y') && (*cSelect != 'n' && *cSelect != 'N'));
		// Loop statement until the value stored in cSelect is Y or N.
		
		/* If the value stored in cSelect is Y, simply print this line and in the main function,
		   it will loop back to the Main Menu. */
		if (*cSelect == 'y' || *cSelect == 'Y')
			printf("\n---------------------------------------------------------------------");
		/* If the value stored in cSelect is N, print this message and set the value stored in cSelect
		   to be X so that it will exit the program in the main function. */
		if (*cSelect == 'n' || *cSelect == 'N')
		{				
			printf("\nSee you next time!");
			*cSelect = 'X';
		}
	}
}

/*
	This function will reveal if the answer the player chose is correct or not. It also executes the mechanic of the other 
	player being able to steal points from the other.
	Precondition: 
		1. answer is an uppercase character.
		2. answerlowercase is a lowercase character.
		3. playeranswer and playeranswer2 is a character from A to D.
		4. round is an integer from 1 to 3.
		5. playernumber and players is an integer from 1 to 2.
		6. wager1 and wager2 are nonnegative integers.
		7. value is an integer from 1 to 5.
		8. The values in *score1 and *score2 are nonnegative integers.
		9. The value in *choose1 and *choose2 are 1 or 0. 
	@param answer - The letter answer to the question in uppercase.
	@param answerlowercase - The letter answer to the question in lowercase.
	@param playeranswer - The current player's answer to the chosen question. Also Player 1's answer in Final Jeopardy.
 	@param playeranswer2 - Player 2's answer in Final Jeopardy.
	@param round - To determine the round the game is currently in.
					- 1 = The game is currently at the Jeopardy Round.
					- 2 = The game is currently at the Double  Round.
					- 3 = The game is currently at the Final Jeopardy.
	@param value - The value amount of the chosen question.
	@param playernumber - To determine which player has answered the question.
							- 1 = Player 1
							- 2 = Player 2
	@param players - The number of players participating in the game.
	@param wager1 - The amount Player 1 wagers.
	@param wager2 - The amount Player 1 wagers.
	@param value - The value amount of the chosen question.
	@param *score1 - Pointing towards the address of Player 1's score.
	@param *score2 - Pointing towards the address of Player 2's score.
	@param *choose1 - To determine whether or not to let Player 1 choose a question.
						- 1 = Let Player 1 choose
						- 0 = Don't let Player 1 choose
	@param *choose2 - To determine whether or not to let Player 2 choose a question.
						- 1 = Let Player 2 choose
						- 0 = Don't let Player 2 choose
*/

void answerIs(char answer, char answerlowercase, char playeranswer, char playeranswer2, int round, int playernumber, int players, int wager1, int wager2, int value, int *score1, int *score2, int *choose1, int *choose2)
{
	// Store the scores of the players in their respective temporary variables.
	int tempscore1 = *score1, tempscore2 = *score2;
	// Declare temporary variables for the choose variables.
	int tempchoose1, tempchoose2;
	
	// If it is currently Jeopardy or Double Round, execute this statement.
	if (round == 1 || round == 2)
	{
		// If player got the answer correct, call function correctAnswer() to add the points and let the next player choose a question.
		if (playeranswer == answer || playeranswer == answerlowercase)
		{
			correctAnswer(round, playernumber, wager1, wager2, value, &tempscore1, &tempscore2);
			if (playernumber == 1)
				tempchoose2 = 1;
			if (playernumber == 2)
				tempchoose1 = 1;
		}
		else // If player got the answer incorrect, call function wrongAnswer() to simply display a message or deduct the points.
		{
			wrongAnswer(round, playernumber, &tempscore1, &tempscore2);
			if (players == 2) // If there are 2 players, execute the following.
			{
				if (playernumber == 1) // If the one who answered incorrectly was Player 1, let Player2 answer the question.
				{
					sleep(1); // Sleep function to pause for 1 second.
					playernumber = 2; // Set player number to 2 to let the program know Player 2 is now answering the question.
					printf("Player 2, what's your answer?\n");
					playeranswer = getAnswer(); // Function call getAnswer() to get the answer.
					// If Player 2 got the answer correct, call function correctAnswer() to add the points and let them choose the next question.
					if (playeranswer == answer || playeranswer == answerlowercase) 
					{
						correctAnswer(round, playernumber, wager1, wager2, value, &tempscore1, &tempscore2);
						tempchoose2 = 1;
					}
					else //Otherwise, call function wrongAnswer() and let the previous player choose the question once again.
					{
						wrongAnswer(round, playernumber, &tempscore1, &tempscore2);
						tempchoose1 = 1;
						tempchoose2 = 0;
					}
				}
				else // Otherwise, if it was Player 2 who incorrectly answered the question, let Player 1 answer said question.
				{
					sleep(1); // Sleep function to pause for 1 second.
					playernumber = 1; // Set the player number to 1 to let the program know Player 1 is now answering the question.
					printf("Player 1, what's your answer?\n");
					playeranswer = getAnswer(); // Function call getAnswer() to get the answer.
					// If Player 2 got the answer correct, call function correctAnswer() to add the points and let them choose the next question.
					if (playeranswer == answer || playeranswer == answerlowercase)
					{
						correctAnswer(round, playernumber, wager1, wager2, value, &tempscore1, &tempscore2);
						tempchoose1 = 1;
					}
					else // Otherwise, call function wrongAnswer() and let the previous player choose the question once again.
					{
						wrongAnswer(round, playernumber, &tempscore1, &tempscore2);
						tempchoose1 = 0;
						tempchoose2 = 1;
					}
				}
			}
		}
	}
	
	// If it is currently in the Final Jeopardy, execute this statement.
	if (round == 3)
	{
		// If number of players are at least 1, display if Player 1 answered the question correctly or not.
		if (players >= 1)
		{
			playernumber = 1; // Set player number to 1 to let the program know to add/deduct Player 1's score. 
			// If there are 2 players in the game, display this.
			if (players == 2) 
				printf("\nPlayer 1: ");
			// If player got the answer correct, call function correctAnswer() to add the points.
			if (playeranswer == answer || playeranswer == answerlowercase)
				correctAnswer(round, playernumber, wager1, wager2, value, &tempscore1, &tempscore2);
			else // If player got the answer incorrect, call function wrongAnswer() to simply display a message or deduct the points.
				wrongAnswer(round, playernumber, &tempscore1, &tempscore2);
		}
		
		// Only display if Player 2 answered the question correctly or not if the number of players is 2.
		if (players == 2)
		{
			printf("\nPlayer 2: ");
			playernumber = 2; // Set player number to 2 to let the program know to add/deduct Player 2's score.
			// If player got the answer correct, call function correctAnswer() to add the points.
			if (playeranswer2 == answer || playeranswer2 == answerlowercase)
				correctAnswer(round, playernumber, wager1, wager2, value, &tempscore1, &tempscore2);
			else // If player got the answer incorrect, call function wrongAnswer() to simply display a message or deduct the points.
				wrongAnswer(round, playernumber, &tempscore1, &tempscore2);
		}
	}
	// Return the resulting value to their respective variables from the temporary variables.
	*score1 = tempscore1;
	*score2 = tempscore2;
	*choose1 = tempchoose1;
	*choose2 = tempchoose2;
}