/*
 * Author: Hector Garcia
 * Course: EGR 226
 * Section: 905
 * Professor Ekin
 * Date: January 10, 2020
 * Description: This program will be utilized as a statistics
 * library to provide the following statistic calculations:
 * maximum, minimum, mean, median, variance, and standard
 * deviation
 *
 * NOTE: I re-used some of my c-program to read in files from
 * my c-programming skills exam from EGR 106 on August 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "stats_lib.h"
#define NUM 300

int main(void)
{
    FILE *myFile = NULL;

    int count = 0;          // 'count' keeps track of amount of elements in the file
    int numRead;            // assigned to the result of fscanf() which is 1
    float array[NUM];          // array will hold all elements of the data file
    float values;           // this variable's address is used to assign the read values from the files to the array
    float max;              // max is the variable assigned to the maximum function results
    float min;              // min is the variable assigned to the minimum function results
    float mean_1 = 0.0;     // mean is the variable assigned to the mean function results
    float median_1 = 0.0;   // COMPLETE THIS
    float var = 0.0;        // the variance function is assigned to the variable 'var;
    float stand = 0.0;      // the standard deviation function is assigned to the variable 'stand'

    // Opens the data file named "data.txt" and reads it
    myFile = fopen("data.txt", "r");

    // Prompts message if the text file could not be opened
    if (myFile == NULL)
    {
        printf("Could not open datax.txt file. \n\n");
        return -1;
    }

    /*
     * This puts the read values in an array, and
     * reads the file until the end of it
     */
    while ( !feof(myFile))
    {
        numRead = fscanf(myFile, "%f", &values);
        array[count] = values;
        count++;
    }

    fclose(myFile);     // closes the first file

    max = maximum(array, count);                    // Calls the maximum function and assigns it to the variable max
    min = minimum(array, count);                    // Calls the minimum function and assigns it to the variable min
    mean_1 = mean(array, count);                    // Calls the mean function and assigns it to the variable mean_1
    median_1 = median(array, count);
    var = variance(array, count);                   // Calls the variance function and assigns it to the variable var
    stand = standard_deviation(array, count);       // Calls the standard deviation function and assigns it to the variable stand

    // Print statements for the results of each statistical function
    printf("Maximum: %g\n", max);
    printf("Minimum: %g\n", min);
    printf("Mean: %g\n", mean_1);
    printf("Median: %g\n", median_1);
    printf("Variance %g\n", var);
    printf("Standard Deviation: %g\n", stand);
}
