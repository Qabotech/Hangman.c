void PrintFile(const char* FileName)
{

	FILE *file =fopen(FileName, "r");
	char temp = fgetc(file);
	while (temp != EOF)
	{
		printf ("%c", temp);
		temp = fgetc(file);
	}

	fclose(file);
}