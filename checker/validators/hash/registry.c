#include <stdlib.h>
#include <string.h>
#include "registry_hash.h"
#include "hash.h"
#include "../validators/basics/basics.h"

static HashTable *validator_table = NULL;

extern int validate_recursion_file(const char *);
extern int validate_factorial_file(const char *);

void init_registry(void)
{
	validator_table = create_table(1024);
	if (!validator_table)
		return;

	insert(validator_table, "recursion", validate_recursion_file);
	insert(validator_table, "factorial", validate_factorial_file);
}

ValidatorFn get_validator(const char *task_name)
{
	if (!validator_table)
		return NULL;

	return get(validator_table, task_name);
}
