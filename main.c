#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"

int main()
{
	int gameMode;

	int totalP1 = 0; // player 1 movement
	int totalP2 = 0; // player 2 movement
	char player1 = '1';
	char player2 = '2';
	char p1Props = 'X';
	char p2Props = 'Y';

	int balanceP1 = 10000000; // 10m each
	int balanceP2 = 10000000;
	int roll;
	char action;
	char rows[20] = {' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ',' ', ' ',' ', 
						' ',' ', ' ', ' ', ' ', ' ', ' ', ' '};
	
	char properties[20] = {' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ',' ', ' ',
							 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	
	gameMode = mainMenu();

	while(gameMode <= 0 || gameMode > 3)  // for invalid number inputs
    {
		printf("\nInvalid Selection, try again: ");
		scanf("%d", &gameMode);
	}
	
	// determines what mode is inputted
	switch(gameMode)
	{
		case 1: // how to play
			printf("1");
			break;
		case 2: // play game
			while(balanceP1 > 0 && balanceP2 > 0)
			{	
				// player 1 turn
				checkJail(totalP1, rows); // checks if you're on the go to jail tile

				if(checkJail(totalP1, rows) == 1)
				{
					totalP1 = 5;
					rows[5] = player1;
					printf("You are in jail and cannot move for 2 turns");
				}
				else
				{
					movement(totalP1, totalP2, rows, player1, player2);
					board(rows, properties);
					
					action = userInterface(balanceP1, balanceP2);
					
					if(action == 'R' || action == 'r')
					{
						roll = diceRoll();
						totalP1 = (totalP1 + roll) % 20; // 20 % 20 = 0 which is the go tile
						
						movement(totalP1, totalP2, rows, player1, player2);
						checkTax(&balanceP1, totalP1);
						rent(totalP1, &balanceP1, p2Props, properties);

						printf("You rolled a: %d\n", roll);
						printf("You are now on tile: %d\n", totalP1);
					}
					else if(action == 'B' || action == 'b')
					{
						buyProperty(&balanceP1, totalP1, properties, p1Props);
					}
					else
					{
						printf("Invalid input, Please try again: ");
						scanf("%d", &action);
					}
				}
			}

			winner(balanceP1, balanceP2); // to decide winner
			
			break;
		case 3: // debug mode
			/*
			while(balanceP1 > 0 && balanceP2 > 0)
			{	
				// player 1 turn
				checkJail(totalP1, rows); // checks if you're on the go to jail tile

				if(checkJail(totalP1, rows) == 1)
				{
					totalP1 = 5;
					rows[5] = player1;
					printf("You are in jail and cannot move for 2 turns");
				}
				else
				{
					movement(totalP1, totalP2, rows, player1, player2);
					board(rows, properties);
					
					action = userInterface(balanceP1, balanceP2);
					
					if(action == 'R' || action == 'r')
					{
						roll = debugRoll();
						totalP1 = (totalP1 + roll) % 20; // 20 % 20 = 0 which is the go tile
						
						movement(totalP1, totalP2, rows, player1, player2);
						checkTax(&balanceP1, totalP1);
						rent(totalP1, &balanceP1, p2Props, properties);

						printf("You rolled a: %d\n", roll);
						printf("You are now on tile: %d\n", totalP1);
					}
					else if(action == 'B' || action == 'b')
					{
						buyProperty(&balanceP1, totalP1, properties, p1Props);
					}
				}
			}

			winner(balanceP1, balanceP2); // to decide winner
			*/
			break;
	}
    
    return 0;
}