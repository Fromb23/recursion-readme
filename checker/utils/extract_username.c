#include "utils.h"
#include <stdlib.h>

char *extract_username(const char *repo_url)
{
	const char *base;
	const char *slash;
	size_t len;
	char *username;

	base = strstr(repo_url, "github.com/");
	if (!base)
		return NULL;

	base += 11; /* length of 'github.com/' */

	slash = strchr(base, '/');
	if (!slash)
		return NULL;

	len = slash - base;
	username = (char *)malloc(len + 1);
	if (!username)
		return NULL;

	strncpy(username, base, len);
	username[len] = '\0';

	return username;
}

int rename_repo(const char *old, const char *new)
{
	if (rename(old, new) != 0)
	{
		perror("Rename failed");
		return 1;
	}
	return 0;
}
