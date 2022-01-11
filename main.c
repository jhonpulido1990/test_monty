#include "monty.h"
/**
 * main - file
 * @argc: data
 * @argv: data
 * Return: 0
 *
 */
int main(int argc, char **argv)
{
	FILE *fileptr;
	char *buffer;
	long filelen;

	if (argc != 2)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	fileptr = fopen(argv[1], "r");
	fseek(fileptr, 0, SEEK_END);
	filelen = ftell(fileptr);
	rewind(fileptr);

	buffer = (char *)malloc(filelen * sizeof(char));
	if (buffer == NULL)
	{
		return (NULL);
	}
	fread(buffer, filelen, 1, fileptr);
	
	printf("%s", buffer);
	fclose(fileptr);
	free(buffer);
	return (0);
}