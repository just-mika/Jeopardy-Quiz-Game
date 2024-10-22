/*
	Description: This program contains the function to display Category 1 (World Capitals) questions and asks for the answer.
	Programmed by: Mikaela Nicole B. Amon S21B
	Last modified: November 23, 2023
	Version: 1.0
*/

#include <stdio.h>
#include <unistd.h>
#include "MPheader.h"

/*
	This function will display the questions and choices in Category 1: World Capitals.
	Preconditions:
		1. value is an integer from 1 to 5.
		2. round is an integer from 1 to 3.
		3. playernumber and players is an integer from 1 to 2.
		4. The values in *score1 and *score2 are nonnegative integers.
		5. wager1 and wager2 are nonnegative integers.
		6. The value in *choose1 and *choose2 are 1 or 0.
		7. players is an integer from 1 to 2.
	@param value - The value amount of the chosen question. 
	@param round - To determine the round the game is currently in.
					- 1 = The game is currently at the Jeopardy Round.
					- 2 = The game is currently at the Double  Round.
					- 3 = The game is currently at the Final Jeopardy.
	@param playernumber - To determine which player has answered the question.
							- 1 = Player 1
							- 2 = Player 2
	@param *score1 - Pointing towards the address of Player 1's score.
	@param *score2 - Pointing towards the address of Player 2's score.
	@param wager1 - The amount Player 1 wagers.
	@param wager2 - The amount Player 2 wagers.	
	@param *choose1 - To determine whether or not to let Player 1 choose a question.
						- 1 = Let Player 1 choose
						- 0 = Don't let Player 1 choose
	@param *choose2 - To determine whether or not to let Player 2 choose a question.
						- 1 = Let Player 2 choose
						- 0 = Don't let Player 2 choose
	@param players - The number of players participating in the game.

*/
void displayCategory1Question(int value, int round, int playernumber, int *score1, int *score2, int wager1, int wager2, int *choose1, int *choose2, int players)
{
	// Store the scores of the players in their respective temporary variables.
	int tempscore1 = *score1, tempscore2 = *score2;
	int tempchoose1 = *choose1, tempchoose2 = *choose2;
	// Declare character variables for the current player's answer and the second player's answer.
	char nPlayerAnswer, nPlayer2answer;
	// If it is currently the Jeopardy Round, display one of these 5 questions.
	if (round == 1)
	{
		// Switch statement to display a question depending on the chosen value amount.
		switch (value)
		{
			case 1: // If the player has chosen a value amount of $200, display this question.
			{
				printf("What is the capital city of the United States?\n");
				printf("A) New York\n");
				printf("B) Los Angeles\n");
				printf("C) Washington D.C.\n");
				printf("D) Seattle\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with C being the answer to the question.
				answerIs('C', 'c', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;
			}	
			case 2: // If the player has chosen a value amount of $400, display this question.
			{
				printf("What is the capital city of Brazil?\n");
				printf("A) Brasilia\n");
				printf("B) Sao Paulo\n");
				printf("C) Rio de Janeiro\n");
				printf("D) Salvador\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with A being the answer to the question.
				answerIs('A', 'a', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;			
			}		
			case 3: // If the player has chosen a value amount of $600, display this question.
			{
				printf("What is the capital city of Germany?\n");
				printf("A) Hamburg\n");
				printf("B) Berlin\n");
				printf("C) Munich\n");
				printf("D) Frankfurt\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with B being the answer to the question.
				answerIs('B', 'b', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;
			}
			case 4: // If the player has chosen a value amount of $800, display this question.
			{
				printf("What is the capital city of Australia?\n");
				printf("A) Brisbane\n");
				printf("B) Canberra\n");
				printf("C) Sydney\n");
				printf("D) Melbourne\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with B being the answer to the question.
				answerIs('B', 'b', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;
			}
			case 5: // If the player has chosen a value amount of $1000, display this question.
			{
				printf("What is the capital city of India?\n");
				printf("A) Mumbai\n");
				printf("B) Kolkata\n");
				printf("C) Surat\n");
				printf("D) New Delhi\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with B being the answer to the question.
				answerIs('D', 'd', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;
			}	
		}
	}
	// If it is currently the Double Round, display one of these 3 questions.
	if (round == 2)
	{
		// Switch statement to display a question depending on the chosen value amount.
		switch (value)
		{
			case 1: // If the player has chosen a value amount of $400, display this question.
			{
				printf("What is the capital city of Vietnam?\n");
				printf("A) Dalat\n");
				printf("B) Ho Chi Minh\n");
				printf("C) Hanoi\n");
				printf("D) Da Nang\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with C being the answer to the question.
				answerIs('C', 'c', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				
				break;
			}
			case 2: // If the player has chosen a value amount of $800, display this question.
			{
				printf("What is the capital city of Argentina?\n");
				printf("A) Tigre\n");
				printf("B) Buenos Aires\n");
				printf("C) Rosario\n");
				printf("D) La Plata\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with B being the answer to the question.
				answerIs('B', 'b', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;
			}
			case 3: // If the player has chosen a value amount of $1200, display this question.
			{
				printf("What is the capital city of Belarus?\n");
				printf("A) Mogilev\n");
				printf("B) Vitebsk\n");
				printf("C) Brest\n");
				printf("D) Minsk\n");
				
				// Ask the player for their answer
				nPlayerAnswer = getAnswer();
				// Function call answerIs, with D being the answer to the question.
				answerIs('D', 'd', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;
			}
		}
	}
	// If it is currently the Final Jeopardy display one of these 2 questions.
	if (round == 3)
	{
		// Switch statement to display a question depending on the chosen value amount.
		switch (value)
		{
			case 1: // If the player has chosen a value amount of $2500, display this question.
			{
				printf("What is the capital city of Kiribati?\n");
				printf("A) Tarawa\n");
				printf("B) Betio\n");
				printf("C) Bikenibeu\n");
				printf("D) Teaoraereke\n");
				
				if (players >= 1)
				{
					if (players == 2)
						printf("\nPlayer 1: ");
					// Ask Player 1 for their answer
					nPlayerAnswer = getAnswer();
				}
				// Only display this if there are 2 players
				if (players == 2)
				{
					printf("\nPlayer 2: ");
					// Ask Player 2 for their answer
					nPlayer2answer = getAnswer();
				}
				// Function call answerIs, with A being the answer to the question.
				answerIs('A', 'a', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;	
			}
			case 2: // If the player has chosen a value amount of $5000, display this question.
			{
				printf("What is the capital city of Botswana?\n");
				printf("A) Francistown\n");
				printf("B) Molepolole\n");
				printf("C) Gaborone\n");
				printf("D) Maun\n");
				
				if (players >= 1)
				{
					if (players == 2)
						printf("\nPlayer 1: ");
					// Ask Player 1 for their answer
					nPlayerAnswer = getAnswer();
				}
				
				if (players == 2)
				{
					printf("\nPlayer 2: ");
					// Ask Player 2 for their answer
					nPlayer2answer = getAnswer();
				}
				// Function call answerIs, with C being the answer to the question.
				answerIs('C', 'c', nPlayerAnswer, nPlayer2answer, round, playernumber, players, wager1, wager2, value, &tempscore1, &tempscore2, &tempchoose1, &tempchoose2);
				break;
			}
		}
	}
	// Return the resulting values from their respective temporary variables.
	*score1 = tempscore1;
	*score2 = tempscore2;
	*choose1 = tempchoose1;
	*choose2 = tempchoose2;
}