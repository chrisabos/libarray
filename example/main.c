#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "array.h"


#define ANSI_COLOR_COMMAND  "\x1b[36m" //cyan
#define ANSI_COLOR_ARGUMENT "\x1b[33m" //yellow
#define ANSI_COLOR_RESET    "\x1b[0m"

#define ARRAY_SIZE 5
#define BUF_INPUT_SIZE 64


void print_help()
{
	char* help_msg =
		"Commands:\n"
		ANSI_COLOR_COMMAND "\thelp" ANSI_COLOR_RESET " - prints help\n"
		ANSI_COLOR_COMMAND "\tget" ANSI_COLOR_ARGUMENT " <index>" ANSI_COLOR_RESET " - returns the value at a given index\n"
		ANSI_COLOR_COMMAND "\tsearch" ANSI_COLOR_ARGUMENT " <value>" ANSI_COLOR_RESET " - returns the index of that value in the array\n"
		ANSI_COLOR_COMMAND "\tinsert" ANSI_COLOR_ARGUMENT " <value>" ANSI_COLOR_RESET " - inserts a value into the array\n"
		ANSI_COLOR_COMMAND "\tdelete" ANSI_COLOR_ARGUMENT " <value>" ANSI_COLOR_RESET " - deletes a value from an array\n"
		ANSI_COLOR_COMMAND "\tprint" ANSI_COLOR_RESET " - prints the array\n"
		ANSI_COLOR_COMMAND "\tquit" ANSI_COLOR_RESET " - quit to program\n";
	printf("%s\n", help_msg);
}

/**
 * @brief main function
 */
int main()
{
	bool running = true;
	int arr[ARRAY_SIZE];

	memset(arr, VAL_EMPTY, ARRAY_SIZE);

	print_help();

	do
	{
		size_t input_buf_size = BUF_INPUT_SIZE;
		char input_buf[input_buf_size];
		char *b = input_buf;
		size_t line_length;

		// terminal
		printf("> ");

		// get input
		line_length = getline(&b, &input_buf_size, stdin);

		// handle the quit command
		if (0 == strncmp("quit", input_buf, 4))
		{
			running = false;
		}

		// handle the help command
		else if (0 == strncmp("help", input_buf, 4))
		{
			print_help();
		}

		// handle the print command
		else if (0 == strncmp("print", input_buf, 5))
		{
			// leverage the array library helper function
			array_print(arr, ARRAY_SIZE);
		}
		
		// handle the get command
		else if (0 == strncmp("get", input_buf, 3))
		{
			int arg;

			if (line_length <= 5)
			{
				print_help();
				continue;
			}

			arg = atoi(&(input_buf[4]));

			// ensure the arg is within the bound of the array
			if (arg >= ARRAY_SIZE)
			{
				printf("Index out of bounds\n");
				continue;
			}

			printf("arr[%d] == %d\n", arg, arr[arg]);
		}

		// handle the search command
		else if (0 == strncmp("search", input_buf, 6))
		{
			int arg;
			int search_result;

			if (line_length <= 8)
			{
				print_help();
				continue;
			}

			arg = atoi(&(input_buf[7]));

			// leverage the array_search function
			search_result = array_search(arr, ARRAY_SIZE, arg);

			// error checking
			if (VAL_NOT_FOUND == search_result)
			{
				printf("Value %d was not found in the array\n", arg);
				continue;
			}

			printf("Found value %d at index %d\n", arg, search_result);
		}

		// handle the insert command
		else if (0 == strncmp("insert", input_buf, 6))
		{
			int arg;
			int insert_result;

			if (line_length <= 8)
			{
				print_help();
				continue;
			}

			arg = atoi(&(input_buf[7]));

			// leverage the array_insert function
			insert_result = array_insert(arr, ARRAY_SIZE, arg);

			// error checking
			if (VAL_NOT_INSERTED == insert_result)
			{
				printf("Value %d was not inserted. The array might be full\n", arg);
				continue;
			}

			printf("Value %d inserted at %d\n", arg, insert_result);
		}

		// handle the delete command
		else if (0 == strncmp("delete", input_buf, 6))
		{
			int arg;
			int delete_result;

			if (line_length <= 8)
			{
				print_help();
				continue;
			}

			arg = atoi(&(input_buf[7]));

			// leverage the array_delete function
			delete_result = array_delete(arr, ARRAY_SIZE, arg);

			// error checking
			if (VAL_NOT_FOUND == delete_result)
			{
				printf("Value %d was not deleted. Are you sure its in the array?\n", arg);
				continue;
			}

			printf("Value %d deleted from index %d\n", arg, delete_result);
		}

		// default
		else
		{
			printf("Command not recognized.\n");
		}
	}
	while(running);

	return EXIT_SUCCESS;
}
