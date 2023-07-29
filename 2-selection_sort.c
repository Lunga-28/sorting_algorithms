#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/***
 * selection_sort - sorting using selection algorithm
 * @array: array
 * @size: size
 ***/

void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t current_index = 0, smallest_index = 0, min_index = 0;

	if (array == NULL || size == 0)
		return;

	for (; current_index < size - 1; current_index++)
	{
		smallest_index = current_index;
		for (min_index = current_index + 1; min_index < size; min_index++)
		{
      
			if (array[min_index] < array[smallest_index])
				smallest_index = min_index;
      
		}
		if (smallest_index != current_index)
		{
      
			temp = array[current_index];
			array[current_index] = array[smallest_index];
			array[smallest_index] = temp;
			print_array(array, size);
		}
	}
}
