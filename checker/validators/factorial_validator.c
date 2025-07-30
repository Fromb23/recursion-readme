#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../checker.h"
#include "validators.h"
#include "../typewriter/typewriter.h"

int validate_factorial_file(const char *filepath)
{
	FILE *fp;
	char line[1024];
	char *trimmed_line;
	int found_docstring;
	char *success_msg;

	fp = NULL;
	trimmed_line = NULL;
	found_docstring = 0;
	success_msg = NULL;

	if (!filepath)
	{
		typewrite("Error: NULL filepath for factorial file\n", 3000);
		return 1;
	}

	fp = fopen(filepath, "r");
	if (!fp)
	{
		typewrite("Error opening file: ", 3000);
		typewrite(filepath, 3000);
		typewrite("\n", 3000);
		return 1;
	}

	if (!fgets(line, sizeof(line), fp))
	{
		typewrite("Error: ", 3000);
		typewrite(filepath, 3000);
		typewrite(" is empty\n", 3000);
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = '\0';
	trimmed_line = lstrip(line);

	if (strncmp(trimmed_line, "#!/usr/bin/env python3", 23) != 0)
	{
		typewrite("Error: First line must be '#!/usr/bin/env python3'\n", 3000);
		fclose(fp);
		return 1;
	}

	if (!fgets(line, sizeof(line), fp))
	{
		typewrite("Error: Second line missing in ", 3000);
		typewrite(filepath, 3000);
		typewrite("\n", 3000);
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = '\0';
	trimmed_line = lstrip(line);

	if (strlen(trimmed_line) != 0)
	{
		typewrite("Error: Second line must be blank\n", 3000);
		fclose(fp);
		return 1;
	}

	if (!fgets(line, sizeof(line), fp))
	{
		typewrite("Error: Third line missing in ", 3000);
		typewrite(filepath, 3000);
		typewrite("\n", 4000);
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = '\0';
	trimmed_line = lstrip(line);

	if (strncmp(trimmed_line, "def factorial(n)", 16) != 0)
	{
		typewrite("Error: Expected 'def factorial(n)' as function prototype\n", 3000);
		fclose(fp);
		return 1;
	}

	while (fgets(line, sizeof(line), fp))
	{
		line[strcspn(line, "\r\n")] = '\0';
		trimmed_line = lstrip(line);

		if (strstr(trimmed_line, "for") || strstr(trimmed_line, "while"))
		{
			typewrite("Error: Loops ('for' or 'while') are not allowed in factorial tasks\n", 3000);
			fclose(fp);
			return 1;
		}

		if (!found_docstring &&
				(strncmp(trimmed_line, "\"\"\"", 3) == 0 || strncmp(trimmed_line, "'''", 3) == 0))
		{
			found_docstring = 1;
		}
	}

	if (!found_docstring)
	{
		typewrite("Error: Missing docstring in factorial function\n", 3000);
		fclose(fp);
		return 1;
	}

	success_msg = malloc(strlen(filepath) + 40);
	if (!success_msg)
	{
		fclose(fp);
		return 1;
	}

	sprintf(success_msg, "%s passed factorial file checks.\n", filepath);
	typewrite(success_msg, 3000);
	free(success_msg);
	fclose(fp);
	return 0;
}
