#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int mainMenu();
void board(char[6][6], char [6][6]);
void clearBoard(char[6][6]);
int movement(int, char[6][6], char);
int buyProperty(int*, int, char[6][6], char);
int diceRoll();
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
    
    while(selectedMode <= 0 || selectedMode > 3)  // for invalid number inputs
    {
	    printf("\n\nInvalid Selection, try again\n\n");	
	    	
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
	}
	return selectedMode;
}

/*
	function for displaying the board
*/
void board(char rows[6][6], char properties[6][6])
{
	printf("\n        e   f   g   h        \n"); 
	printf("  +---+---+---+---+---+---+  \n"); 
	printf("  |%c V|%c %c|%c %c|%c %c|%c %c|%c P|  \n", rows[0][5], rows[1][0], properties[1][0], rows[1][1], properties[1][1], 
                                                            rows[2][0], properties[2][0], rows[2][1], properties[2][1], rows[3][0]);
	printf("  +---+---+---+---+---+---+  \n");
	printf(" d|%c %c|               |%c %c|i \n", rows[0][4], properties[0][4], rows[3][1], properties[3][1]);
	printf("  +---+               +---+  \n");
	printf(" c|%c %c|               |%c %c|j \n", rows[0][3], properties[0][3], rows[4][0], properties[4][0]);
	printf("  +---+               +---+  \n");
	printf(" b|%c %c|               |%c %c|k \n", rows[0][2], properties[0][2], rows[4][1], properties[4][1]);
	printf("  +---+               +---+  \n");
	printf(" a|%c %c|               |%c %c|l \n", rows[0][1], properties[0][1], rows[5][0], properties[5][0]);
	printf("  +---+---+---+---+---+---+  \n");
	printf("  |%c G|%c %c|%c T|%c %c|%c %c|%c J|  \n", rows[0][0], rows[5][5], properties[5][5], rows[5][4], rows[5][3], properties[5][3], 
                                                            rows[5][2], properties[5][2], rows[5][1], properties[5][1]);
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
	function for decided action
*/


/*
	function for player movement
*/
int movement(int total, char rows[6][6], char player)
{
    switch(total)
    {
        case 1 :
            clearBoard(rows);
            rows[0][0] = player;
            break;
        case 2 :
            clearBoard(rows);
            rows[0][1] = player;
            break;
        case 3 :
            clearBoard(rows);
            rows[0][2] = player;
            break ;
        case 4 :
            clearBoard(rows);
            rows[0][3] = player;
            break;
        case 5:
            clearBoard(rows);
            rows[0][4] = player;
            break;
        case 6:
            clearBoard(rows);
            rows[0][5] = player;
            break;
        case 7 :
            clearBoard(rows);
            rows[1][0] = player;
            break;
        case 8 :
            clearBoard(rows);
            rows[1][1] = player;
            break;
        case 9 :
            clearBoard(rows);
            rows[2][0] = player;
            break ;
        case 10 :
            clearBoard(rows);
            rows[2][1] = player;
            break;
        case 11 :
            clearBoard(rows);
            rows[3][0] = player;
            break;
        case 12 :
            clearBoard(rows);
            rows[3][1] = player;
            break;
        case 13 :
            clearBoard(rows);
            rows[4][0] = player;
            break;
        case 14 :
            clearBoard(rows);
            rows[4][1] = player;
            break;
        case 15 :
            clearBoard(rows);
            rows[5][0] = player;
            break ;
        case 16 :
            clearBoard(rows);
            rows[5][1] = player;
            break;
        case 17 :
            clearBoard(rows);
            rows[5][2] = player;
            break;
        case 18:
            clearBoard(rows);
            rows[5][3] = player;
            break;
        case 19:
            clearBoard(rows);
            rows[5][4] = player;
            break;
        case 20:
            clearBoard(rows);
            rows[5][5] = player;
            break;
    }
}

int buyProperty(int *balance, int total, char properties[6][6], char indicator)
{
    switch(total)
    {
		case 1 :
			printf("You cannot buy this property!");
            break;
        case 2 :
			*balance -= 2000000;
            properties[0][1] = indicator;
			return *balance;
            break;
        case 3 :
			*balance -= 2000000;
            properties[0][2] = indicator;
			return *balance;
            break ;
        case 4 :
			*balance -= 2000000;
            properties[0][3] = indicator;
			return *balance;
            break;
        case 5:
			*balance -= 2000000;
            properties[0][4] = indicator;
			return *balance;
            break;
		case 6 :
			printf("You cannot buy this property!");
            break;
        case 7 :
			*balance -= 4000000;
            properties[1][0] = indicator;
			return *balance;
            break;
        case 8 :
			*balance -= 4000000;
            properties[1][1] = indicator;
			return *balance;
            break;
        case 9 :
			*balance -= 4000000;
            properties[2][0] = indicator;
			return *balance;
            break ;
        case 10 :
			*balance -= 4000000;
            properties[2][1] = indicator;
			return *balance;
            break;
		case 11 :
			printf("You cannot buy this property!");
            break;
        case 12 :
			*balance -= 6000000;
            properties[3][1] = indicator;
			return *balance;
            break;
        case 13 :
			*balance -= 6000000;
            properties[4][0] = indicator;
			return *balance;
            break;
        case 14 :
			*balance -= 6000000;
            properties[4][1] = indicator;
			return *balance;
            break;
        case 15 :
			*balance -= 6000000;
            properties[5][0] = indicator;
			return *balance;
            break ;
		case 16 :
			printf("You cannot buy this property!");
            break;
        case 17 :
			*balance -= 8000000;
            properties[5][2] = indicator;
			return *balance;
            break;
        case 18:
			*balance -= 8000000;
            properties[5][3] = indicator;
			return *balance;
            break;
        case 20:
			*balance -= 8000000;
            properties[5][5] = indicator;
			return *balance;
            break;
    }
}

/*
	function to clear the board
*/
void clearBoard(char rows[6][6])
{
    int i,j;

    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 6; j++)
        {
            rows[i][j] = ' ';
        }
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