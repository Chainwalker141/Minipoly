#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"

int main()
{
	int gameMode;

	int totalP1 = 1; // player 1 movement
	int totalP2 = 1; // player 2 movement
	char player1 = '1';
	char player2 = '2';
	char p1Props = 'X';
	char p2Props = 'Y';

	int balanceP1 = 10000000; // 10m each
	int balanceP2 = 10000000;
	char action;
	char rows[6][6] = {
                        {' ', ' ', ' ', ' ', ' ', ' '}, // row 1
                        {' ',' '}, // row 2
                        {' ',' '}, // row 3
                        {' ',' '}, // row 4
                        {' ',' '}, // row 5
                        {' ', ' ', ' ', ' ', ' ', ' '} // row 6
                      };
	char properties[6][6] = {
								{' ', ' ', ' ', ' ', ' ', ' '}, 
								{' ',' '}, 
								{' ',' '}, 
								{' ',' '}, 
								{' ',' '}, 
								{' ', ' ', ' ', ' ', ' ', ' '} 
                      		};
	
	gameMode = mainMenu();
	
	// determines what mode is inputted
	switch(gameMode)
	{
		case 1: // how to play
			printf("1");
			break;
		case 2: // play game
			while(balanceP1 > 0 && balanceP2 > 0)
			{
				movement(totalP1, rows, player1);
				board(rows, properties);
				action = userInterface(balanceP1, balanceP2);
				int roll;

				if(action == 'R' || action == 'r')
				{

					roll = diceRoll();
					totalP1 = (totalP1 + roll) % 20;
					if (totalP1 == 0)
					{
						totalP1 = 20; // if total becomes 20 % 20 which results 0
					}
					else
					{
						totalP1;
					}
					
					movement(totalP1, rows, player1);

					printf("You rolled a: %d\n", roll);
					printf("You are now on tile: %d\n", totalP1);
					
				}
				else if(action == 'B' || action == 'b')
				{
					buyProperty(&balanceP1, totalP1, properties, p1Props);
				}
			}

			winner(balanceP1, balanceP2); // to decide winner
			
			break;
		case 3: // debug mode
			printf("3");
			break;
	}
    
    return 0;
}