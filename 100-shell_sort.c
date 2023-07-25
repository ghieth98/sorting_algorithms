#include "sort.h"

/**
 * swap - swaps two integers positions in as array.
 * @x: First integer
 * @y: Second integer
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - sorts an array of integers using shell sort
 * @array: the array to sort
 * @size: the size of the array
 **/
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(&array[j], &array[j - gap]);
				j -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * shell_sort_Ciura - sorts an array of integers using Ciura algo
 * @array: the array to sort
 * @size: the size of the array
 **/
void shell_sort_Ciura(int *array, size_t size)
{
	size_t gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
	size_t i, j, k, gap;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < sizeof(gaps) / sizeof(gaps[0]); k++)
	{
		gap = gaps[k];

		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			print_array(array, size);
			array[j] = temp;
		}
	}
}
