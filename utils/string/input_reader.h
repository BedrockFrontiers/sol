#ifndef INPUT_READER_H
#define INPUT_READER_H

/**
 * @file input_reader.h
 * @brief Header file for input reading functions.
 */

/**
 * @brief Checks the input buffer for binary string characters.
 * 
 * This function checks the input buffer for binary string characters.
 * 
 * @param buffer The input buffer to be checked.
 */
void check_bstring_buffer(const char* buffer);

/**
 * @brief Reads input from the user.
 * 
 * This function reads input from the user.
 * 
 * @return A pointer to a character array containing the input.
 */
char* read_input();

#endif
