#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../main/checker.h"
#include "../validators.h"
#include "../../typewriter/typewriter.h"

int validate_factorial_file(const char *filepath)
{
	FILE *fp = NULL;
	char line[1024];
	char *trimmed_line = NULL;
	int found_docstring = 0;
	int inside_docstring = 0;
	char *success_msg = NULL;

	if (filepath == NULL)
	{
		typewrite(3000, "Error: NULL filepath for factorial file\n");
		return 1;
	}

	fp = fopen(filepath, "r");
	if (fp == NULL)
	{
		typewrite(3000, "Error opening file: %s\n", filepath);
		return 1;
	}

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		typewrite(3000, "Error: %s is empty\n", filepath);
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = '\0';
	trimmed_line = lstrip(line);

	if (strncmp(trimmed_line, "#!/usr/bin/env python3", 23) != 0)
	{
		typewrite(3000, "Error: First line must be '#!/usr/bin/env python3'\n");
		fclose(fp);
		return 1;
	}

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		typewrite(3000, "Error: Second line missing in %s\n", filepath);
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = '\0';
	trimmed_line = lstrip(line);

	if (strlen(trimmed_line) != 0)
	{
		typewrite(3000, "Error: Second line must be blank\n");
		fclose(fp);
		return 1;
	}

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		typewrite(3000, "Error: Third line missing in %s\n", filepath);
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = '\0';
	trimmed_line = lstrip(line);

	if (strncmp(trimmed_line, "def factorial(n)", 16) != 0)
	{
		typewrite(3000, "Error: Expected 'def factorial(n)' as function prototype\n");
		fclose(fp);
		return 1;
	}

	while (fgets(line, sizeof(line), fp) != NULL)
	{
		line[strcspn(line, "\r\n")] = '\0';
		trimmed_line = lstrip(line);

		if (strncmp(trimmed_line, "\"\"\"", 3) == 0 || strncmp(trimmed_line, "'''", 3) == 0)
		{
			if (!found_docstring)
				found_docstring = 1;

			inside_docstring = !inside_docstring;
			continue;
		}

		if (inside_docstring)
			continue;

		if (strstr(trimmed_line, "for ") != NULL || strstr(trimmed_line, "while ") != NULL)
		{
			typewrite(3000, "Error: Loops ('for' or 'while') are not allowed in factorial tasks\n");
			fclose(fp);
			return 1;
		}
	}

	if (!found_docstring)
	{
		typewrite(3000, "Error: Missing docstring in factorial function\n");
		fclose(fp);
		return 1;
	}

	success_msg = malloc(strlen(filepath) + 50);
	if (success_msg == NULL)
	{
		fclose(fp);
		return 1;
	}

	sprintf(success_msg, "%s passed factorial file checks.\n", filepath);
	typewrite(3000, "%s", success_msg);

	free(success_msg);
	fclose(fp);
	return 0;
}
