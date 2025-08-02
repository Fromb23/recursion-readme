#include <stdio.h>
#include <time.h>
#include "logs.h"

#define TIMESTAMP_LOG "logs/repo_timestamps.log"

int log_clone_time(const char *username, const char *repo_dir)
{
	FILE *fp;
	time_t now;

	fp = fopen(TIMESTAMP_LOG, "a");
	if (!fp)
		return 1;

	now = time(NULL);
	fprintf(fp, "%s:%s:%ld\n", username, repo_dir, now);

	fclose(fp);
	return 0;
}
