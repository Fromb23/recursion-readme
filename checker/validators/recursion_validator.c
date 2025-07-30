#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main/checker.h"
#include "../typewriter/typewriter.h"
#include "validators.h"

/* Left-strip whitespace from a string */
char *lstrip(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return str;
}

int validate_recursion_file(const char *filepath)
{
	FILE *fp = NULL;
	char line[1024];
	char expected_func[512];
	char func_name[256];
	const char *filename = NULL;
	char *trimmed_line = NULL;
	char message[2048];
	int found_docstring = 0;
	size_t len = 0;

	if (filepath == NULL)
	{
		fprintf(stderr, "Error: NULL filepath provided.\n");
		return 1;
	}

	fp = fopen(filepath, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", filepath);
		return 1;
	}

	/* Extract task name from path for function match */
	filename = strrchr(filepath, '/');
	if (!filename || strlen(filename) < 5)
	{
		fprintf(stderr, "Error: Invalid filepath '%s'\n", filepath);
		fclose(fp);
		return 1;
	}
	filename++; /* skip slash */

	strncpy(func_name, filename, sizeof(func_name) - 1);
	func_name[sizeof(func_name) - 1] = '\0';

	len = strlen(func_name);
	if (len < 4 || strcmp(&func_name[len - 3], ".py") != 0)
	{
		fprintf(stderr, "Error: Filename must end with .py: '%s'\n", filename);
		fclose(fp);
		return 1;
	}
	func_name[len - 3] = '\0'; /* remove .py */

	snprintf(expected_func, sizeof(expected_func), "def %s(", func_name);

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		fprintf(stderr, "Error: %s is empty\n", filepath);
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = 0;
	trimmed_line = lstrip(line);

	if (strncmp(trimmed_line, "#!/usr/bin/env python3", 23) != 0)
	{
		fprintf(stderr, "Error: First line must be '#!/usr/bin/env python3'\n");
		fclose(fp);
		return 1;
	}

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		fprintf(stderr, "Error: Second line missing\n");
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = 0;
	trimmed_line = lstrip(line);
	if (strlen(trimmed_line) != 0)
	{
		fprintf(stderr, "Error: Second line must be blank\n");
		fclose(fp);
		return 1;
	}

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		fprintf(stderr, "Error: Third line missing\n");
		fclose(fp);
		return 1;
	}
	line[strcspn(line, "\r\n")] = 0;
	trimmed_line = lstrip(line);

	if (strncmp(trimmed_line, expected_func, strlen(expected_func)) != 0)
	{
		fprintf(stderr, "Error: Expected function definition '%s'\n", expected_func);
		fclose(fp);
		return 1;
	}

	while (fgets(line, sizeof(line), fp) != NULL)
	{
		line[strcspn(line, "\r\n")] = 0;

		if (strlen(line) == 0)
			continue;

		trimmed_line = lstrip(line);
		if (strncmp(trimmed_line, "\"\"\"", 3) == 0 || strncmp(trimmed_line, "'''", 3) == 0)
		{
			found_docstring = 1;
			break;
		}
		else
		{
			fprintf(stderr, "Error: Expected a docstring (\"\"\" or ''') immediately after function definition\n");
			fclose(fp);
			return 1;
		}
	}

	if (!found_docstring)
	{
		fprintf(stderr, "Error: Docstring not found after function definition\n");
		fclose(fp);
		return 1;
	}
	/* 6. Ensure no loops are used */
	while (fgets(line, sizeof(line), fp) != NULL) {
		trimmed_line = lstrip(line);
		if (strstr(trimmed_line, "for ") != NULL || strstr(trimmed_line, "while ") != NULL) {
			fprintf(stderr, "Error: Loops ('for' or 'while') are not allowed in recursion tasks\n");
			fclose(fp);
			return 1;
		}
	}

	/* Only successful result is animated */
	snprintf(message, sizeof(message), "%s passed recursion file checks.\n", filepath);
	typewrite(25000, "%s", message);

	fclose(fp);
	return 0;
}
