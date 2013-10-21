/*
 * L22_header.h
 * Author: C2C Caleb Ziegler
 * Date: 16 Oct 2013
 * Description: Header file for moving average computation
 */

int CalcAverage(int array[], int numberOfSamples);

void shiftarray(int sample, int array[], int numberOfSamples);

int maximum(int* Numbers, int maximum, int size);

int minimum(int* Numbers, int minimum, int size);

int CalculateRange(int max, int min);
