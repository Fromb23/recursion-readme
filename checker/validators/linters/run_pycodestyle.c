#include "linters.h"
#include <stdio.h>
#include <stdlib.h>

int run_pycodestyle(const char *filepath)
{
	FILE *fp;
	char cmd[1024];
	char buffer[1024];
	int found_issues = 0;
	snprintf(cmd, sizeof(cmd), "pycodestyle %s", filepath);

	fp = popen(cmd, "r");
	if (!fp) {
		perror("popen");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), fp)) {
		fprintf(stderr, "Pycodestyle: %s", buffer);
		found_issues = 1;
	}

	pclose(fp);
	return found_issues;
}
