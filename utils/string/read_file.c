#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *filename) {
   FILE *file = fopen(filename, "r");
   if (file == NULL) {
      fprintf(stderr, "Error: Failed to open file %s.\n", filename);
      return "$<ERROR.FAILED_TO_OPEN_FILE>$";
   }

   char *content = NULL;
   char line[1000];
   size_t capacity = 1000;
   size_t size = 0;

   while (fgets(line, sizeof(line), file) != NULL) {
      size_t line_length = strlen(line);

      if (content == NULL) {
         content = strdup(line);
      } else {
         content = realloc(content, size + line_length + 1);
         if (content == NULL) {
            fprintf(stderr, "Error on allocating memory.\n");
            return "$<ERROR.NULL_FILE_CONTENT>$";
         }
         strcat(content, line);
      }
      size += line_length;
   }

   fclose(file);
   return content;
}
