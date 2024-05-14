#ifndef READ_FILE_H
#define READ_FILE_H

/**
 * @file read_file.h
 * @brief Header file for text file reading functions.
 */

/**
 * @brief Reads content from a text file.
 * 
 * This function reads content from a text file specified by the filename.
 * 
 * @param filename The name of the text file to be read.
 * @return A pointer to a character array containing the content of the file.
 */
char* read_file(const char* filename);

#endif