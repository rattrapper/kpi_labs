#include <math.h>
#include <malloc.h>
#include <limits.h>

typedef struct {
	double x, y, z;
} point;

typedef struct {
	point *data;
	int n;
} polygon;

double mod(point a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

polygon max(polygon *arr, int n)
{
	polygon res = { (point*) malloc(sizeof(point) * n), n };
	double max = -_DMAX, temp;
	for (int i = 0; i < n; i++, max = -_DMAX)
		for (int j = 0; j < arr[i].n; j++)
			if ((temp = mod(arr[i].data[j])) > max)
			{
				res.data[i] = arr[i].data[j];
				max = temp;
			}
	return res;
}
