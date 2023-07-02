#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"


int array_search(int* arr, int arr_size, int query)
{
	int i = 0;
	int ret_value = VAL_NOT_FOUND; // default behavoir
	
	// loop over all the elements of the array
	for (i = 0; i < arr_size; i++)
	{
		if (arr[i] == query)
		{
			// if the query is found, set the return value to the index
			// of the found query value
			ret_value = i;
			break;
		}
	}

	return ret_value;
}


int array_insert(int* arr, int arr_size, int insert)
{
	// leverages the array_search function to find the first
	// VAL_EMPTY index in the array
	int insert_index = array_search(arr, arr_size, VAL_EMPTY);

	// if the search did not find an empty value, then the array is full
	// and we cannot insert
	if (VAL_NOT_FOUND == insert_index)
	{
		return VAL_NOT_INSERTED;
	}

	// set the value and return the index
	arr[insert_index] = insert;
	return insert_index;
}


int array_delete(int* arr, int arr_size, int delete)
{
	// leverages the array_search function to find the
	// delete value in the array
	int delete_index = array_search(arr, arr_size, delete);

	// if the search did not find the delete value, then the array
	// did not contain the value
	if (VAL_NOT_FOUND == delete_index)
	{
		return VAL_NOT_FOUND;
	}

	// delete the value and return the index
	arr[delete_index] = VAL_EMPTY;
	return delete_index;
}


void array_print(int* arr, int arr_size)
{
	int i = 0;

	printf("[ ");

	for (i = 0; i < arr_size; i++)
	{
		if (0 != i)
		{
			printf(", ");
		}

		printf("%d", arr[i]);
	}

	printf(" ]\n");
}

