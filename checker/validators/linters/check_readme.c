#include "linters.h"
#include <stdio.h>

int check_readme(const char *path)
{
	FILE *f = NULL;
	char fullpath[1024];
	long size = 0;

	snprintf(fullpath, sizeof(fullpath), "%s/README.md", path);

	f = fopen(fullpath, "r");
	if (!f) {
		fprintf(stderr, "Missing README.md in %s\n", path);
		return 0;
	}

	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fclose(f);

	if (size <= 0) {
		fprintf(stderr, "README.md is empty in %s\n", path);
		return 0;
	}

	printf("README.md found and is not empty in %s\n", fullpath);
	return 1;
}

