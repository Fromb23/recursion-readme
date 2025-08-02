#ifndef UTILS_H
#define UTILS_H

#include "../main/checker.h"

extern char **g_task_names;
extern int g_task_name_count;

char *get_directory_path(const char *filepath, char *output, size_t size);
int check_task_files(Task *task);
void free_tasks(Task *tasks, int count);
int is_valid_git_url(const char *url);
int check_output(const char *script_path, const char *expected_string);
void trim_trailing_whitespace(char *str);
int clone_repo(const char *url, const char *target_dir);
char *extract_username(const char *url);
int rename_repo(const char *old, const char *new_path);
int update_repo(const char *dir);
int load_tasks(const char *json_file, const char *repo_dir, Task *tasks, int *task_count);

#endif
