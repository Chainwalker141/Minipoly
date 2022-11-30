#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int mainMenu();
void board(char[20], char [20]);
void clearBoard(char[20]);
int movement(int, int, char[20], char, char);
int rent(int, int*, char, char[20]);
int checkJail(int, char[20]);
int checkTax(int*, int);
int buyProperty(int*, int, char[20], char);
int diceRoll();
int debugRoll();
char userInterface(float, float);
void winner(int, int);

/*
	function for displaying the main menu
*/
int mainMenu()
{
	int selectedMode;
	
	// main menu display
    printf("Welcome to Minipoly!\n");
    printf("A Game by Joaquin Sinjian\n");
    printf("Of Section S21B\n\n");
    printf("==============================\n\n");
    printf("Choose a Mode\n");
    printf("[1] How to Play\n");
	printf("[2] Play Mode\n");
	printf("[3] Debug Mode\n");
    
    printf("Enter Number: ");
    scanf("%d", &selectedMode);

	return selectedMode;
}

/*
	function for displaying the board
*/
void board(char rows[20], char properties[20])
{
	printf("\n        e   f   g   h        \n"); 
	printf("  +---+---+---+---+---+---+  \n"); 
	printf("  |%c V|%c %c|%c %c|%c %c|%c %c|%c P|  \n", rows[5], rows[6], properties[6], rows[7], properties[7], 
                                                            rows[8], properties[8], rows[9], properties[9], rows[10]);
	printf("  +---+---+---+---+---+---+  \n");
	printf(" d|%c %c|               |%c %c|i \n", rows[4], properties[4], rows[11], properties[11]);
	printf("  +---+               +---+  \n");
	printf(" c|%c %c|               |%c %c|j \n", rows[3], properties[3], rows[12], properties[12]);
	printf("  +---+               +---+  \n");
	printf(" b|%c %c|               |%c %c|k \n", rows[2], properties[2], rows[13], properties[13]);
	printf("  +---+               +---+  \n");
	printf(" a|%c %c|               |%c %c|l \n", rows[1], properties[1], rows[14], properties[14]);
	printf("  +---+---+---+---+---+---+  \n");
	printf("  |%c G|%c %c|%c T|%c %c|%c %c|%c J|  \n", rows[0], rows[19], properties[19], rows[18], rows[17], properties[17], 
                                                            rows[16], properties[16], rows[15], properties[15]);
	printf("  +---+---+---+---+---+---+  \n");
	printf("        o       n   m        \n");
}

/* 
	function for normal diceroll
*/ 
int diceRoll()
{
	int diceRoll;

	srand(time(0));
	
	diceRoll = (rand() % 6) + 1;

	return diceRoll;
}

/*
    function for debug diceroll
*/
int debugRoll()
{
    int number;

    printf("Enter a roll number (0-19): ");
    scanf("%d", &number);

    return number;
}

/*
	function for user interface (UI)
*/
char userInterface(float balanceP1, float balanceP2)
{
	char action;

	printf("-------------------------\n");
	printf("Log:\n\n");
	printf("-------------------------\n");
	printf("\nAccount Balance:\n");
	printf("Player 1: %.2f\n", balanceP1);
	printf("Player 2: %.2f\n\n", balanceP2);
	printf("Actions\n");
	printf("[R]oll the Dice\n");
	printf("[B]uy Property\n");
	printf("Input: ");
	scanf("\n\n%c", &action);

	return action;
}

/*
	function for player movement
*/
int movement(int totalP1, int totalP2, char rows[20], char player1, char player2)
{
    clearBoard(rows);

    if(totalP1 == totalP2)
    {
        rows[totalP1] = '3'; // if both are on the same tile
    }
    else
    {
        rows[totalP1] = player1;
        rows[totalP2] = player2;
    }
}

/*
    function to check if in jail
*/
int checkJail(int total, char rows[20])
{
    total = total == 15;

    return total;
}

/*
    function to check if player is on tax tile
*/
int checkTax(int *bal, int total)
{
    if(total == 18)
    {
        *bal -= 1000000;
        return *bal;
    }
    else
    {
        return 0;
    }
}

/*
    function for buying properties & checks if property is owned
*/
int buyProperty(int *balance, int total, char properties[20], char indicator)
{
    if(properties[total] == 'X' || properties[total] == 'Y')// checks if property is occupied
    {
        printf("\nThis tile is already owned by someone!\n");
    }
    else
    {
        if (total >= 1 && total <= 4)
        {
            *balance -= 2000000;
            properties[total] = indicator;
            return *balance;
        }
        else if (total >= 6 && total <= 9)
        {
            *balance -= 4000000;
            properties[total] = indicator;
            return *balance;
        }
        else if (total >= 11 && total <= 14)
        {
            *balance -= 6000000;
            properties[total] = indicator;
            return *balance;
        }
        else if (total == 16 || total == 17 || total == 19)
        {
            *balance -= 8000000;
            properties[total] = indicator;
            return *balance;
        }
        else
        {
            printf("You cannot buy on this tile!");
        }
    }
}

/*
    function for renting
*/
int rent(int total, int *bal, char oppProperty, char properties[20])
{
    if(properties[total] == oppProperty)
    {
        if (total >= 1 && total <= 4)
        {
            *bal -= 300000;
            return *bal;
        }
        else if (total >= 6 && total <= 9)
        {
            *bal -= 500000;
            return *bal;
        }
        else if (total >= 11 && total <= 14)
        {
            *bal -= 1000000;
            return *bal;
        }
        else if (total == 16 || total == 17 || total == 19)
        {
            *bal -= 2000000;
            return *bal;
        }
    }
    else
    {
        return 0;
    }
}

/*
	function to clear the board
*/
void clearBoard(char rows[20])
{
    int i,j;

    for(i = 0; i < 20; i++)
    {
       rows[i] = ' ';
    }
}

/*
    function to check for winner
*/
void winner(int balance1, int balance2)
{
    if(balance1 <= 0)
    {
        printf("\nPlayer 2 is the winner!\n");
    }
    else if(balance2 <= 0)
    {
        printf("\nPlayer 1 is the winner!\n");
    }
}