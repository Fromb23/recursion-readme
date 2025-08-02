#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "validators.h"

int check_plagiarism(const char *filepath, Task *task)
{
	char hash[HASH_LENGTH];

	if (compute_file_hash(filepath, hash) != 0)
	{
		fprintf(stderr, "Failed to compute hash for file: %s\n", filepath);
		goto cleanup;
	}

	if (is_duplicate_hash(task->username, filepath, hash, LOG_PATH))
	{
		fprintf(stderr, "Plagiarism detected! Duplicate hash found for file: %s\n", filepath);
		goto cleanup;
	}

	if (append_hash_to_log(task->username, filepath, hash, LOG_PATH) != 0)
	{
		fprintf(stderr, "Failed to record hash to log for file: %s\n", filepath);
		goto cleanup;
	}

	if (task->username)
		free(task->username);

	return 0;

cleanup:
	if (task->username)
		free(task->username);
	return 1;
}

int compute_file_hash(const char *filepath, char *output_hex)
{
	FILE *file = fopen(filepath, "rb");
	int i;
	unsigned char buffer[1024];
	unsigned char hash[SHA256_DIGEST_LENGTH];
	size_t bytesRead;
	SHA256_CTX sha256;

	if (!file)
	{
		fprintf(stderr, "Failed to open file for hashing: %s\n", filepath);
		return 1;
	}

	SHA256_Init(&sha256);

	while ((bytesRead = fread(buffer, 1, sizeof(buffer), file))) {
		SHA256_Update(&sha256, buffer, bytesRead);
	}

	SHA256_Final(hash, &sha256);

	fclose(file);

	for (i = 0; i < SHA256_DIGEST_LENGTH; ++i)
		sprintf(output_hex + (i * 2), "%02x", hash[i]);

	output_hex[64] = '\0';
	return 0;
}

int is_duplicate_hash(const char *username, const char *filepath, const char *hash, const char *log_path)
{
	FILE *fp = fopen(log_path, "r");
	char line[512];
	char log_user[64], log_file[256], log_hash[HASH_LENGTH];

	if (!fp)
		return 0;


	while (fgets(line, sizeof(line), fp))
	{
		sscanf(line, "%63[^:]:%255[^:]:%64s", log_user, log_file, log_hash);

		if (strcmp(hash, log_hash) == 0 && strcmp(filepath, log_file) == 0)
		{
			if (strcmp(username, log_user) == 0)
			{
				fclose(fp);
				return 0;
			}
			else
			{
				fclose(fp);
				return 1;
			}
		}
	}

	fclose(fp);
	return 0;
}

int append_hash_to_log(const char *username, const char *filepath, const char *hash, const char *log_path)
{
	FILE *fp = fopen(log_path, "a");
	if (!fp)
	{
		fprintf(stderr, "Failed to open log for appending: %s\n", log_path);
		return 1;
	}

	fprintf(fp, "%s:%s:%s\n", username, filepath, hash);
	fclose(fp);
	return 0;
}
