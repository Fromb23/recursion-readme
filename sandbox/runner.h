#ifndef RUNNER_H
#define RUNNER_H

#define MAX_OUTPUT_SIZE 8192

typedef struct {
    char stdout_output[MAX_OUTPUT_SIZE];
    char stderr_output[MAX_OUTPUT_SIZE];
    int exit_code;
} ExecutionResult;

ExecutionResult run_code(const char *source_code, const char *language);

#endif
