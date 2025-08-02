#include "utils.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "../typewriter/typewriter.h"

int clone_repo(const char *url, const char *target_dir)
{
	int result;
	char command[1024];
	char message[1024];

	snprintf(command, sizeof(command), "git clone %s %s", url, target_dir);
	result = system(command);

	if (result == 0)
	{
		snprintf(message, sizeof(message), "Repository cloned successfully into '%s'\n", target_dir);
		typewrite(3000, "%s", message);
	}

	return result;
}

int update_repo(const char *dir)
{
	int ret;

	ret = chdir(dir);
	if (ret != 0)
	{
		perror("chdir");
		return 1;
	}

	typewrite(20000, "Fetching latest changes...\n");
	ret = system("git fetch origin");
	if (ret != 0)
	{
		fprintf(stderr, "git fetch failed.\n");
		return 1;
	}

	typewrite(20000, "Resetting to origin/main...\n");
	ret = system("git reset --hard origin/main");
	if (ret != 0)
	{
		fprintf(stderr, "git reset failed.\n");
		return 1;
	}

	typewrite(20000, "Cleaning working directory...\n");
	ret = system("git clean -fdx");
	if (ret != 0)
	{
		fprintf(stderr, "git clean failed.\n");
		return 1;
	}

	ret = chdir("..");
	if (ret != 0)
	{
		perror("chdir back");
		return 1;
	}

	return 0;
}
