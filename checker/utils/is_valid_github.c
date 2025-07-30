#include "utils.h"
#include <regex.h>

int is_valid_git_url(const char *url)
{
	regex_t regex;
	const char *pattern;
	int ret;

	pattern = "^(https://|git@|ssh://)?[^[:space:]]+\\.git$";

	if (url == NULL)
	{
		fprintf(stderr, "Error: NULL URL provided.\n");
		return 0;
	}

	ret = regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);
	if (ret != 0)
	{
		fprintf(stderr, "Error: Failed to compile regex.\n");
		return 0;
	}

	ret = regexec(&regex, url, 0, NULL, 0);
	regfree(&regex);

	if (ret != 0)
	{
		fprintf(stderr,
			"Error: Invalid Git repository URL: '%s'\n"
			"Hint: Make sure the URL ends with '.git', like:\n"
			"  https://github.com/user/repo.git\n",
			url);
		return 0;
	}

	return 1;
}
