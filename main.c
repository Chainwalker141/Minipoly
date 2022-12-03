#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"

int main()
{
	int gameMode;

	int totalMovesP1 = 1; // player 1 movement starts at 1, the GO tile
	int totalMovesP2 = 1; // player 2 movement starts at 1, the GO tile
	char player1 = '1';
	char player2 = '2';
	char propertiesP1 = 'X';
	char propertiesP2 = 'Y';
	int jailTimeP1 = 3;
	int jailTimeP2 = 3;

	int balanceP1 = 10000000; // 10m each player
	int balanceP2 = 10000000;
	int roll;
	char action;
	char movementTiles[21] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	
	char properties[21] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	
	gameMode = mainMenu();

	while(gameMode <= 0 || gameMode > 4)  // for invalid number inputs
    {
		printf("\nInvalid Selection, try again: ");
		scanf("%d", &gameMode);
	}
	
	// determines what mode is inputted
	switch(gameMode)
	{
		case 1: // how to play (no break as to continue after user input)
			howToPlay(); 
		case 2: // play game
			while(balanceP1 > 0 && balanceP2 > 0)
			{	
				/*        start of player 1 turn        */
				if(jailTimeP1 <= 2 && jailTimeP1 > 0) // if player is in jail
				{
					inJail(&totalMovesP1, &jailTimeP1, movementTiles, player1);
				}
				else
				{
					jailTimeP1 = 3; // resets jail counter if player went to jail
					movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
					board(movementTiles, properties);

					do
					{
						action = userInterface(balanceP1, balanceP2, player1);
						
						switch(action)
						{
							case 1:
								roll = diceRoll();
								passedGo(&balanceP1, totalMovesP1, roll, player1);

								if (totalMovesP1 + roll >= 21)
								{
									totalMovesP1 = (totalMovesP1 + roll) % 21 + 1; // to prevent a totalMoves of 0
								}
								else
								{
									totalMovesP1 = (totalMovesP1 + roll) % 21;
								}
								
								movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
								checkTax(&balanceP1, totalMovesP1, player1);
								rent(totalMovesP1, &balanceP1, &balanceP2, propertiesP2, properties, player1, player2);

								if(checkJail(totalMovesP1) == 1) // checks if player landed on go to jail tile
								{	
									actionLog(player1, roll, totalMovesP1);
									inJail(&totalMovesP1, &jailTimeP1, movementTiles, player1);
								}
								else
								{
									actionLog(player1, roll, totalMovesP1);
								}
								break;
							case 2:	
								buyProperty(&balanceP1, totalMovesP1, properties, propertiesP1, propertiesP2, player1);
								board(movementTiles, properties);
								break;
							default:
								printf("\nInvalid Selection, try again\n\n");
								break;
						}
					}while(action != 1);
				}

				/*        start of player 2 turn        */
				if(jailTimeP2 <= 2 && jailTimeP2 > 0) 
				{	
					inJail(&totalMovesP2, &jailTimeP2, movementTiles, player2);
				}
				else
				{
					jailTimeP2 = 3; // resets jail counter if player went to jail
					movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
					board(movementTiles, properties);
					
					do
					{
						action = userInterface(balanceP1, balanceP2, player2);
						
						switch(action)
						{
							case 1: // Roll the dice
								roll = diceRoll();
								passedGo(&balanceP2, totalMovesP2, roll, player2);
								if (totalMovesP2 + roll >= 21)
								{
									totalMovesP2 = (totalMovesP2 + roll) % 21 + 1; // to prevent a totalMoves of 0
								}
								else
								{
									totalMovesP2 = (totalMovesP2 + roll) % 21;
								}
								movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
								checkTax(&balanceP2, totalMovesP2, player2);
								rent(totalMovesP2, &balanceP2, &balanceP1, propertiesP1, properties, player2, player1);

								if(checkJail(totalMovesP2) == 1) // checks if player landed on go to jail tile
								{	
									actionLog(player2, roll, totalMovesP2);
									inJail(&totalMovesP2, &jailTimeP2, movementTiles, player2);
								}
								else
								{
									actionLog(player2, roll, totalMovesP2);
								}
								break;
							case 2: // Buy a property then roll the dice
								buyProperty(&balanceP2, totalMovesP2, properties, propertiesP2, propertiesP1, player2);
								board(movementTiles, properties);
								break;
							default:
								printf("\nInvalid Selection, try again\n\n");
								break;
						}
					}while(action != 1);
				}
			}
			displayWinner(balanceP1, balanceP2); // to decide winner
			break;
			
		case 3: // debug mode
			while(balanceP1 > 0 && balanceP2 > 0)
			{	
				/*        start of player 1 turn        */
				if(jailTimeP1 <= 2 && jailTimeP1 > 0) // if player is in jail
				{
					inJail(&totalMovesP1, &jailTimeP1, movementTiles, player1);
				}
				else
				{
					jailTimeP1 = 3; // resets jail counter if player went to jail
					movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
					board(movementTiles, properties);
					
					do
					{
						action = userInterface(balanceP1, balanceP2, player1);
						
						switch(action)
						{
							case 1:
								roll = debugRoll();
								passedGo(&balanceP1, totalMovesP1, roll, player1);
								totalMovesP1 = roll % 21; // 21 % 21 + 1 = 1 which is the go tile
								
								movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
								checkTax(&balanceP1, totalMovesP1, player1);
								rent(totalMovesP1, &balanceP1, &balanceP2, propertiesP2, properties, player1, player2);

								if(checkJail(totalMovesP1) == 1) // checks if player landed on go to jail tile
								{	
									actionLog(player1, roll, totalMovesP1);
									inJail(&totalMovesP1, &jailTimeP1, movementTiles, player1);
								}
								else
								{
									actionLog(player1, roll, totalMovesP1);
								}
								break;
							case 2:
								buyProperty(&balanceP1, totalMovesP1, properties, propertiesP1, propertiesP2, player1);
								board(movementTiles, properties);
								break;
							default:
									printf("\nInvalid Selection, try again\n\n");
									break;
						}
					}while(action != 1);
				}

				/*        start of player 2 turn        */
				if(jailTimeP2 <= 2 && jailTimeP2 > 0) 
				{	
					inJail(&totalMovesP2, &jailTimeP2, movementTiles, player2);
				}
				else
				{
					jailTimeP2 = 3; // resets jail counter if player went to jail
					movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
					board(movementTiles, properties);
					
					do
					{
						action = userInterface(balanceP1, balanceP2, player2);
						
						switch(action)
						{
							case 1:
								roll = debugRoll();
								passedGo(&balanceP2, totalMovesP2, roll, player2);
								totalMovesP2 = roll % 21; // 21 % 21 = 1 which is the go tile
								
								movement(totalMovesP1, totalMovesP2, movementTiles, player1, player2);
								checkTax(&balanceP2, totalMovesP2, player2);
								rent(totalMovesP2, &balanceP2, &balanceP1, propertiesP1, properties, player2, player1);

								if(checkJail(totalMovesP2) == 1)
								{	
									actionLog(player2, roll, totalMovesP2);
									inJail(&totalMovesP2, &jailTimeP2, movementTiles, player2);
								}
								else
								{
									actionLog(player2, roll, totalMovesP2);
								}
								break;
							case 2:
								buyProperty(&balanceP2, totalMovesP2, properties, propertiesP2, propertiesP1, player2);
								board(movementTiles, properties);
								break;
							default:
									printf("\nInvalid Selection, try again\n\n");
									break;
						}
					}while(action != 1);
				}
			}
			displayWinner(balanceP1, balanceP2); // to decide winner
			break;

		case 4:
			printf("\nThank you for playing! :)\n\n");
	}
	return 0;
}