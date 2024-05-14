#ifndef DIRECTORY_CHECK_H
#define DIRECTORY_CHECK_H

/**
 * @file directory_check.h
 * @brief Header file containing a function to verify the execution directory.
 */

/**
 * @brief Verifies if the program is being executed from the specified directory.
 * 
 * This function checks if the program is currently running from the specified directory.
 * 
 * @param expected_dir The expected directory path to check against.
 * @return 1 if the current directory matches the expected directory, 0 otherwise.
 *         -1 if an error occurs while retrieving the current directory.
 */
int verify_execution_directory(const char* expected_dir);

#endif /* DIRECTORY_CHECK_H */
