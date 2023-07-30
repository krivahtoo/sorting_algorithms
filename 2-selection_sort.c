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
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 *
 * @array: pointer to the first element of the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		if (min != i)
		{
			swap((array + i), (array + min));
			print_array(array, size);
		}
	}
}
