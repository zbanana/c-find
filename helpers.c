/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0) {
        return false;
    }
    // get the value in the middle of the array (store it because we are using it a couple of times)
    int midIndex = n/2;
    if (values[midIndex] == value) {
        return true;
    } else if (value < midIndex) {
        return search(value, values, midIndex-1);
    }
        
    return search(value, values + midIndex + 1, n - midIndex + 1);

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int countArray[MAX];
    for (int i = 0; i < n; i++) {
        countArray[values[n]]++;
    }
    
    int j = 0;
    for (int i = 0; i < MAX; i++) {
        while (countArray[i] > 0) {
            values[j] = i;
            j++;
            countArray[i]--;
        }
    }
    
    return;
}
