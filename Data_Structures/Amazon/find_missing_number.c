/**
** Author: Joshua Alana
** Date Created: 13/10/2024
** Purpose: Problem Statement:
** Given an array containing n - 1 integers in the range 1 to n, find the missing integer.
**/

// Using the Sum formula:::: first natural numbers is n * ( n + 1) / 2. 
// subbstract the sum of the given array from the total to get the missing number.


#include <stdio.h>

int findMissingNumber (int* nums, int numsSize) {
	
	int n = numsSize + 1;
	int total_sum = n * ( n + 1) / 2;

	
	int array_sum = 0;
	for (int i = 0; i < numsSize; i++) {
	array_sum += nums[i];
}
	return total_sum - array_sum;

}

int main() {
	int nums[] = {1,2,4,5,6};
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	int missingNumber = findMissingNumber(nums, numsSize);
	printf("The missing number is: %d\n", missingNumber);
	return 0; 
}
