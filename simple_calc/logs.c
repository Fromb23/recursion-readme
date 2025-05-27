#include "main.h"
#include <time.h>

/**
 * calculate_log10 - Calculates the base-10 logarithm of a number.
 * @x: The input value.
 *
 * Return: The base-10 logarithm of x, or 0 if x is non-positive.
 */


double calculate_log10(double x)
{
	if (x <= 0)
	{
		printf("Error: log10 is undefined for non-positive values.\n");
		return (0);
	}
	double result = log10(x);

	log_calculation("log10", x, result);

	return (result);
}

/**
 * calculate_ln - Calculates the natural logarithm of a number.
 * @x: The input value.
 *
 * Return: The natural logarithm of x, or 0 if x is non-positive.
 */
double calculate_ln(double x) {
    if (x <= 0) {
        fprintf(stderr, "Error: natural log of non-positive number\n");
        return NAN;
    }
    double result = log(x);
    log_calculation("ln", x, result);
    return result;
}

/**
 * calculate_ln - Calculates the natural logarithm of a number.
 * @x: The input value.
 *
 * Return: The natural logarithm of x, or 0 if x is non-positive.
 */


void log_calculation(const char *func_name, double x, double result) {
	time_t now;
	time(&now);
	FILE *log_file = fopen("calculator.log", "a"); 

	if (log_file) {
		fprintf(log_file, "[%s] %s(%.2lf) = %.2lf\n", 
				ctime(&now), func_name, x, result);
		fclose(log_file);
	}
	printf("%s(%.2lf) = %.2lf\n", func_name, x, result);
}
