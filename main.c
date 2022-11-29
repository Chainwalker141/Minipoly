#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int mainMenu();
void board(char[6][6]);
int movement(int, char[6][6], char);
int buyProperty(int*, int, char[6][6], char);
int diceRoll();
void userInterface(float, float);

int main()
{
	int gameMode;

	int total1 = 1; // player 1 movement
	int total2 = 1; // player 2 movement
	char player1 = '1';
	char player2 = '2';
	char p1Props = 'X';
	char p2Props = 'Y';

	float balanceP1 = 10000000; // 10m each
	float balanceP2 = 10000000;
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
			board(rows);
			userInterface(balanceP1, balanceP2);
			break;
		case 3: // debug mode
			printf("3");
			break;
	}
    
    return 0;
}

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
void board(char rows[6][6])
{
	printf("\n        e   f   g   h        \n"); 
	printf("  +---+---+---+---+---+---+  \n"); 
	printf("  |%c V|%c  |%c  |%c  |%c  |%c P|  \n", rows[0][5], rows[1][0], rows[1][1], rows[2][0], rows[2][1], rows[3][0]);
	printf("  +---+---+---+---+---+---+  \n");
	printf(" d|%c  |               |%c  |i \n", rows[0][4], rows [3][1]);
	printf("  +---+               +---+  \n");
	printf(" c|%c  |               |%c  |j \n", rows[0][3], rows[4][0]);
	printf("  +---+               +---+  \n");
	printf(" b|%c  |               |%c  |k \n", rows[0][2], rows[4][1]);
	printf("  +---+               +---+  \n");
	printf(" a|%c  |               |%c  |l \n", rows[0][1], rows[5][0]);
	printf("  +---+---+---+---+---+---+  \n");
	printf("  |%c G|%c  |%c T|%c  |%c  |%c J|  \n", rows[0][0], rows[5][5], rows[5][4], rows[5][3], rows[5][2], rows[5][1]);
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
void userInterface(float balanceP1, float balanceP2)
{
	char action;
	int roll;

	printf("\nAccount Balance:\n");
	printf("Player 1: %.2f\n", balanceP1);
	printf("Player 2: %.2f\n", balanceP2);
	printf("-------------------------\n");
	printf("Log:\n\n");
	printf("-------------------------\n");
	printf("Actions\n");
	printf("[R]oll the Dice\n");
	printf("[B]uy Property\n");
	printf("Input: ");
	scanf("\n\n%c", &action);

	if(action == 'R' || action == 'r')
	{
		roll = diceRoll();
		printf("%d", roll);
	}
	else if(action == 'B' || action == 'b')
	{
		printf("You bought this property");
	}
	
}

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
        case 2 :
			*balance -= 2000000;
            properties[0][1] = indicator;
            break;
        case 3 :
			*balance -= 2000000;
            properties[0][2] = indicator;
            break ;
        case 4 :
			*balance -= 2000000;
            properties[0][3] = indicator;
            break;
        case 5:
			*balance -= 2000000;
            properties[0][4] = indicator;
            break;
        case 7 :
			*balance -= 4000000;
            properties[1][0] = indicator;
            break;
        case 8 :
			*balance -= 4000000;
            properties[1][1] = indicator;
            break;
        case 9 :
			*balance -= 4000000;
            properties[2][0] = indicator;
            break ;
        case 10 :
			*balance -= 4000000;
            properties[2][1] = indicator;
            break;
        case 12 :
			*balance -= 6000000;
            properties[3][1] = indicator;
            break;
        case 13 :
			*balance -= 6000000;
            properties[4][0] = indicator;
            break;
        case 14 :
			*balance -= 6000000;
            properties[4][1] = indicator;
            break;
        case 15 :
			*balance -= 6000000;
            properties[5][0] = indicator;
            break ;
        case 17 :
			*balance -= 8000000;
            properties[5][2] = indicator;
            break;
        case 18:
			*balance -= 8000000;
            properties[5][3] = indicator;
            break;
        case 20:
			*balance -= 8000000;
            properties[5][5] = indicator;
            break;
    }
}