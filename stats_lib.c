/*
 * Author: Hector Garcia
 * Course: EGR 226
 * Section: 905
 * Professor Ekin
 * Date: January 10, 2020
 * Description: This program will be utilized as a statistics
 * library to provide the function prototypes for stat
 */

#include "stats_lib.h"
#include <math.h>
/*
 * This functions find the maximum float entered
 * entered by the user
 */
float maximum(float nums[], int n)
{

    int a;                  // 'a' is variable that keeps track of elements
    float max = 0.0;        // the maximum is assigned the variable 'max'

    for ( a = 0; a < n; a++)
    {
        if (nums[a] > max)
        {
            max = nums[a];
        }
    }

    return max;
}

/*
 * This functions find the minimum float entered
 * entered by the user
 */
float minimum(float nums[], int n)
{
    int b;                      // 'b' is variable that keeps track of elements
    float min = nums[0];        // the maximum is assigned the variable 'max'

    for ( b = 0; b < n; b++)
    {
        if (nums[b] < min)
        {
            min = nums[b];
        }
    }

    return min;
}

/*
 * This functions find the mean float entered
 * entered by the user
 */
float mean(float nums[], int n)
{
    int c;                      // 'c' is variable that keeps track of elements
    float sum = 0.0;            // The sum of all the elements is assigned the variable 'sum'
    float mean = 0.0;           // The mean is assigned to the variable 'mean'

    for ( c = 0; c < n; c++)
    {
        sum = (sum + nums[c]);
        mean = sum / n;

    }
    return mean;
}

/*
 * This functions find the median float entered
 * entered by the user
 */
float median(float nums[], int n)
{
    int i, j;
    float temp = 0.0;       // temp variable holds onto an array element during
    // the sorting process
    float med = 0.0;        // med variable holds onto the median result

    // This nested for loops cycles through the array
    // and sorts the elements from low to high
    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            if (nums[j] > nums[i])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    // We have to take into consideration if there are odd
    // or even amount of elements
    if ((n % 2) != 0)   // if there's an even number elements
    {
        i = (n - 1) / 2;
        med = nums[i];
    }
    else {             // else there's an odd number of elements
        i = (n - 1) / 2;
        j = (n / 2);
        med = (nums[i] + nums[j]) / 2;
    }

    return med;
}


/*
 * This functions find the median float entered
 * entered by the user
 */
float variance(float nums[], int n)
{
    float mean_1;
    float array[n];
    float a = 0.0;
    float v = 0.0;

    mean_1 = mean(nums, n);

    for (int i = 0; i < n; i++) {
         a = a + pow((nums[i] - mean_1), 2);
    }

     v = a / (n - 1);

    return v;
}

/*
 * This function finds the standard deviation
 */

float standard_deviation(float nums[], int n) {
    float v = 0.0;
    float s = 0.0;

    v = variance(nums, n);

    s = sqrt(v);

    return s;
}

