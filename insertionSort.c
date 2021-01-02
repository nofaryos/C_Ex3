#include "insertionSort.h"
#include <stdio.h>

void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);

/*
Main function
*/

int main(){
	int arrayToSort[arraySize];
	int index = 0;
	int num;
	//getting 50 numbers and put them in an array
	while(index < arraySize){
		scanf("%d",&num);
		arrayToSort[index] = num;
		index++;
	}
	//sorting the array using insertion sort algorithm	
	insertion_sort(arrayToSort,arraySize);
	
	//Printing the sorted array
	for (int i = 0; i < arraySize - 1; i++){
		printf("%d, ",arrayToSort[i]);
	}
	
	printf("%d",arrayToSort[arraySize-1]);
	return 0;
}

/*
This function moves the following i organs in one cell array to the right
*/
void shift_element(int* arr, int i){
	
	int* ptr = NULL;
	 ptr = arr + i -1;
	 if(ptr != NULL){
	while(0 < i ){
		int temp = *ptr;
		*(ptr+1) = temp;
		i--;
		ptr--;
		}
	}
}

/*
Insertion sort function
*/

void insertion_sort(int* arr , int len){
	int temp;
	int counter;
	
	for(int i = 1; i < len; i++){	
		counter = 0;
		temp = *(arr+i);
		for(int j = i; j > 0 && *(arr+j-1) > *(arr+i); j--){
	
			counter++;
		}	
		shift_element(arr + i -counter, counter);
		*(arr + i - counter) = temp;
	}
}
