#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *filename) {
   FILE *file = fopen(filename, "r");
   char* content = NULL;
   char line[1000];

   size_t size = 0;
   size_t capacity = 1000;

   if (file == NULL) {
      fprintf(stderr, "Error: Failed to open file %s.\n", filename);
      exit(EXIT_FAILURE);
   }

   while(fgets(line, sizeof(line), file) != NULL) {
      if (size + sizeof(line) >= capacity) {
         capacity *= 2;
         content = realloc(content, capacity);
         if (content == NULL) {
            fprintf(stderr, "Error on allocating memory.\n");
            exit(EXIT_FAILURE);
         }
      }
      strcat(content, line);
      size += strlen(line);
   }
   
   fclose(file);
   return content;
}
