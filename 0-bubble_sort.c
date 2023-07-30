#include "sort.h"
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
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 *
 * @array: array of integers to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array != NULL)
		for (i = 0; i < (size - 1); i++)
		{
			for (j = 0; j < (size - i - 1); j++)
			{
				if (*(array + j) > *(array + j + 1))
				{
					swap(array + j, array + j + 1);
					print_array(array, size);
				}
			}
		}
}
