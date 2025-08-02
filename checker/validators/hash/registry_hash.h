#ifndef REGISTRY_HASH_H
#define REGISTRY_HASH_H

#include "../validators.h"

typedef int (*ValidatorFn)(const char *filepath);

void init_registry(void);
ValidatorFn get_validator(const char *task_name);

#endif
