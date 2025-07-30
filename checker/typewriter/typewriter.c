#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "typewriter.h"

void typewrite(unsigned int delay_us, const char *format, ...)
{
	va_list args;
	char buffer[1024];
	const char *p;

	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	p = buffer;

	while (*p) {
		printf("%c", *p++);
		fflush(stdout);
		usleep(delay_us);
	}
}
