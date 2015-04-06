#include <time.h>
#include <stdio.h>
#include <malloc.h>
#define TElem int

TElem pown(TElem el, int power);
void print(TElem **matrix, int n)
{
	int i, j;
	for (i = 0; i < n; i++, printf('\n'))
		for (j = 0; j < n; j++)
			printf("%d\t", matrix[i][j]);
}
TElem *readVector(count)
{
	int i;
	TElem *result = (TElem*)malloc(sizeof(TElem) * count);
	printf("enter %d elements: \n", count);
	for (i = 0; i < count; i++)
	{
		printf("b%d = ", i);
		scanf("%d", result + i);
	}
	return result;
}

main()
{
	TElem **matrix, *seq;
	int n, line, i, j, k = 0;
	printf("enter n: ");
	scanf("%d", &n);
	seq = readVector(n);
	matrix = (TElem**)malloc(sizeof(TElem*)*n);
	for (i = 0; i < n; i++)
		matrix[i] = (TElem*)malloc(sizeof(TElem) * n);
	for (line = 0; line < 2 * n - 1; line++)
		for (i = line < n ? 0 : line - n; i <= (line < n ? line : n - 1); i++)
			matrix[line % 2 ? line - i : i][line % 2 ? i : line - i] =
				pown(seq[k / n], k++%n + 1);
	print(matrix, n);
}

TElem pown(TElem x, unsigned int n)
{
	if (!n)
		return 1;
	return x * pown(x, n - 1);
}