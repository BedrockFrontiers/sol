#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "path.h"

int verify_execution_directory(const char* expected_dir) {
   char current_dir[1024];
   if (getcwd(current_dir, sizeof(current_dir)) == NULL) {
      perror("Error getting current directory");
      return -1;
   }

   normalize_path(current_dir);
   char expected_dir_normalized[1024];
   strcpy(expected_dir_normalized, expected_dir);
   normalize_path(expected_dir_normalized);

   size_t current_dir_length = strlen(current_dir);
   size_t expected_dir_length = strlen(expected_dir_normalized);

   if (current_dir_length < expected_dir_length)
      return 0;

   if (strcmp(current_dir + current_dir_length - expected_dir_length, expected_dir_normalized) == 0)
      return 1;

   return 0;
}