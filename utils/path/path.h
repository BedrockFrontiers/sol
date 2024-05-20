#ifndef PATH_H
#define PATH_H

/**
 * @file path.h
 * @brief Header file for path utility functions.
 * 
 * This file declares utility functions for handling paths.
 */

/**
 * @brief Normalize a path by replacing backslashes with forward slashes.
 * 
 * This function normalizes a path by replacing backslashes with forward slashes.
 * 
 * @param path The path to be normalized.
 */
void normalize_path(char *path);

#endif