#include "monty.h"
/**
 * print_matrix - print matrix
 * @matrix: the matrix.
 *
 * Return: void.
 */
void print_matrix(char **matrix)
{
	int i, j, m, n;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
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

	fclose(fileptr);
	free(buffer);
	return (0);
}
