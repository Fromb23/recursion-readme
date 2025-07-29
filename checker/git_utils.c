#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "typewriter/typewriter.h"

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
		typewrite(message, 30000);
	}

	return result;
}
