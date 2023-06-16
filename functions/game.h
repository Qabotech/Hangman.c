char *randomWord()
{
	char *wordList[] = { 
    "apfel",
		"banane",
		"katze",
		"hund",
		"elefant",
		"fisch",
		"giraffe",
		"pferd",
		"eidechse",
		"jaguar",
		"kirsche",
		"zitrone",
		"maus",
		"vogel",
		"schwein",
		"spinne",
		"tiger",
		"affe",
		"eule",
		"löwe",
		"nashorn",
		"schaf",
		"schildkröte",
		"eichhörnchen",
		"hase",
		"delfin",
		"hai",
		"eisbär",
		"gorilla",
		"hummel" };

	srand(time(NULL));
	int ArrLen = sizeof(wordList) / sizeof(wordList[0]);
	int randomNum = rand() % (ArrLen);
	return wordList[randomNum];
}

void appendUser(char name[], char alter[], char strasse[], char plz[], char ort[])
{
	FILE * datei;
	datei = fopen("files/users.txt", "a");
	if (datei != NULL)
	{
		char line[100];
		fprintf(datei, "\n%s;%s;%s;%s;%s", name, alter, strasse, plz, ort);
		fclose(datei);
		system("clear");
		color("blue");
		printf("Neuer Benutzer wurde erfolgreich hinzugefügt.\n");
		sleep(1);
	}
	else
	{
		printf("Fehler beim Öffnen der Datei.\n");
	}
}

void newUser()
{
	char name[50];
	char alter[50];
	char strasse[50];
	char plz[50];
	char ort[50];
	printf("Bitte name eingeben: ");
	scanf("%s", name);
	printf("Bitte alter eingeben: ");
	scanf("%s", alter);
	printf("Bitte strasse eingeben: ");
  gets(strasse);
  while (getchar() != '\n');
	printf("Bitte plz eingeben: ");
	scanf("%s", plz);
	printf("Bitte ort eingeben: ");
	scanf("%s", ort);
	appendUser(name, alter, strasse, plz, ort);
	system("clear");
}

bool userExists(const char user[])
{
	FILE * file;
	file = fopen("files/users.txt", "r");

	if (file != NULL)
	{
		char line[100];
		while (fgets(line, sizeof(line), file) != NULL)
		{
			char *token = strtok(line, ";");

			if (token != NULL && strcmp(token, user) == 0)
			{
				fclose(file);
				return true;
			}
		}

		fclose(file);
	}

	return false;
}

void login(char usernames[2][50])
{
	int remainingAttempts = 3;
	for (int i = 0; i < 2; i++)
	{
		while (remainingAttempts > 0)
		{
			printf("Spieler %d Benutzernamen eingeben: ", i + 1);
			scanf("%s", usernames[i]);

			if (userExists(usernames[i]))
			{
				break;
			}
			else
			{
				color("red");
				printf("Der Benutzer existiert nicht.\n");
				color("x");
				remainingAttempts--;
			}
		}

		if (remainingAttempts <= 0)
		{
			color("red");
			printf("Maximale Anzahl von Login-Versuchen erreicht.\n");
			color("x");
			exit(0);
		}

		remainingAttempts = 3;
	}
}

void saveAsWord(const char *filename, const char *content)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("Fehler beim Öffnen der Datei.\n");
		return;
	}

	fprintf(file, "%s", content);
	fclose(file);
}

void getCurrentDate(char *currentDate)
{
	time_t t = time(NULL);
	struct tm *currentTime = localtime(&t);
	strftime(currentDate, 11, "%d.%m.%Y", currentTime);
}

void brief(int betrag, char username[])
{
	char brief[2500];
	char heute[11];
	char name[50];
	char strasse[50];
	char plz[50];
	char ort[50];
	FILE *file = fopen("files/users.txt", "r");
	if (file != NULL)
	{
		char line[100];
		while (fgets(line, sizeof(line), file) != NULL)
		{
			char *token = strtok(line, ";");
			char *currName = token;
			token = strtok(NULL, ";");
			char *currAlter = token;
			token = strtok(NULL, ";");
			char *currStrasse = token;
			token = strtok(NULL, ";");
			char *currPlz = token;
			token = strtok(NULL, ";");
			char *currOrt = token;

			if (strcmp(username, currName) == 0)
			{
				strcpy(name, currName);
				strcpy(strasse, currStrasse);
				strcpy(plz, currPlz);
				strcpy(ort, currOrt);
				break;
			}
		}

		fclose(file);
	}
	else
	{
		printf("Fehler beim Öffnen der Datei.\n");
		return;
	}

	getCurrentDate(heute);
	snprintf(brief, sizeof(brief),
		"Absender:\n"
		"BSZ WÜ\n"
		"Musterstr. 10\n"
		"97070 Würzburg\n"
		"\n"
		"Empfänger:\n"
		"%s\n"
		"%s\n"
		"%s %s\n"
		"\n"
		"Datum: %s\n"
		"\n"
		"Betreff: Herzlichen Glückwunsch! Sie haben %d Euro gewonnen!\n\n"
		"Sehr geehrte/r %s,\n\n"
		"wir freuen uns, Ihnen mitteilen zu können, dass Sie als Teilnehmer an unserem Hangman-Spiel den Hauptpreis in Höhe von %d Euro gewonnen haben. Herzlichen Glückwunsch!\n\n"
		"Ihr Geschick und Ihre Beteiligung an unserem Hangman-Spiel haben sich ausgezahlt, und wir möchten Ihnen für Ihre Teilnahme danken. Ihre Ausdauer und Ihr Können haben dazu geführt, dass Sie als Gewinner ausgewählt wurden. Wir hoffen, dass Sie beim Spielen von Hangman viel Spaß hatten und der Gewinn Ihnen eine zusätzliche Freude bereitet.\n\n"
		"Um Ihren Gewinn zu erhalten, bitten wir Sie, sich mit uns in Verbindung zu setzen. Sie können uns telefonisch unter 1020202505 erreichen oder uns eine E-Mail an email@email.com senden. Geben Sie bitte Ihren vollständigen Namen, Ihre Adresse und weitere erforderliche Informationen an, damit wir den Gewinn problemlos an Sie überweisen können.\n\n"
		"Nochmals herzlichen Glückwunsch zu Ihrem Gewinn! Wir hoffen, dass er Ihnen eine angenehme Überraschung bereitet und Ihnen nützlich ist. Vielen Dank für Ihre Teilnahme an unserem Hangman-Spiel.\n\n"
		"Mit freundlichen Grüßen,\n\n"
		"Mustermann\n", name, strasse, plz, ort, heute, betrag, name, betrag);

	char filename[100];
	snprintf(filename, sizeof(filename), "briefe/%s.docx", name);
	saveAsWord(filename, brief);
	printf("Der Brief wurde and den gewinner %s gesendet.\n", name);
}

void hideWord(char *RandomWord, char *hiddenWord)
{
	int i = 0;
	for (i = 0; i < strlen(RandomWord); i++)
	{
		strcat(hiddenWord, "_");
	}
}

void checkWord(char *RandomWord, char *word, char *hiddenWord, bool *wordCheck, bool *check)
{
	int j = 0;
	int c = 0;
	for (j = 0; j < strlen(RandomWord); j++)
	{
		for (c = 0; c < strlen(word); c++)
		{
			if (RandomWord[j] == word[c])
			{
				hiddenWord[j] = RandomWord[j];
				*wordCheck = true;
			}
		}
	}
}

void game(int *win)
{
	*win = 0;
	char *RandomWordP1 = randomWord();
	sleep(1);
	char *RandomWordP2 = randomWord();
	char word[100];
	int i = 0;
	int player1 = 0;
	int player2 = 0;
	int j = 0;
	_Bool check = true;
	bool wordCheckP1 = false;
	bool wordCheckP2 = false;
	char hiddenWordP1[100] = { '\0' };

	char hiddenWordP2[100] = { '\0' };

	char filename[20];
	hideWord(RandomWordP1, hiddenWordP1);
	hideWord(RandomWordP2, hiddenWordP2);
	while (check)
	{
		if (i % 2 == 0)
		{
			color("red");
			wordCheckP1 = false;
			sprintf(filename, "files/%d.txt", player1);
			PrintFile(filename);
			printf("\n");
			for (j = 0; j < strlen(RandomWordP1); j++)
			{
				printf("%c ", hiddenWordP1[j]);
			}

			j = 0;
			printf("\n");
			printf("%s", RandomWordP1);
			scanf("%s", word);
			checkWord(RandomWordP1, word, hiddenWordP1, &wordCheckP1, &check);
			if (strchr(hiddenWordP1, '_') == NULL)
			{ 	*win = 1;
				check = false;
			}

			if (player1 == 6)
			{ 	*win = 3;
				check = false;
			}

			if (wordCheckP1 == false)
			{
				player1++;
			}

			color("x");
		}
		else
		{
			color("blue");
			wordCheckP2 = false;
			sprintf(filename, "files/%d.txt", player2);
			PrintFile(filename);
			printf("\n");
			for (j = 0; j < strlen(RandomWordP2); j++)
			{
				printf("%c ", hiddenWordP2[j]);
			}

			j = 0;
			printf("\n");
			printf("%s", RandomWordP2);
			scanf("%s", word);
			checkWord(RandomWordP2, word, hiddenWordP2, &wordCheckP2, &check);
			if (strchr(hiddenWordP2, '_') == NULL)
			{ 	*win = 2;
				check = false;
			}

			if (player2 == 6)
			{ 	*win = 4;
				check = false;
			}

			if (wordCheckP2 == false)
			{
				player2++;
			}

			color("x");
		}

		i++;
	}
}