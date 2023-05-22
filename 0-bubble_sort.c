#include "sort.h"
/**
 * bubble_sort - implementation of the bubble sort algorithm
 * @array: array to be sorted
 * @size: length of the array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;

	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
