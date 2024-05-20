#include <stdio.h>

void normalize_path(char *path) {
   for (size_t i = 0; path[i] != '\0'; i++) {
      if (path[i] == '\\')
         path[i] = '/';
   }
}