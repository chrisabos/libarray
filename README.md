# libarray
This is an example project demonstrating the functions of an array. Specifically, the theoretical efficiency of common data-structure functions like search, insert, and delete. This library does not allow for custom typing and is strictly programmed for integer arrays.

## How to use
Compile:
```
cmake .
make
```

This will generate a libarray.so which can be linked with your project

This also compiles an example program from example/main.c


## Neuances / Disclaimers
- integer only arrays
- '0' is considered to be a empty element in an array. This is to enable the insert and delete functions to operate properly.
- Arrays in C are simple enough, and this level of abstraction can be helpful in some circumstatnces. But in practice, an array with '0' defined as empty is not the most widely applicable implementation.
- There is no 'array_get' function as writing "arr[some_value]" is too simple to be abstracted.


## Functions
Doxygen style comments can be found in [include/array.h](/include/array.h)

### array_search
```
int array_search(int* arr, int arr_size, int query)
```
This function searches an array for a query value.

### array_insert
```
int array_insert(int* arr, int arr_size, int insert)
```
This function inserts a value into the first empty element in the array.

### array_delete
```
int array_delete(int* arr, int arr_size, int delete)
```
This function deletes the first occurance of the value referenced by the delete argument.

### array_print
```
int array_print(int* arr, int arr_size)
```
This function prints a representation of the array to stdout.

## Runtime Efficiency
| Function | Average | Worst Case |
| -------- | -------- | -------- |
| get | O(1) | O(1) |
| search | O(n) | O(n) |
| insert | O(n) | O(n) |
| delete | O(n) | O(n) |

Where 'n' is the size of the array.

