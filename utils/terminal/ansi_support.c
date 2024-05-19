#include <stdio.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#ifdef _WIN32
#include <windows.h>

void enable_ansi_support() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE) {
		fprintf(stderr, "Error on handle console.\n");
		return;
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode)) {
		fprintf(stderr, "Error on catch console.\n");
		return;
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	if (!SetConsoleMode(hOut, dwMode)) {
		fprintf(stderr, "Error on turn to console mode.\n");
		return;
	}
}
#endif