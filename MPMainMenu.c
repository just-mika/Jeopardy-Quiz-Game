/*
	Description: This file contains the functions for the main menu and the 'How to Play?' option in Jeopardy.
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

//This function displays the title of the game.
void displayTitle() 
{
	printf("\n  #####  ######   ####   #####    ####   #####   #####   #    #  ##");
	printf("\n     #   #       #    #  #    #  #    #  #    #  #    #  #    #  ##");
	printf("\n     #   ####    #    #  #####   ######  #####   #    #   ####   ##");
	printf("\n#    #   #       #    #  #       #    #  #    #  #    #    ##     ");
	printf("\n ####    ######   ####   #       #    #  #    #  #####     ##    ##\n");
}

//This function displays the selections in the Main Menu.
void displayMainMenu() 
{
	printf("\n");
	printf("Main Menu Select:\n");
	printf("How to play? [H]\n");
	printf("Play Game [P]\n");
	printf("Quit [X]\n");
}

//This function displays the How to Play option in the main menu.
void displayHowToPlay() 
{	
	char selection; //declare variable for the selection of the sub-menus.
	printf("-----------------------------------------------------------------------------\n");
	printf("\n  JEOPARDY! is a quiz game where players compete by answering questions from\n");
	printf("a variety of different categories. In this game, there will be a game board\n");
	printf("containing a grid of squares which contains the questions available for that\n");
	printf("round. The columns represent which category the question belongs to, and the\n");
	printf("rows represent the question dollar value amount.\n");
	
	sleep(6); //sleep function to pause in between paragraphs for 6 seconds.
	
	printf("\n  The player is free to choose which questions they would like to answer,\n"); 
	printf("and if they answer correctly, the player will earn the dollar amount. But if\n");
	printf("their answer is incorrect, the player\'s score is either left unchanged or\n");
	printf("deducted (depending on the current round), and the question is open to the\n");
	printf("other player. The player with the highest score at the end of the final round\n");
	printf("wins the game.\n");
	
	sleep(6);//sleep function to pause in between paragraphs for 6 seconds.
	
	printf("\n[Note: While this game is inspired by the renowned American television game\n");
	printf("show, Jeopardy, it is NOT a direct simulation of it. This game has its own \n"); 
	printf("set of rules and mechanics.]\n");
	
	sleep(4);//sleep function to pause for 4 seconds before showing the selection.
	
	printf("\n-----------------------------------------------------------------------------");
	
	do //execute loop statement at least once.
	{
		printf("\nSelect:\n");
		printf("Choosing a Question [C]\n");
		printf("Overview of the Rounds [R]\n");
		printf("Player Modes [P]\n");
		printf("Return to Main Menu [M]\n");

		/* Enter input for the selection.    */
		/* The function getChar() is called. */
		printf("\nEnter: ");
		selection = getChar();
		
		/* Switch statement for the selection. */
		switch (selection)
		{
			//If selection is C, show how to choose a question.
			case 'c':
			case 'C':
				printf("-----------------------------------------------------------------------------\n");
				printf("\nAs mentioned before, this game will have a game board, which contains a grid\n");
				printf("of squares that represents a question.\n");
				
				sleep (3);//sleep function to pause for 3 seconds before showing sample gameboard.
				
				printf("\nSample Gameboard:\n");
				
				printf("\n=-----------------------------------------------------------=\n");
				printf("|    [A] History    |  [B] Pop Trivia   |   [C] Astronomy   | <---- |These are the three      |\n");
				printf("|-----------------------------------------------------------|       |categories that are the  |\n");
				printf("|     [1] $200      |     [1] $200      |     [1] $200      |       |subjects of the questions|\n");
				printf("|-----------------------------------------------------------|       |for the entire game.     |\n");
				printf("|     [2] $400      |     [2] $400      |     [2] $400      |\n");
				printf("|-----------------------------------------------------------|\n");
				printf("|     [3] $600      |     [3] $600      |     [3] $600      |<---|The questions in this   |\n");
				printf("|-----------------------------------------------------------|    |entire row have a dollar|\n");
				printf("|     [4] $800      |     [4] $800      |     [4] $800      |    |value amount of $600.   |\n");
				printf("|-----------------------------------------------------------|\n");
				printf("|     [5] $1000     |     [5] $1000     |     [5] $1000     |\n");
				printf("=-----------------------------------------------------------=\n");
				printf("                               ^\n");
				printf("                               |\n");
				printf("                    |All of the questions in |\n");
				printf("                    |this column is related  |\n");
				printf("                    |to Pop Trivia.          |\n");
				
				sleep (5);//sleep function to pause for 5 seconds before showing text.
				printf("\nIn choosing a question, the player must decide which category the question\n");
				printf("will be about and the value amount they wish to earn.\n");
				
				sleep (3);//sleep function to pause for 3 seconds before showing text.
				
				printf("\nFor example, you want the question to be about Pop Trivia, and you want to earn $600.\n");
				printf("Then, for you to choose the question, you must type the corresponding letter or number\n");
				printf("your desired question belongs to.\n");
				
				sleep(4);//sleep function to pause for 4 seconds before showing the instruction.
				
				printf("\nExample:\n");
				printf("Select a category [A to C]: B <--------- |Player should the letter 'B' or 'b'|\n");
				printf("Select a value amount [1 to 5]: 3        |since the letter represents the Pop|\n");
				printf("                                ^        |Trivia category.                   |\n");
				printf("                                |\n");
				printf("                    |To select the value amount   |\n");
				printf("                    |$600, Player should input    |\n");
				printf("                    |the number 3 which represents|\n");
				printf("                    |said value amount.           |\n");
				
				sleep (5);//sleep function to pause for 5 seconds at the end.
				break;
			//If selection is R, show the overview of the rounds.
			case 'r':
			case 'R':
			{
				printf("-----------------------------------------------------------------------------\n");
				printf("\nThe game consists of three rounds:\n");
				sleep(3);//sleep function to pause for 3 seconds before showing text.
				printf("\n1. Jeopardy Round");
				sleep(2);//sleep function to pause for 2 seconds before showing text.
				printf("\n    The game begins with the Jeopardy Round. In this round, there are five (5)\n");
				printf("  questions given per category, having a total of 15 questions to choose from at\n");
				printf("  the start of the game. Each of these questions have value amounts of either\n");
				printf("  $200, $400, $600, $800, and $1000. The player(s) may only answer four (4)\n");
				printf("  questions in total for this round.\n");
				sleep(6);//sleep function to pause for 6 seconds before showing text.
				printf("\n    The player(s) have the freedom to choose which category and the value of\n");
				printf("  the question they wish to answer. If they got the answer correctly, the value\n");
				printf("  amount chosen will be added up to their current score. If not, then their.\n");
				printf("  current score remains the same.\n");
				sleep(5);//sleep function to pause for 5 seconds before showing text.
				
				printf("\n2. Double Round");
				sleep(2);//sleep function to pause for 2 seconds before showing text.
				printf("\n    After the Jeopardy round, the game will then begin the Double Round. In\n");
				printf("  this round, there are three (3) questions given per category, having a total\n");
				printf("  of 9 questions to choose from. Each question has the value amounts of either\n");
				printf("  $400, $800, and $1200. The player(s) may only answer two (2) questions for\n");
				printf("  this round.\n");
				sleep(6);//sleep function to pause for 6 seconds before showing text.
				printf("\n    The scoring for this round differs from the previous round. If the player\n");
				printf("  answers a question correctly, the score they earn will be double the sum of\n");
				printf("  the player\'s current score and the value amount chosen.\n");
				sleep(5);//sleep function to pause for 5 seconds before showing text.
				printf("\n    In short: Earned score = 2 x (Current Score + Value Amount)\n");
				sleep(4);//sleep function to pause for 4 seconds before showing text.
				printf("\n    However, if the player\'s answer to the question is incorrect, they will\n");
				printf("  lose ALL of their points up to that point, so be careful and choose your\n");
				printf("  questions wisely!\n");
				sleep(5);//sleep function to pause for 5 seconds before showing text.
				
				printf("\n3. Final Jeopardy");
				sleep(2);//sleep function to pause for 2 seconds before showing text.
				printf("\n    This is the final round of the game, with only two (2) questions given per\n");
				printf("  category, having a total of 6 questions to choose from. Each question has the\n");
				printf("  value amounts of either $2500 or $5000. The player(s) will only answer one (1)\n");
				printf("  question for this round.\n");
				sleep(6);//sleep function to pause for 6 seconds before showing text.
				printf("\n    In this round, the player(s) are given the choice of whether or not they\n");
				printf("  want to wager a portion or the entirety of their current score. If they do\n");
				printf("  choose to wager, their wager amount will be the score they will earn once they\n");
				printf("  answer the question correctly. If they don\'t choose to wager or if they\n");
				printf("  don\'t have any points to wager, they may simply earn the value of the chosen\n");
				printf("  question.\n");
				sleep(6);//sleep function to pause for 6 seconds before showing text.
				printf("\n    Just like in the Double round, if the player\'s chosen answer is wrong,\n");
				printf("  they will lose all of their points, so be careful!\n");
				sleep(5);//sleep function to pause for 5 seconds before showing text.
				
				printf("\n3.1. Tiebreaker Round");
				sleep(2);//sleep function to pause for 2 seconds before showing text.
				printf("\n    If there are 2 players and the Final Jeopardy results in a tie, the game\n");
				printf("  will enter a Tiebreaker round. This round is basically the same as the Final\n");
				printf("  Jeopardy, and it will use the same game board as the one used in the previous\n");
				printf("  round. The tiebreaker round can only be repeated 3 times. Otherwise, if there\n");
				printf("  is still a tie after 3 times, the result will be forced to a draw.\n");
				sleep(6);//sleep function to pause for 6 seconds at the end.
				break;
			}
			//If selection is P, show Player Modes
			case 'p':
			case 'P':
				printf("-----------------------------------------------------------------------------\n");
				printf("\nBefore the game begins, you are asked how many players are going to play the game.\n");
				sleep(3);//sleep function to pause for 3 seconds before showing text.
				printf("\n1. One player mode");
				sleep(2);//sleep function to pause for 2 seconds before showing text.
				printf("\n    If only one player will play the game, the sequence of the game will be\n");
				printf("  played normally. They are asked to choose a question, and regardless of\n");
				printf("  whether or not they are correct or not, they will choose the next question to\n");
				printf("  answer.\n");
				sleep(5);//sleep function to pause for 5 seconds before showing text.
				
				printf("\n1. Two player mode");
				sleep(2);//sleep function to pause for 2 seconds before showing text.
				printf("\n    The game works a bit differently when there are two players. At the beginning\n");
				printf("  of each round, Player 1 will be the first to choose a question. If Player 1\n");
				printf("  answers correctly, The next player, Player 2, will choose the next question.\n");
				printf("  And after Player 2 correctly answers the question, it\'s Player 1\'s turn again.\n");
				sleep(6);//sleep function to pause for 6 seconds before showing text.
				printf("\n    However, if Player 1\'s answer is incorrect, Player 2 must answer the same\n");
				printf("  question that Player 1 chose.");
				sleep(3);//sleep function to pause for 3 seconds before showing text.
				printf("\n    - If Player 2\'s answer is correct, Player 2 earns the score instead of\n");
				printf("       Player 1, and it\'s Player 2\'s turn to choose and answer another question.\n");
				sleep(4);//sleep function to pause for 4 seconds before showing text.
				printf("\n    - If Player 2\'s answer is also incorrect, then it\'s Player 1\'s turn again to\n");
				printf("       choose and answer another question.\n");
				sleep(4);//sleep function to pause for 4 seconds before showing text.
				printf("\n  This also applies to Player 2 if their answer to their chosen question is incorrect.\n");
				sleep(3);//sleep function to pause for 3 seconds before showing text.
				printf("\n    For the Final Jeopardy, since only one question will be answered, both players\n");
				printf("  will give their answers before revealing if their answers are correct or not.\n");
				sleep(4);//sleep function to pause for 4 seconds at the end.
				break;
			//If selection is M, break the statement.	
			case 'm':
			case 'M':
				break;
			//If selection is none of the choices, invalid input.
			default:
				printf("Invalid input!\n");
				break;
		}
		printf("-----------------------------------------------------------------------------");
	} while (selection != 'm' && selection != 'M'); //loop the statement as long as selection is not M.
}