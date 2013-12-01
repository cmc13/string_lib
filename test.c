#include <stdio.h>
#include "string_lib.h"

int main()
{
	STRING str = str_new();
	STRING str2 = str_create("test test test! test test test!");
	STRING str3 = str_create("asdf                                                                                             \n\n\n\r\r\r");
	STRING str4 = str_create("                  ");

	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str2), (unsigned int)str_size(str2), str2);

	str_printf(&str, "%s", "this is a test!12345");
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str), (unsigned int)str_size(str), str);

	str_cat(&str, str2);
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str), (unsigned int)str_size(str), str);
	str_cat(&str, str2);
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str), (unsigned int)str_size(str), str);
	str_cat(&str, str2);
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str), (unsigned int)str_size(str), str);
	str_cat(&str, str2);
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str), (unsigned int)str_size(str), str);
	str_cat(&str, str2);
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str), (unsigned int)str_size(str), str);

	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str3), (unsigned int)str_size(str3), str3);
	str_trim(str3);
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str3), (unsigned int)str_size(str3), str3);

	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str4), (unsigned int)str_size(str4), str4);
	str_trim(str4);
	printf("[%u\\%u]: %s\n", (unsigned int)str_length(str4), (unsigned int)str_size(str4), str4);

	return 0;
}
