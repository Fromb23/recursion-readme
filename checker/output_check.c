#include "checker.h"
#include <ctype.h>
#define MAX_OUTPUT 4096

void trim_trailing_whitespace(char *str) {
	int len = strlen(str);
	while (len > 0 && isspace((unsigned char)str[len - 1])) {
		str[--len] = '\0';
	}
}

int check_output(const char *script_path, const char *expected_string) {
	char buffer[128];
	char expected_copy[MAX_OUTPUT];
	char full_output[MAX_OUTPUT] = "";
	FILE *fp;

	if ((fp = popen(script_path, "r")) == NULL) {
		fprintf(stderr, "Error running script: %s\n", script_path);
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), fp)) {
		strncat(full_output, buffer, MAX_OUTPUT - strlen(full_output) - 1);
	}
	pclose(fp);

	trim_trailing_whitespace(full_output);
	strncpy(expected_copy, expected_string, MAX_OUTPUT - 1);
	expected_copy[MAX_OUTPUT - 1] = '\0';
	trim_trailing_whitespace(expected_copy);

	if (strcmp(full_output, expected_copy) == 0) {
		printf("Output matches expected result.\n");
		return 0;
	} else {
		fprintf(stderr, "Output did NOT match expected result.\n");
		fprintf(stderr, "Got:\n%s\n", full_output);
		fprintf(stderr, "Expected:\n%s\n", expected_copy);
		return 1;
	}
}

