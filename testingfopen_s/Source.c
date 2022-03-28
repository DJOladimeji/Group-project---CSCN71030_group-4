#include <stdio.h>

#define _CRT_SECURE_NO_DEPRECATE        
#define MAXCHAR 100

void print(FILE* fp, char info[]);
void readfile();

int main()
{
	FILE* fp;
	int ch;
	unsigned long count = 0;

	fopen_s(&fp, "fopen.txt", "w");

	char message[MAXCHAR] = "it will work";

	print(fp, message);

	if(fp == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}
	
	fclose(fp);

	readfile();

	printf("\n");
	return 0;
}

void print(FILE* fp, char info[])
{
	fprintf(fp, "%s", info);
}

void readfile()
{
	FILE* fp;
	int ch;
	unsigned long count = 0;

	fopen_s(&fp, "fopen.txt", "r");

	if (fp == NULL)
	{
		printf("Can't open file\n");
		exit(1);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
}