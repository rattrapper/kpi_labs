#include <time.h>
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

pown(int, unsigned int);
max(int, int);
min(int, int);
void print(int **, int);
*readVector();

main()
{
	int **matrix, *seq;
	int n, line, i, k = 0;
	seq = readVector(&n);
	matrix = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++)
		matrix[i] = (int*)malloc(sizeof(int) * n);
	for (line = 0; line < 2 * n - 1; line++)
		for (i = max(0, line - n + 1); i < min(line + 1, n); i++, k++)
			matrix[line % 2 ? i : line - i][line % 2 ? line - i : i] =
				pown(seq[k / n], k%n + 1);
	print(matrix, n);
	getch();
}

int *readVector(int *count)
{
	char *buffer = (char*)malloc(sizeof(char)*1000);
	int i = 0, temp = 0;
	int *result;
	printf("enter sequence: ");
	gets(buffer);
	*count = 0;
	while (buffer[i])
		if (isdigit(buffer[i++]) && !isdigit(buffer[i]))
			(*count)++;
	result = (int*)malloc(sizeof(int)*(*count));
	for (i = 0; buffer[i]; i++)
		if (isdigit(buffer[i]))
			temp = temp * 10 + buffer[i] - '0';
		else if (temp)
		{
			*(result++) = temp;
			temp = 0;
		}
	if (temp)
		*(result++) = temp;
	return result - *count;
}
int pown(register int x, register unsigned int n)
{
	if (!n)
		return 1;
	return x * pown(x, n - 1);
}
max(x, y)
{
	return x > y ? x : y;
}
min(x, y)
{
	return x < y ? x : y;
}
void print(int **matrix, int n)
{
	int i, j;
	for (i = 0; i < n; i++, printf("\n"))
		for (j = 0; j < n; j++)
			printf("%d\t", matrix[i][j]);
}