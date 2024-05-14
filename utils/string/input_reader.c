#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void check_bstring_buffer(const char* buffer) {
	if (buffer == NULL) {
		fprintf(stderr, "Error on allocating memory.\n");
		exit(EXIT_FAILURE);
	}
};

char* read_input() {
	char* buffer = malloc(BUFFER_SIZE * sizeof(char));
	check_bstring_buffer(buffer);

	size_t size = 0;
	size_t capacity = BUFFER_SIZE;

	while (1) {
		if (fgets(buffer + size, BUFFER_SIZE, stdin) == NULL)
			
			break;
		size_t line_size = strlen(buffer + size);

		if (line_size < BUFFER_SIZE - 1 || buffer[size + (line_size - 1)] == '\n')
			break;

		size += line_size;
		capacity *= 2;

		buffer = realloc(buffer, capacity);
		check_bstring_buffer(buffer);
	}

	return buffer;
}