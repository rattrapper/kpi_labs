#include <time.h>
#include <stdio.h>
#include <malloc.h>

int pown(int el, int power);
max(int, int);
min(int, int);
void print(int **, int);
int *readVector(int);

main()
{
	int **matrix, *seq;
	int n, line, i, j, k = 0;
	printf("enter n: ");
	scanf("%d", &n);
	seq = readVector(n);
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

int *readVector(count)
{
	int i;
	int *result = (int*)malloc(sizeof(int) * count);
	printf("enter %d elements: \n", count);
	for (i = 0; i < count; i++)
	{
		printf("b%d = ", i);
		scanf("%d", result + i);
	}
	return result;
}
int pown(int x, unsigned int n)
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