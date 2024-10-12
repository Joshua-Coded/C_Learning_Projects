/**
** Author: Joshua Alana
** Date Created: 12/10/2024
** Purpose: Problem Statement:
** Given an array of integers nums and an integer target, return the indices of the two num** bers such that they add up to target. You may assume that each input would have exactly ** one solution, and you may not use the same element twice.
**/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for hash map nodes

struct HashMapNode {
	int key;
	int value;
	struct HashMapNode* next;
};

// HASH MAP SIZE

#define HASH_MAP_SIZE 1000

// Hash function to generate index

int hashFunction(int key) {
	return abs(key) % HASH_MAP_SIZE;
}

// insert into hash map

void insert(struct HashMapNode** hashMap, int key, int value) {
	int index = hashFunction(key);
	struct HashMapNode* newNode = (struct HashMapNode*)malloc(sizeof(struct HashMapNode));
	newNode->key = key;
	newNode->value = value;
	newNode->next = hashMap[index];
	hashMap[index] = newNode;
}

// search in hash map

int search(struct HashMapNode** hashMap, int key) {
	int index = hashFunction(key);
	struct HashMapNode* current = hashMap[index];
	while (current != NULL) {
	   if (current->key == key) {
	      return current->value;
}
 current = current->next;
}

return -1; // not found
}

// function to find two sum

int*  twoSum(int* nums, int numsSize, int target, int* returnSize) {
 // we need to create a hash map (array of pointers to nodes)

	struct HashMapNode* hashMap[HASH_MAP_SIZE] = { NULL };
	
	// allocate memory for the result
	int* result = (int*)malloc(2 * sizeof(int));
	
	for (int i = 0; i < numsSize; i ++) {
	    int complement = target - nums[i];

	// check if the complement exists in the hash map
	int complementIndex = search(hashMap, complement);
	        if (complementIndex != -1) {
            // If found, return the indices
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }

	
// otherwise insert the current number and its index into the hash map
	insert(hashMap, nums[i], i);

}

	*returnSize = 0;
	return NULL; 
}

int main() {
	int nums[] = {2, 7, 11, 15};
	int target = 9;
	int returnSize;
	int* result = twoSum(nums, 4, target, &returnSize);

	if (returnSize == 2) {
	  printf("Indices: [%d, %d]\n", result[0], result[1]);
} else {
	printf("No solution found.\n");

}

free(result);
return 0;

}
