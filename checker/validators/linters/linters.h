#ifndef LINTERS_H
#define LINTERS_H

int check_readme(const char *path);
int is_python_file(const char *filename);
int run_betty_linter(const char *filepath);
int run_pycodestyle(const char *filepath);

#endif
