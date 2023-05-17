char* randomWord()
{
    char* wordList[] = 
    {
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
        "hummel"
    };
    srand(time(NULL));
    int ArrLen =sizeof(wordList) / sizeof(wordList[0]);
    int randomNum = rand() % (ArrLen);
    return wordList[randomNum];
}

void hideWord(char *RandomWord,char *hiddenWord)
{
    int i =0;
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

void game (int *win)
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
    char hiddenWordP1[100] = {'\0'};
    char hiddenWordP2[100] = {'\0'};
    char filename[20];
    hideWord(RandomWordP1, hiddenWordP1);
    hideWord(RandomWordP2, hiddenWordP2);
    while (check)
    	{
			if (i % 2 == 0)
			{
				color("red");
				wordCheckP1 = false;
    	    	sprintf(filename, "man/%d.txt", player1);
    	    	PrintFile(filename);
    	    	printf("\n");
    	    	for (j = 0; j < strlen(RandomWordP1); j++)
    	    	{
    	    	    printf("%c ", hiddenWordP1[j]);
    	    	}
    	    	j = 0;
				// printf("\n%s\n", RandomWordP1);
				printf("\n");
				scanf("%s", word);
    	    	checkWord(RandomWordP1, word, hiddenWordP1, &wordCheckP1, &check);
				if (strchr(hiddenWordP1, '_') == NULL)
    	    	{
                    *win = 1;
    	    		check = false;
    	    	}
				if (player1 == 6)
    	    	{
                    *win = 3;
    	    	    check = false;
    	    	}
    	    	if (wordCheckP1 == false)
    	    	{
    	    	    player1++;
    	    	}
				color("x");
			}
			else{

				color("blue");
				wordCheckP2 = false;
    	    	sprintf(filename, "man/%d.txt", player2);
    	    	PrintFile(filename);
    	    	printf("\n");
    	    	for (j = 0; j < strlen(RandomWordP2); j++)
    	    	{
    	    	    printf("%c ", hiddenWordP2[j]);
    	    	}
    	    	j = 0;
				// printf("\n%s\n", RandomWordP2);
				printf("\n");
    	    	scanf("%s", word);
    	    	checkWord(RandomWordP2, word, hiddenWordP2, &wordCheckP2, &check);
				if (strchr(hiddenWordP2, '_') == NULL)
    	    	{
                    *win = 2;
    	    		check = false;
    	    	}
				if (player2 == 6)
    	    	{
                    *win = 4;
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

