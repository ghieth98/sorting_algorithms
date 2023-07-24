#include "sort.h"

/**
 * swap- swaps two integres in an array
 * @i: First intger
 * @j: Second integer
 * Return: void
 */

void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}


/**
 * bubble_sort - sorts an array of integers in asceding order
 * @array: Pointer to the array sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t n, temp, i;

	if (array == NULL || size < 2)
		return;

	n = size;
	do {
		temp = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
				temp = 1;
			}
		}

		n = temp;
	} while (n > 1)
}
