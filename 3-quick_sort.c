#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Function prototype for quick_s */
void quick_s(int *arr, int low, int high, size_t sz);

/**
 * quick_sort - sorts in ascending order using the quick sort algorithm             
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - Lomuto partition scheme
 * @arr: Pointer
 * @low: index
 * @high: High index
 * @sz: Size
 * Return: i
 */
int partition(int *arr, int low, int high, size_t sz)
{
	int i = low - 1, j = low;
	int pivot = arr[high], temp = 0;

	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (arr[i] != arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				print_array(arr, sz);
			}
		}
		j++;
	}

	if (arr[i + 1] != arr[high])
	{
		temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;
		print_array(arr, sz);
	}

	return (i + 1);
}

/**
 * quick_s - quick sort
 * @arr: Pointer to the array
 * @low: Lower index
 * @high: Higher index
 * @sz: Size of the array
 * Return: void
 */
void quick_s(int *arr, int low, int high, size_t sz)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high, sz);
		quick_s(arr, low, pivot - 1, sz);
		quick_s(arr, pivot + 1, high, sz);
	}
}
