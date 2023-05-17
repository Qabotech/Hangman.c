#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "functions/PrintFile.h"
#include "functions/colors.h"
#include "functions/game.h"

int main()
{
    int round = 0;
    int roundCount = 0;
    int p1Score = 0;
    int p2Score = 0;
    int *win;
	system("clear");
	printf("How many rounds do you want to play?");
	scanf("%i",&roundCount);
	for (round = 1; round < roundCount+1; round++)
	{
		system("clear");
		if (win== 1)
		{
			p1Score++;	
			printf("\nPlayer 1 Won!\n");
		}
		else if (win == 2)
		{
			p2Score++;	
			printf("\nPlayer 2 Won!\n");
		}else if (win == 3)
		{
			printf("\nPlayer 1 Lost!\n");
		}
		else if (win == 4)
		{
			printf("\nPlayer 2 Lost!\n");
		}
		printf("\nRound %i:\n",round);
		printf("Score:\nPlayer1: %i\t\t\t\t\t\t\t      Player2: %i\n\n",p1Score,p2Score);
		if (round==3)
		{
			if (p1Score<p2Score)
			{
				printf("\nPlayer 2 Won! Score:%i\n",p2Score+1);
			}else
			{
				printf("\nPlayer 1 Won! Score:%i\n",p1Score+1);
			}
		}
		game (&win);
	}
    return 0;
}
