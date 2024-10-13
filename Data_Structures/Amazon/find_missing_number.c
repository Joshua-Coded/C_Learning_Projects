/**
** Author: Joshua Alana
** Date Created: 13/10/2024
** Purpose: Find Missing Number in an Array
** Problem Statement: Given an array containing n - 1 integers in the range 1 to n, find the missing integer.
**/

#include <stdio.h>

// function to find the missing number

int findMissingNumber(int* nums, int numsSize) {
	// as we are missing a number, the size of array should be n;
		
	int n = numsSize + 1;
	
	// find the total sum of natural number
	int total_sum = n * ( n + 1 ) / 2;

	int array_sum = 0;
	
	for (int i = 0; i < numsSize; i++) {
	    array_sum += nums[i];
}
	return total_sum - array_sum;

}


int main() {
	int nums[] = {1,3,4,5,6,7};
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	int missingNumber = findMissingNumber(nums, numsSize);
	printf("The missing number is: %d\n", missingNumber);
	return 0;

}
