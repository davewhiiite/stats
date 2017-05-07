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
 * @file stats.c
 * @brief main program for computing various statistical values of a data array
 *
 * The program defines an array of data. functions may be called to print the values,
 * and compute various values of statistically important phenomena (e.g. mean, min
 * max).
 *
 * @author Dave White
 * @date 04-21-2017
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  //declaring the main data array
  unsigned char numbers[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char * ptr;
  ptr = numbers;
  unsigned char max_out;
  unsigned char min_out;
  float med_out;
  float mean_out; 
  unsigned char * sorted_out;

  /* Statistics and Printing Functions Go Here */

  /* function to print the contents of the array */
  void print_array(unsigned char * array, unsigned int length){

    for(int i = 0; i < length; i++){
      printf("%d", *array);
      printf(", ");
      array++;
    }
  }

  /* function to return the median of an array */
  float find_median(unsigned char * array, unsigned int length){
  
    //variables must be float to store intermediate median values
    float median, med_a, med_b; 
    //various indexing variables 
    int med_index;
    int i, j, flag = 1;
    int temp;

    // full ascending sort function provided here
    for(i = 0; i < length; i++){

      flag = 0;
      for(j = 0; j < (length-1); j++){

        //this section compares two values, and if one precedes the other
        //the old values is stored in a temp variable, and the new one
        //replaces it. 
        if( array[j+1] < array[j]){
          temp = array[j];
          array[j] = array[j+1];
          array[j+1] = temp;
          flag = 1;
        } //end if statement
      } // end inner for loop
    } // end outer for loop

    if( (length & 1) == 1){ //if array length is odd
      med_index = length / 2; // the median is at the center of the array
      median = array[med_index];
    }
    else { // if the array length is even
      med_index = length/2;
      med_a = array[med_index - 1];
      med_b = array[med_index];
      median = ( (med_a + med_b) / 2 ); //take avg of 2x middle values
    }

    return median;
  }

  /* procedure for calculating the mean or average values of a number set */
  float find_mean(unsigned char * array, unsigned int length){

    float mean;
    float sum = 0;

    for(unsigned int i = 0; i < length; i++){
      sum += *array;
      array++;
    }
    mean = sum / length ;
    return mean;
  }

  /* procedure for calculating the maximum value in a set of numbers */
  unsigned char find_maximum(unsigned char * array, unsigned int length){ 

    unsigned char max;

    for(int i = 0; i < length; i++){
      if ( i == 0 ){
        max = *array;
      }
      if  ( *array > max ){
        max = *array;
      }
      array++;
    }
    return max;
  }

  /* procedure for finding the minimum value in a set of numbers */
  unsigned char find_minimum(unsigned char * array, unsigned int length){
    
    //unsigned int i;
    unsigned char min;

    for (int i = 0; i < length; i++){
      if ( i == 0 )
        min = *array;
      if ( *array < min )
        min = *array;
      array++;
    }
    return min;
  }

  /* procedure for sorting an array of numbers in descending order */
  unsigned char * sort_array(unsigned char * array, unsigned int length){

    int i, j, flag = 1;
    int temp;

    for(i = 0; i < length; i++){

      flag = 0;
      for(j = 0; j < (length-1); j++){
        
        if( array[j+1] > array[j]){
          temp = array[j];
          array[j] = array[j+1];
          array[j+1] = temp;
          flag = 1;
        } //end if statement
      } // end inner for loop
    } // end outer for loop

    return array;
  }

  /* procedure for printing the outputs of the various functions defined above */
  void print_statistics(void){
  
    printf("These stats for the following array: ");
    print_array(ptr, SIZE);
    printf("\n");

    max_out = find_maximum(ptr, SIZE);
    printf("The maximum of the set is: %d", max_out);
    printf("\n");

    min_out = find_minimum(ptr, SIZE);
    printf("The minimum of the set is: %d", min_out);
    printf("\n");

    mean_out = find_mean(ptr, SIZE);
    printf("The mean of the set is: %f", mean_out);
    printf("\n");

    med_out = find_median(ptr, SIZE);
    printf("The median of the set is: %f", med_out);
    printf("\n");

    sorted_out = sort_array(ptr, SIZE);
    printf("The sorted array follows (descending): ");
    for( int i = 0; i < SIZE; i++){
      printf("%d", *sorted_out);
      printf(", ");
      sorted_out++;
    }
  } // end print_statistics function

  print_statistics();
  
}

/* Add other Implementation File Code Here */
