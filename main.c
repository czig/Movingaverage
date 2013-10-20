/*******************************************
  * Author: C2C Caleb Ziegler/CS-39
  * Created: 16 Oct 2013
  * Description: Computes the "moving average"
  * for a stream of data points it is receiving.
*******************************************/
#include <msp430.h> 
#include "L22_header.h"
#define N_AVG_SAMPLES 4
#define SIZE 10 //Amount of numbers in number array


int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    int Max;
    int Min;
    int range;
    int numbers[] = {174, 162, 149, 85, 130, 149, 153, 164, 169, 173};
    int sampleArray[N_AVG_SAMPLES];  //Array that numbers are moved into and out of
    Max = -256; // Lowest number possible for 1 byte, easily overwritten
    Min = 255; // Highest number possible for 1 byte, easily overwritten
    int i = 0;
    int x = 0;
    int avg;
    int avgs[SIZE+2]; //Sets up array to store moving average
    //I had to do this so that the program would not overwrite SizeOfArray

    //Variable x keeps track of i and stores its value
    for(i = 0; i <= N_AVG_SAMPLES; i++){
    	x = i;
    	sampleArray[i] = 0;
    	i = x;
    }

    //Determine size of array
   // int SizeOfArray = sizeof(numbers)/sizeof(int); //Number of bytes in numbers divided by number of bytes in int
    int SizeOfArray = SIZE; //Can get by with only

    //Finds the average
    for(i = 0; i<= SizeOfArray +1; i++){
    	avg = CalcAverage(sampleArray, N_AVG_SAMPLES);
    	avgs[i] = avg;
    	shiftarray(numbers[i], sampleArray, N_AVG_SAMPLES);
    }

    //Calculate max, min, and range of set
    Max = maximum(numbers, Max, SizeOfArray);
    Min = minimum(numbers, Min, SizeOfArray);
    range = CalculateRange(Max, Min);

	while(1){} //Trap CPU


	return 0;
}
***error