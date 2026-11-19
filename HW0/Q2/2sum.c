#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 10000

void two_sum(int nums[], int nums_size, int target);
void quick_sort(int *arr, int *idx, int left, int right);

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;

	printf("enter the target value: ");
	scanf("%d", &target); //get the target number from the user

	printf("enter you numbers: ");
	//get the list of numbers from the user:
	while (scanf("%d", &nums[array_size++]) == 1);
	array_size--;

	two_sum(nums, array_size, target);

	return (0);
}

void two_sum(int nums[], int nums_size, int target) {

	int *idx = malloc(nums_size * sizeof(int));

	if (idx == NULL) { //check th malloc value
		printf("failed\n");
		return; 
	} 

	for (int i = 0; i < nums_size; i++) {
		idx[i] = i; //initialize the index array
	}

	quick_sort(nums, idx, 0, nums_size - 1); //sort the array

	int left_cntr =0;
	int right_cntr = nums_size - 1;

	while (left_cntr < right_cntr) { 

		//check if the sum of the two numbers is equal to the target
		if (nums[left_cntr] + nums[right_cntr] == target) {

			//print the indexes by format:
			if (idx[left_cntr] < idx[right_cntr]) {
				printf("(%d, %d)\n", idx[left_cntr], idx[right_cntr]);
			} else {
				printf("(%d, %d)\n", idx[right_cntr], idx[left_cntr]);
			}
			free(idx);
			return;

		//check if the sum of the two numbers is less than the target
		} else if (nums[left_cntr] + nums[right_cntr] < target) {
			left_cntr++;

		} else {
			right_cntr--;
		}
	}

	printf("not found\n");// if we got here so not found
	free(idx);
	return; 
}

void quick_sort(int *arr, int *idx, int left, int right)/*sort an arry and keep 
														the indexes*/
{
    // stop when there is nothing left to sort
    if (left >= right)
        return;

    // choose the last element as the pivot
    int pivot = arr[right];
    int i = left;

    // move smaller numbers to the left
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            // swap the numbers
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            // swap their original indexes
            temp = idx[i];
            idx[i] = idx[j];
            idx[j] = temp;

            i++;
        }
    }

    // move the pivot to its correct position
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;

    // move the pivot index as well
    temp = idx[i];
    idx[i] = idx[right];
    idx[right] = temp;

    // sort the left and right parts
    quick_sort(arr, idx, left, i - 1);
    quick_sort(arr, idx, i + 1, right);
}
