#include <stdio.h>
#include "checker.h"

/**
 * main - Entry point for the checker program
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    const char *repo_url = "https://github.com/Fromb23/recursion-readme.git";
    const char *target_dir = "cloned_repo";

    if (clone_repo(repo_url, target_dir) != 0)
    {
        fprintf(stderr, "❌ Failed to clone the repository.\n");
        return 1;
    }

    printf("✅ Repository cloned successfully into '%s'\n", target_dir);
    return 0;
}