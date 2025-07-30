#include <unistd.h>
#include <string.h>
#include "linters.h"

int is_python_file(const char *filename)
{
	const char *dot;

	dot = strrchr(filename, '.');
	if (!dot || dot == filename)
		return 0;

	return strcmp(dot, ".py") == 0;
}

