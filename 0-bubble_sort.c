#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts using bubble sort algorithm
 * @array: array to sort
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t a = 0, b = 0;
	int temp = 0;

	if (array == NULL || size == 0)
		return;
	
	for (; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b + 1];
				array[b + 1] = array[b];
				array[b] = temp;
				print_array(array, size);
			}
		}
	}
}
