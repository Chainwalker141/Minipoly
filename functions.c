#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int mainMenu();
void board(char[21], char [21]);
void clearBoard(char[21]);
void movement(int, int, char[21], char, char);
void rent(int, int*, int*, char, char[21], char, char);
int checkJail(int);
void inJail(int*, int*, char[21], char);
void passedGo(int*, int, int, char);
void debugPassedGo(int*, int, char);
void checkTax(int*, int, char);
void buyProperty(int*, int, char[21], char, char, char);
int diceRoll();
int debugRoll();
int userInterface(float, float, char);
void actionLog(char, int, int);
void displayWinner(int, int);

/*  Displays the main menu and returns the selected game mode
    @returns the selected game mode
*/
int mainMenu()
{
	int selectedMode;
	
	// main menu display
    printf("\nWelcome to Minipoly!\n");
    printf("A Game by Joaquin Sinjian\n");
    printf("Of Section S21B\n\n");
    printf("==============================\n\n");
    printf("Choose a Mode\n");
    printf("[1] How to Play\n");
	printf("[2] Play Mode\n");
	printf("[3] Debug Mode\n");
    printf("[4] Quit\n");
    
    printf("Enter Number: ");
    scanf("%d", &selectedMode);

	return selectedMode;
}

/*  Displays the intructions
	Pre-condition: the player types '1' in the main menu
*/
void howToPlay()
{
	char back[50]; // to prevent any problems~

    printf("\n\nTHE GAME\n\n");
	printf("MiniPoly is a faster paced, 2 player version of a very certain boardgame that\n");
	printf("shall not be named due to legal reasons.\n\n");

	printf("THE PLAYERS\n\n");

	printf("- Player 1 is denoted as '1' and Player 2 as '2'. Their properties.\n");
	printf("  are denoted as 'X' and 'Y' respectively. A '3' will be displayed if the players\n");
	printf("  happen to be on the same tile\n\n");

	printf("- Players will start on tile 0 also known as the 'GO' tile which is denoted by 'G'\n");
	printf("- Properties are named after the corresponding letter on the outskirts of the board\n");
	printf("  and are named starting from 2 up to 20\n\n");

	printf("- Players will also start with 10000000 (10 Million) in their accounts denoted as 'Balance'\n\n");

    printf("Type anything to continue\n");
    scanf("\n%s", &back[1]);

	printf("\n\nSPECIAL TILES\n\n");

	printf("1. The 'G' tile\n");
	printf("- If the player lands or passes this tile, they will be rewarded 1000000 (1 Million)\n\n");

	printf("2. The 'J' and 'V' tiles\n");
	printf("- If the player lands on the tile with the letter J on it, tile 16, the player will be arrested and\n");
	printf("- shall be sent to the upper right corner of the board, the 'V' tile a.k.a. the 'Just visiting' tile\n");
	printf("  and will not be able to play their turn for 2 turns\n");
	printf("- Note that if the player lands on the 'V' tile, they are not arested and would go on as normal\n\n");

	printf("3. The 'T' tile\n");
	printf("- If the player lands on this tile, they will have to pay a hefty sum of 1000000 (1 Million)\n\n");

	printf("4. The 'P' tile\n");
	printf("- Allan please add details\n"); // heh
	printf("- References aside, this tile does nothing\n\n");

    printf("Type anything to continue\n");
    scanf("\n%s", &back[2]);

	printf("\n\nBUYING PROPERTIES\n\n");

	printf("- Players may buy the lettered properties on the board (a-o)\n");
	printf("- If their opponent lands on a bought property, their opponent will pay a certain ammount a.k.a. 'rent'\n");
    printf("- If you land on your own property, nothing happens\n");
	printf("- However, buying properties is not free! The player has to pay a certain amount to own a property\n");
    printf("- PROPERTIES MAY ONLY BE BOUGHT ON SUBSEQUENT TURNS (cannot buy after rolling the dice)\n\n");

	printf("PROPERTY COSTS\n\n");

	printf("Proprties a - d = 2000000 (2 Million)\n");
	printf("Proprties e - h = 4000000 (4 Million)\n");
	printf("Proprties i - l = 6000000 (6 Million)\n");
	printf("Proprties m - o = 8000000 (8 Million)\n\n");

	printf("RENTING\n\n");

	printf("Proprties a - d = 300000 (300 Thousand)\n");
	printf("Proprties e - h = 500000 (500 Thousand)\n");
	printf("Proprties i - l = 1000000 (1 Million)\n");
	printf("Proprties m - o = 2000000 (2 Million)\n\n");

	printf("WINNING\n\n");

	printf("- A player wins if their opponent's balance reaches or goes below 0\n\n");

	printf("Are you ready to play? Type anything to start!\n");
	scanf("\n%s", &back[3]);
}

/*  Displays the entire board
    @param tiles[21] - The locations where the players will move
    @param properties[21] - The locations where bought properties are found
*/
void board(char tiles[21], char properties[21])
{
	printf("\n        e   f   g   h        \n"); 
	printf("  +---+---+---+---+---+---+  \n"); 
	printf("  |%c V|%c %c|%c %c|%c %c|%c %c|%c P|  \n", tiles[6], tiles[7], properties[7], tiles[8], properties[8], 
                                                            tiles[9], properties[9], tiles[10], properties[10], tiles[11]);
	printf("  +---+---+---+---+---+---+  \n");
	printf(" d|%c %c|               |%c %c|i \n", tiles[5], properties[5], tiles[12], properties[12]);
	printf("  +---+               +---+  \n");
	printf(" c|%c %c|               |%c %c|j \n", tiles[4], properties[4], tiles[13], properties[13]);
	printf("  +---+               +---+  \n");
	printf(" b|%c %c|               |%c %c|k \n", tiles[3], properties[3], tiles[14], properties[14]);
	printf("  +---+               +---+  \n");
	printf(" a|%c %c|               |%c %c|l \n", tiles[2], properties[2], tiles[15], properties[15]);
	printf("  +---+---+---+---+---+---+  \n");
	printf("  |%c G|%c %c|%c T|%c %c|%c %c|%c J|  \n", tiles[1], tiles[20], properties[20], tiles[19], tiles[18], properties[18], 
                                                            tiles[17], properties[17], tiles[16]);
	printf("  +---+---+---+---+---+---+  \n");
	printf("        o       n   m        \n");
}

/*  Function that clears the board to help simulate player movement
    @param tiles[21] - The tiles of the board
*/
void clearBoard(char tiles[21])
{
    int i;

    for(i = 0; i < 21; i++) // 21 tiles of the board (including 0)
    {
       tiles[i] = ' ';
    }
}

/*  Simulates a 6-sided die by giving a random number
    @returns the given diceroll number
*/ 
int diceRoll()
{
	int diceRoll;

	srand(time(0));
	
	diceRoll = (rand() % 6) + 1; // adds 1 to prevent an output of 0 

	return diceRoll;
}

/*  Allows the user to go to any tile. Only used in debugging
    Pre-Condition: The user inputs a number between 1-20
    @returns the inputted number
*/ 
int debugRoll()
{
    int number;

    printf("Enter a tile a tile to go to (1-20): ");
    scanf("%d", &number);

	while(number <= 0 || number > 20)  // for invalid number inputs
    {
		printf("\nInvalid Selection, try again: ");
		scanf("%d", &number);
	}

    return number;
}

/*  Displays the User Interface during gameplay and returns the inputted action
    Pre-Condition: action inputted are only the numbers enclosed in brackets
    @param balanceP1 - to display the current balance of the first player
    @param balanceP2 - to display the current balance of the second player
    @param player - Determines the current player
    @returns the inputted action
*/
int userInterface(float balanceP1, float balanceP2, char player)
{
	int action;
    printf("It is now Player %c's turn", player);
	printf("\nAccount Balance:\n");
	printf("Player 1: %.2f\n", balanceP1);
	printf("Player 2: %.2f\n\n", balanceP2);
	printf("Actions\n");
	printf("[1] Roll the Dice\n");
	printf("[2] Buy Property\n");
	printf("Input: ");
	scanf("%d", &action);

	return action;
}

/*	Displays the action log
	@param player - The current player
	@param diceRoll - The number given by the diceroll
	@param totalMoves - Determines the current tile of the player
*/
void actionLog(char player, int diceRoll, int totalMoves)
{
    printf("-------------------------\n");
	printf("Player %c's Log\n", player);
	printf("-------------------------\n");
    printf("Player %c rolled a: %d\n", player, diceRoll);
    printf("Player %c is now on tile: %d\n", player, totalMoves);
}

/*  Displays the current position of the players and determines if both players are on the same tile
    Pre-Condition: Both players are on the same tile
    @param totalP1 - Determines what tile the first player is on
    @param totalP2 - Determines what tile the second player is on
    @param tiles - The tiles of the board
    @param player1 - Displays the first player's piece
    @param player2 - Displays the second player's piece
*/
void movement(int totalP1, int totalP2, char tiles[21], char player1, char player2)
{
    clearBoard(tiles);

    if(totalP1 == totalP2) // same tile display
    {
        tiles[totalP1] = '3';
    }
    else // separate tile display
    {
        tiles[totalP1] = player1;
        tiles[totalP2] = player2;
    }
}

/*  Returns a 1 if the player is on tile 16 (go to jail tile)
    Pre-Condition: The player is on the go to jail tile (tile 16)
    @param *totalMoves - To check the player's current position
*/
int checkJail(int totalMoves)
{
    totalMoves = totalMoves == 16;

    return totalMoves;
}

/*  Uses pointers to move the player into the jail tile and also deducts 1 to their jailtime after each iteration
    Pre-Condition: The player is in jail
    @param *totalMoves - To change the player's move count to the jail tile
    @param *jailTime - To update the player's jail time
    @param tiles[21] - The tiles of the board
    @param player - To move the icon of the player to the jail tile  
*/
void inJail(int *totalMoves, int *jailTime, char tiles[21], char player)
{  
    *jailTime -= 1;
    *totalMoves = 6;
	tiles[*totalMoves] = player;
	printf("\nPlayer %c is in jail and cannot move for %d turn/s\n", player, *jailTime);
}

/*  Determines if the player is on the tax tile and updates their balance (tile 19)
    Pre-Condition: Player is on the 19th tile
    @param *bal - Determines the amount to be deducted by the player
    @param totalMoves - Checks if the player is on tile 19 (tax tile)
	@param player - The current player
*/
void checkTax(int *bal, int totalMoves, char player)
{
    if(totalMoves == 19)
    {
        *bal -= 1000000;
		printf("\nPlayer %c had to pay 1000000 in taxes!\n", player);
    }
}

/*	Determines if the player passed or is on the GO tile
	Pre-condition: Player passes or is on the GO tile
    @param *bal - Updates the player's balance
	@param totalMoves - Determines the player's current location
	@param diceRoll - Adds the given diceroll value to the current location
	@param player - The current player
*/
void passedGo(int *bal, int totalMoves, int diceRoll, char player)
{
    if(totalMoves + diceRoll >=21) // e.g: player is on tile 16 and diceroll is 6
									// 16 + 6 = 22 which means the player passed go
    {
        *bal += 1000000;
        printf("\nPlayer %c passed GO and collected 1000000\n", player);
    }
}

/*  Due to the original algorithm created, a separate, similar function had to be created for passing GO during debug mode
    Pre-condition: Player passes or is on the GO tile
    @param *bal - Updates the player's balance
	@param totalMoves - Determines the player's current location and adds onto itself
	@param player - The current player
*/
void debugPassedGo(int *bal, int totalMoves, char player)
{
    if(totalMoves + totalMoves >=21) 
    {
        *bal += 1000000;
        printf("\nPlayer %c passed GO and collected 1000000\n", player);
    }
}
/*  function to allow player to buy the property their piece is on
    Pre-Condition: The player buys the tile they are currently on and said tile is buyable/not already owned. Player also has enough money
    @param *balance - Determines the amount deducted from the player
    @param totalMoves - Determines what tile the player is on
    @param properties[21] - The location of the properties on the board
    @param playerProperty - Displays the player's property symbol on the tile
    @param opponentProperty - Displays the opponent's property symbol on the tile
*/
void buyProperty(int *balance, int totalMoves, char properties[21], char playerProperty, char opponentProperty, char player)
{
    if(properties[totalMoves] == playerProperty || properties[totalMoves] == opponentProperty)// if property is occupied
    {
        printf("\nThis tile is already owned by someone!\n");
    }
    else
    {
        if (totalMoves >= 2 && totalMoves <= 5) // a-d
        {
            if(*balance <= 2000000){
                printf("\nYou will lose if you buy this property! No sale!\n");
            }
            else
            {
            *balance -= 2000000;
            properties[totalMoves] = playerProperty;
            printf("\nPlayer %c bought property %d\n", player, totalMoves);
            }
        }
        else if (totalMoves >= 7 && totalMoves <= 10) // e-h
        {
            if(*balance <= 4000000){
                printf("\nYou will lose if you buy this property! No sale!\n");
            }
            else{
            *balance -= 4000000;
            properties[totalMoves] = playerProperty;
            printf("\nPlayer %c bought property %d\n", player, totalMoves);
            }
        }
        else if (totalMoves >= 12 && totalMoves <= 15) // i-l
        {
            if(*balance <= 6000000){
                printf("\nYou will lose if you buy this property! No sale!\n");
            }
            else{
            *balance -= 6000000;
            properties[totalMoves] = playerProperty;
            printf("\nPlayer %c bought property %d\n", player, totalMoves);
            }
        }
        else if (totalMoves == 17 || totalMoves == 18 || totalMoves == 20) // m, n, and o
        {
            if(*balance <= 8000000){
                printf("\nYou will lose if you buy this property! No sale!\n");
            }
            else{
            *balance -= 8000000;
            properties[totalMoves] = playerProperty;
            printf("\nPlayer %c bought property %d\n", player, totalMoves);
            }
        }
        else // for special tiles
        {
            printf("\nYou cannot buy on this tile!\n");
        }
    }
}

/*  Checks if the player landed on their opponent's property and deducts a certain amount
    Pre-Condition: The player landed on a tile owned by their opponent
    @param totalMoves - Determines what tile the player is on
    @param *balPlayer - Determines the amount deducted from the player
    @param *balOppoent - Determines the amount added to the opponent
    @param playerProperty - Checks if the opponent's property symbol is on the tile
    @param properties[21] - The location of the properties on the board
    @param player - The player's icon
    @param opponent - The opponent's icon
*/
void rent(int totalMoves, int *balPlayer, int *balOpponent, char opponentProperty, char properties[21], char player, char opponent)
{
    if(properties[totalMoves] == opponentProperty)
    {
        if (totalMoves >= 2 && totalMoves <= 5)
        {
            *balPlayer -= 300000;
            *balOpponent += 300000;
            printf("Player %c paid 300000 to Player %c\n", player, opponent);
        }
        else if (totalMoves >= 7 && totalMoves <= 10)
        {
            *balPlayer -= 500000;
            *balOpponent += 500000;
            printf("Player %c paid 500000 to Player %c\n", player, opponent);
        }
        else if (totalMoves >= 12 && totalMoves <= 15)
        {
            *balPlayer -= 1000000;
            *balOpponent += 1000000;
            printf("Player %c paid 1000000 to Player %c\n", player, opponent);
        }
        else if (totalMoves == 17 || totalMoves == 18 || totalMoves == 20)
        {
            *balPlayer -= 2000000;
            *balOpponent += 2000000;
            printf("Player %c paid 2000000 to Player %c\n", player, opponent);
        }
    }
}

/*  Checks if either of the players have a balance less than or equal to 0 then displays the winner
    @param balanceP1 - Checks the balance of the first player
    @param balanceP2 - Checks the balance of the second player
*/
void displayWinner(int balanceP1, int balanceP2)
{
    if(balanceP1 <= 0)
    {
        printf("\nPlayer 2 is the winner!\n");
    }
    else if(balanceP2 <= 0)
    {
        printf("\nPlayer 1 is the winner!\n");
    }
}