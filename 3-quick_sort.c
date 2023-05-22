#include "sort.h"

/**
 * partition - swaps index values
  * @array: where to swap  values
  * @size: size of array
  * @first: first index to look
  * @last: last index to look
  * Return: last swapped index
  */
int partition(int *array, int first, int last, int size)
{
	int pivot = array[last];
	int tmp;
	int i = first - 1;
	int j;

	for (j = first; j < size; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[last] < array[i + 1])
	{
		tmp = array[last];
		array[last] = array[i + 1];
		array[i + 1] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * lomuto - calls partition and parts the array in sorted and unsorted parts
 * @array: array to sort
 * @first: first index to look
 * @size: array size
 * @last: last index to look
 */
void lomuto(int *array, int first, int last, int size)
{
	int parted;

	if (first < last)
	{
		parted = partition(array, first, last, size);
		lomuto(array, first, parted - 1, size);
		lomuto(array, parted + 1, last, size);
	}
}
/**
 * quick_sort - calls the lomuto function to perform the quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto(array, 0, size - 1, size);
}
