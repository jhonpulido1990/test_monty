#include "monty.h"

/**
 * _free_double_pointer - Entry point
 * @d_pointer: double pointer
 * Return: void
 */
void _free_double_pointer(char **d_pointer)
{
	unsigned int i = 0;

	if (d_pointer == NULL)
		return;

	while (d_pointer[i])
	{
		free(d_pointer[i]);
		++i;
	}

	if (d_pointer[i] == NULL)
		free(d_pointer[i]);

	free(d_pointer);
}

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
	char **arr_matrix;

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
		return (-1);
	}
	fread(buffer, filelen, 1, fileptr);
	printf("%s\n", buffer);
	arr_matrix = add(buffer);
	if (!arr_matrix)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	fclose(fileptr);
	_free_double_pointer(arr_matrix);
	free(buffer);
	return (0);
}
