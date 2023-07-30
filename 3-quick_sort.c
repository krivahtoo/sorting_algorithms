#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * swap - swap two values
 *
 * @a: pointer to integer value
 * @b: pointer to integer value
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partition the array
 *
 * @array: pointer to the array
 * @lo: lower bound of the array
 * @hi: upper bound of the array
 * @size: array size
 *
 * Return: the partition index
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int j, i = lo - 1;
	int pivot = array[hi];

	for (j = lo; j < hi; j++)
		if (array[j] <= pivot)
		{
			i++;
			swap(array + i, array + j);
			print_array(array, size);
		}
	i++;
	swap(array + i, array + hi);

	return (i);
}

/**
 * sort - sort an array of integers recursively
 *
 * @array: pointer to the array
 * @lo: lower bound of the array
 * @hi: upper bound of the array
 * @size: array size
 */
void sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo >= hi || lo < 0)
		return;
	p = partition(array, lo, hi, size);

	sort(array, lo, p - 1, size); /* Left side of pivot */
	sort(array, p + 1, hi, size); /* Right side of pivot */
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 *
 * @array: pointer to the first element of the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	sort(array, 0, size - 1, size);
}
