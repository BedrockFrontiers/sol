#ifndef ANSI_SUPPORT_H
#define ANSI_SUPPORT_H

/**
 * @file ansi_support.h
 * @brief Header file for ANSI support functions.
 */

/**
 * @brief Enables ANSI support in the terminal.
 * 
 * This function enables ANSI support in the terminal on platforms where it is
 * available, such as Windows. ANSI support allows the use of ANSI escape codes
 * for text formatting and colorization.
 * 
 * @note This function is specifically designed for platforms where ANSI support
 * is optional or disabled by default, such as Windows. On platforms where ANSI
 * support is already enabled by default (e.g., most Unix-like systems), this
 * function may not have any effect.
 * 
 * @note Calling this function is necessary before using ANSI escape codes for
 * text formatting and colorization to ensure proper behavior on platforms where
 * ANSI support needs to be explicitly enabled.
 */
void enable_ansi_support();

#endif