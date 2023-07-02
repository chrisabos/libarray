#ifndef _ARRAY_H
#define _ARRAY_H


#define VAL_EMPTY 0
#define VAL_NOT_FOUND -1
#define VAL_NOT_INSERTED -2


/**
 * @brief find the first index of a balue in an array
 *
 * @param arr is a pointer to an array of integers to be searched
 * @param arr_size is the size of the array
 * @param query is the value to be searched for
 * @return the index of the value in the array, or VAL_NOT_FOUND if it does not exist
 */
int array_search(int* arr, int arr_size, int query);


/**
 * @brief inserts a vlue into an array
 *
 * @param arr is a pointer to an array of integers to be inserted into
 * @param arr_size is the size of the array
 * @param insert is the value to be inserted
 * @return the index that the value was inserted into, or VAL_NOT_INSERTED if not inserted
 */
int array_insert(int* arr, int arr_size, int insert);


/**
 * @brief deletes the first occurance of a blue from an array
 *
 * @param arr is a pointer to an array of integers to be deleted from
 * @param arr_size is the size of the array
 * @param delete is the value to be deleted
 * @return the index thatg the value was deleted from, or VAL_NOT_FOUND if the value was not found in the array
 */
int array_delete(int* arr, int arr_size, int delete);


/**
 * @brief prints a representation of the array to stdout
 *
 * @param arr a pointer to an array to be printed
 * @param arr_size the size of the array
 */
void array_print(int* arr, int arr_size);

#endif

