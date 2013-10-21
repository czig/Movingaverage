/*
 * L22_imp.c
 * Author: C2C Caleb Ziegler
 * Date: 16 Oct 2013
 * Description: Implementation for moving average computation
 */

#include "moving_average.h"

/*
 *Sums up all the numbers in the input array and
 *divides by the amount of numbers in the array
 *to get an average.
 */
int CalcAverage(int array[], int amountSamples){
	int sum = 0;
	int i;

	for(i = 0; i < amountSamples; i++){
		sum += array[i];
	}

	int avg = sum / amountSamples;

	return avg;
}

/*
 * Shift array over by 1 and bring next number
 * into array
 */
void shiftarray(int number, int array[], int amountSamples){
	int i;

	for(i=0; i < amountSamples-1; i++){
		array[i] = array[i+1]; // Move array to the right one place
	}

	array[amountSamples-1] = number; //Move the next number into the array
}

/*
 * Referencing values in locations in numbers array and comparing
 * number with maximum, and if number is greater than maximum, the
 * new maximum is the current number. Increments the location
 * in the array at the end.
 *
 */
int maximum(int* Numbers, int maximum, int size){
	int i;

	for(i = 0; i < size; i++){
		if(*Numbers > maximum){
			maximum = *Numbers;
		}
        Numbers++;
	}

	return maximum;
}

/*
 * Referencing values in locations in numbers array and comparing
 * number with minimum, and if number is less than maximum, the
 * new minimum is the current number. Increments the location
 * in the array at the end.
 *
 */
int minimum(int* Numbers, int minimum, int size){
	int i;

	for(i = 0; i < size; i++){
		if(*Numbers < minimum){
			minimum = *Numbers;
		}
		Numbers++;
	}

	return minimum;
}

/*
 *Range is defined as the difference between the maximum
 *and minimum values. This function does that.
 */
int CalculateRange(int max, int min){
	return max - min;
}

