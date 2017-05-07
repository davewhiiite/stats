/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file  stats.h 
 * @brief stats.c header file for assessment m1
 *
 * header file for stats.c. this file hosts the declarations for functions that 
 * run in the stats.c file.
 *
 * @author  David White
 * @date 04-21-2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief prints the statistics from an unsigned array
 * 
 * The print_statistics() function merely calls other
 * functions within the stats.c program, pass the array
 * and length to them, in order to print the outputs of 
 * min, max, mean, and median functions.
 *
 * @param NONE
 *
 * @return no return values. Just prints
 */
void print_statistics(void);

/**
 * @brief print the contents of an array input
 *
 * the function takes unsigned char pointer to array, 
 * and an unsigned integer  as athe array length, and
 * print the contents of the array to screen
 *
 * @param array unsigned char pointer to the input data array
 * @param length unsigned int of length of the array
 *
 * @return returns void. Just prints, no input params
 */
void print_array(unsigned char * array, unsigned int length);

/**
 * @brief finds the median of an input array
 *
 * the function takes unsigned char pointer and unsigned int as 
 * location and length for an array of chars, then returns the median.
 *
 * @param array unsigned char pointer to array input
 * @param length unsigned int describing length of array
 * 
 * @return returns the median value of the array components
 */
unsigned char find_median(unsigned char * array, unsigned int length);

/**
 * @brief find the mean of an input array
 * 
 * the function takes unsigned char pointer and unsigned int as inputs
 * then calculates the mean of the array they reference. 
 * 
 * @param array unsigned char pointer to array input
 * @param length unsigned int describing the length of the array
 *
 * @return returns the mean value of the array components
 */
unsigned char find_mean(unsigned char * array, unsigned int length);

/**
 * @brief find the maximum value within an array
 * 
 * the function takes unsigned char pointer and unsigned int as inputs
 * then finds the maximum values within the array that they reference.
 * 
 * @param array unsigned char pointer to array input
 * @param length unsigned int describing the length of the input array
 *
 * @return returns the maximum value of the array components
 */
unsigned char find_maximum(unsigned char * array, unsigned int length);

/**
 * @brief find the minimum value within the array
 * 
 * the function takes unsigned char pointer and unsigned int as inputs
 * then finds the minimum value within the array they reference
 *
 * @param array unsigned char pointer to array input
 * @param length unsigned int describing the length of the input array
 *
 * @return returns the minimum value of the array components
 */
unsigned char find_minimum(unsigned char * array, unsigned int length);

/**
 * @brief sort the input array components from high to low
 * 
 * the function takes unsigned char pointer and unsigned int as inputs
 * describing an array. The function then sorts the array components
 * from high to low, and returns the result as an array.
 *
 * @param array unsigned char pointer to array input
 * @param length unsigned int describing the length of the input array
 * 
 * @return returns the unsigned char array, rearranged from high to low
*/
unsigned char sort_array(unsigned char * array, unsigned int length);


#endif /* __STATS_H__ */
