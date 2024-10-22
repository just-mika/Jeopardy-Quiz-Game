/*
	Description: This program executes Jeopady, a quiz game inspired by the American game show of the same name.
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
		- Finished the program including the comments.
	Acknowledgements:
		I would like to give thanks for the following sources, as they have helped me understand and how to utilize functions that I have yet to learn.
		- Portfolio Courses on YouTube, for helping me understand how to use the sleep() function.
			- Video Link: https://youtu.be/SjOPUr7Bkmo
		- LearningLad on YouTube, for helping me understand how to implement a random number generator in C.
			- Video Link: https://youtu.be/oXEDMNXzuo4
			- Video Link (for the RNG witihin a range): https://youtu.be/ZaZxHzRn-AY
*/

#include <stdio.h>
#include <unistd.h>
#include "MPHeader.h"

// This is the main function of the Jeopardy Game.
int main ()
{
	char cSelect, cEnd; // Declare variables for the user's selection and if they decide to end game or not.
	int nRound, nCategorySet; // Declare variables for the current round and the category set.
	int nPlayers, nScore1, nScore2; // Declare variables for the number of players and their scores.
	
	displayTitle(); // Function call to display the title.
	do // Do-while statement to display the main menu.
	{
		printf("\nWelcome to JEOPARDY!\n");
		displayMainMenu(); //Display the selection for the main menu.
		printf("\nEnter: ");
		cSelect = getChar(); // Ask for the user's selection. Use function getChar() to get a character value.
		// Switch statement to do various actions depending on user input.
		switch (cSelect) 
		{
			// If user input H, display the How to Play? option.
			case 'H':
			case 'h':
				displayHowToPlay(); // Function call displayHowToPlay() to enter the How to Play part with its sub-menus.
				break;
			// If user input X, display this message.
			case 'x':
			case 'X':
				printf("\nSee you next time!");
				break;
			// If user input P, execute
			case 'p':
			case 'P':
				{
					 // In every iteration of the game, choose a category set for the next game.
					nCategorySet = getCategorySet(); // Call function getCategorySet() to generate a random number from 1 to 4.
					nRound = 1; // Set round number to 1 to let the program know it is currently Jeopardy Round.
					// Set both scores of the players to 0.
					nScore1 = 0;
					nScore2 = 0;
					
					// Ask the user how many players will play. Call function getPlayers() and assign the returned value to the variable nPlayers.
					nPlayers = getPlayers();
					
					// Execute the Jeopardy Round by calling the function startJeopardyRound() with the following parameters.
					startJeopardyRound(nCategorySet, nRound, nPlayers, &nScore1, &nScore2);
					
					//After the round, ask the user to end the game using the function endGame().
					endGame(nPlayers, &nScore1, &nScore2, &cEnd, &cSelect, nRound);
					
					// If the user does not want to end the game, continue the game.
					if (cEnd == 'n' || cEnd == 'N')
					{
						nRound++; // Increment nRound by 1 to let the program know that it is currently the Double Round.
						
						printf("\n-----------------------------------------------------------------------------");
						printf("\nStart of the Double Round!\n");
						sleep(2); // Sleep function to pause the program for 2 seconds.
						
						// Execute the Double Round by calling the function startDoubleRound() with the following parameters.
						startDoubleRound(nCategorySet, nRound, nPlayers, &nScore1, &nScore2);
						
						//After the round, ask the user to end the game using the function endGame().
						endGame(nPlayers, &nScore1, &nScore2, &cEnd, &cSelect, nRound);
						
						// If the user does not want to end the game, continue the game.
						if (cEnd == 'n' || cEnd == 'N')
						{
							nRound++; // Increment nRound by 1 to let the program know that it is currently the the Final Jeopardy.
							
							printf("\n-----------------------------------------------------------------------------");
							printf("\nStart of the Final Jeopardy!\n");
							sleep(2); // Sleep function to pause the program for 2 seconds.
							
							// Execute the Final Jeopardy by calling the function startFinalJeopardy() with the following parameters.
							startFinalJeopardy(nCategorySet, nRound, nPlayers, &nScore1, &nScore2);
							
							//After the round, ask the user to end the game using the function endGame().
							endGame(nPlayers, &nScore1, &nScore2, &cEnd, &cSelect, nRound);
						}
					}
					break;	
				}
			default: // If the user input is none of the choices, simply display the error message and go back to the main menu.
				printf("Invalid input!\n");
				printf("\n---------------------------------------------------------------------");
				break;
		} 
	} while (cSelect != 'x' && cSelect != 'X'); // Only iterate this statement unless cSelect is X. Otherwise, end the program.
	return 0;
}