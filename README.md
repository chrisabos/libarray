# libarray
This library makes working with arrays in C easier.

## How to use
Compile:
```
cmake .
make
```

This will generate a libarray.so which can be linked with your project

This all compiles an example program from example/main.c


## Functions

`int array_search(int* arr, int arr_size, int query)`
: This function finds the first occurance of a value in an array.
: *arr* is the array to be searched
: *arr_size* is the size of the array
: *query* is the value to be searched for
