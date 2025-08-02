#ifndef VALIDATORS_H
#define VALIDATORS_H

#include "../main/checker.h"
#include "linters/linters.h"
#include "./hash/registry_hash.h" 

#define HASH_LENGTH 65

typedef struct {
	const char *task_name;
	ValidatorFn validator;
} TaskValidator;

int dispatch_validation(Task *task, const char *filepath);

int validate_task(Task *task, const char *filepath);
int validate_recursion_file(const char *filepath);
int validate_factorial_file(const char *filepath);

int compute_file_hash(const char *filepath, char *output_hex);
int is_duplicate_hash(const char *username, const char *filepath, const char *hash, const char *log_path);
int append_hash_to_log(const char *username, const char *filepath, const char *hash, const char *log_path);
int check_plagiarism(const char *filepath, Task *task);

#endif
