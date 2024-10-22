/*
	Description: This file contains the function to display the game board in Jeopardy.
	Programmed by: Mikaela Nicole B. Amon S21B
	Last modified: November 23, 2023
	Version: 1.0
*/

#include <stdio.h>
#include "MPheader.h"

/*
	This function displays the game board for the game. It also shows which questions have already been answered or is still available
	for the player.
	Precondition: All integer variables are greater than zero, and all character variables range from A to C only.
	@param nCategorySet  - The chosen set of categories at the start of the round.
						- 1 = Categories 1, 2, and 3 are chosen for the game.
						- 2 = Categories 1, 3, and 4 are chosen for the game.
						- 3 = Categories 1, 2, and 4 are chosen for the game.
						- 4 = Categories 2, 3, and 4 are chosen for the game.
	@param round - represents a number for the current round.
				 - 1 = Jeopardy Round
				 - 2 = Double Round
				 - 3 = Final Jeopardy
	@param nAnswered1 - The value amount of the first answered question.
	@param nAnswered2 - The value amount of the second answered question.
	@param nAnswered3 - The value amount of the third answered question.
	@param cAnswered1 - The category of the first answered question.
	@param cAnswered2 - The category of the second answered question.
	@param cAnswered3 - The category of the third answered question.
*/
void displayGameBoard(int nCategorySet, int round, int nAnswered1, int nAnswered2, int nAnswered3, char cAnswered1, char cAnswered2, char cAnswered3)
{
	/* Integer variables i and j are for the loops, num(1-3) is the category of the answered question in integers.
	   i represents the number of rows of the board, while j represents the number of columns. */
	int i, j, num1, num2, num3;
	
	/* Switch cases for each cAnswered variable. 
		  'A' will be converted to 1	     
		  'B' will be converted to 2		 
		  'C' will be converted to 3 */
	switch(cAnswered1)
	{
		case 'A':
			num1 = 1;
			break;
		case 'B':
			num1 = 2;
			break;
		case 'C':
			num1 = 3;
			break;
	}
	
	switch(cAnswered2)
	{
		case 'A':
			num2 = 1;
			break;
		case 'B':
			num2 = 2;
			break;
		case 'C':
			num2 = 3;
			break;
	}
	
	switch(cAnswered3)
	{
		case 'A':
			num3 = 1;
			break;
		case 'B':
			num3 = 2;
			break;
		case 'C':
			num3 = 3;
			break;
	}

	printf("\n=-----------------------------------------------------------=\n");
	
	// Different sets of categories will be shown depending on the value of nCategorySet.
	if (nCategorySet == 1)
	{
		printf("|   [A] World       |   [B] Food        |   [C] Science     |\n");
		printf("|       Capitals    |       Trivia      |       & Nature    |\n");
	}
	if (nCategorySet == 2)
	{
		printf("|   [A] World       |   [B] Science     |   [C] Idioms      |\n");
		printf("|       Capitals    |       & Nature    |       & Phrases   |\n");
	}
	if (nCategorySet == 3)
	{
		printf("|   [A] World       |   [B] Food        |   [C] Idioms      |\n");
		printf("|       Capitals    |       Trivia      |       & Phrases   |\n");	
	}
	if (nCategorySet == 4)
	{
		printf("|   [A] Food        |   [B] Science     |   [C] Idioms      |\n");
		printf("|       Trivia      |       & Nature    |       & Phrases   |\n");
	}
	
	// If it is Jeopardy Round, execute this for-loop.
	if (round == 1)
	{
	    printf("|-----------------------------------------------------------|\n");
	    
	    // This loop will be for the generation of the rows of the table.
	    for (i = 1; i <= 5; i++) 
		{
			// This nested loop will be for the generation of the columns of the table.
	        for (j = 1; j <= 3; j++) 
			{
	            printf("|     ");
	            /* If the current row (i) is within the current row of the answered question AND 
	               If current column (j) is within the current column of the answered question,  
	               Print DONE. */
	            if ((i == nAnswered1 && j == num1) || (i == nAnswered2 && j == num2) || (i == nAnswered3 && j == num3))
	            	printf(" [DONE] ");
				else // If none of the conditions are true, simply print the value amount and its corresponding number.
					printf("[%d] $%d", i, i * 200);
				
				// For consistent spacing.
				if ((i != 5) || ((i == nAnswered1 && j == num1) || (i == nAnswered2 && j == num2) || (i == nAnswered3 && j == num3)))
					printf("      ");
				else
					printf("     ");
			}
	        printf("|\n");
	        if (i == 5)
	        	printf("=-----------------------------------------------------------=\n");
	        else
		        printf("|-----------------------------------------------------------|\n");
   		}	
	}
	// If it is Double Round, execute this for-loop.
	if (round == 2)
	{
		printf("|-----------------------------------------------------------|\n");
	    // This loop will be for the generation of the rows of the table.
		for (i = 1; i <= 3; i++) 
		{
			// This nested loop will be for the generation of the columns of the table.
	        for (j = 1; j <= 3; j++) 
			{
				/* If the current row (i) is within the current row of the answered question AND 
	               If current column (j) is within the current column of the answered question,  
	               Print DONE. */
	            printf("|     ");
	            if (i == nAnswered1 && j == num1)
	            	printf(" [DONE] ");
				else // If none of the conditions are true, simply print the value amount and its corresponding number.
					printf("[%d] $%d", i, i * 400);
				// For consistent spacing
				if ((i != 3) || (i == nAnswered1 && j == num1))
					printf("      ");
				else
					printf("     ");
			}
	        printf("|\n");
	        if (i == 3)
	        	printf("=-----------------------------------------------------------=\n");
	        else 
		        printf("|-----------------------------------------------------------|\n");
   		}	
	}
	// If it is Final Jeopardy, execute this for-loop. 
	if (round == 3)
	{
		printf("|-----------------------------------------------------------|\n");
	    // This loop will be for the generation of the rows of the table.
		for (i = 1; i <= 2; i++)
		{
			// This nested loop will be for the generation of the columns of the table.
	        for (j = 1; j <= 3; j++)
			{
	            printf("|     ");
	            /* If the current row (i) is within the current row of the answered question AND
	               If current column (j) is within the current column of the answered question,
	               Print DONE. */
	            if ((i == nAnswered1 && j == num1) || (i == nAnswered2 && j == num2) || (i == nAnswered3 && j == num3))
	            	printf(" [DONE] ");
				else // If none of the conditions are true, simply print the value amount and its corresponding number.
					printf("[%d] $%d", i, i * 2500);
				// For consistent spacing
				if ((i == nAnswered1 && j == num1) || (i == nAnswered2 && j == num2) || (i == nAnswered3 && j == num3))
					printf("      ");
				else
					printf("     ");
			}
	        printf("|\n");
	        if (i == 2)
	        	printf("=-----------------------------------------------------------=\n");
	        else
		        printf("|-----------------------------------------------------------|\n");
   		}	
	}
}