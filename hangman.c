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
	int round, betrag, eingabe, roundCount, p1Score, p2Score, win = 0;
	char usernames[2][50];
	PrintFile("./files/logo.txt");

	printf("Neu hier? Dann geben Sie 1 ein.\n");
	printf("Bereits Benutzer? Dann geben Sie 2 ein.\n");
	printf("Eingabe: ");
	scanf("%i", &eingabe);

	if (eingabe == 1)
	{
		newUser();
		eingabe = 2;
	}

	if (eingabe == 2)
	{
		login(usernames);
	}

	PrintFile("./files/logo.txt");
	printf("\nWie viele Runden möchten Sie spielen? \nmind. 4:");
	scanf("%i", &roundCount);
	if (roundCount < 4)
	{
    system("clear");
		color("red");
		printf("\nsehr wienige Runden.\n");
		color("x");
		exit(0);
	}

	for (round = 1; round < roundCount + 1; round++)
	{
		if (win == 1)
		{
			p1Score++;
			printf("\n%s hat gewonnen!\n", usernames[0]);
		}
		else if (win == 2)
		{
			p2Score++;
			printf("\n%s hat gewonnen!\n", usernames[1]);
		}
		else if (win == 3)
		{
			printf("\nSpieler 1 hat verloren!\n");
		}
		else if (win == 4)
		{
			printf("\nSpieler 2 hat verloren!\n");
		}

		printf("\nRound %i:\n", round);
		printf("Score:\nPlayer1: %i\t\t\t\t\t\t\t      Player2: %i\n\n", p1Score, p2Score);
		game(&win);
	}

	if (round > roundCount)
	{
    system("clear");
    PrintFile("./files/logo.txt");
		if (p1Score + 1 < p2Score + 1)
		{
			printf("\n%s hat gewonnen! Punkte: %i\n", usernames[1], p2Score + 1);
			betrag = (p2Score + 1) *1000;
			brief(betrag, usernames[1]);
		}
		else if (p1Score + 1 > p2Score + 1)
		{
			printf("\n%s hat gewonnen! Punkte: %i\n", usernames[0], p1Score + 1);
			betrag = (p1Score + 1) *1000;
			brief(betrag, usernames[0]);
		}
	}

	return 0;
}