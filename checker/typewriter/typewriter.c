#include <stdio.h>
#include <unistd.h>
#include "typewriter.h"

void typewrite(const char *text, unsigned int delay_us)
{
	while (*text) {
		printf("%c", *text++);
		fflush(stdout);
		usleep(delay_us);
	}
}
