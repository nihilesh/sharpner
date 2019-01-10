#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int binary_search(int *array, int val);
int _binary_search(int *array, int start, int end, int val);


int main(int argc, char** argv) {
	int array[] = {1, 2, 5, 6, 18, 19, 30};
	binary_search(array, 5);
	return 0;
}

int binary_search(int *array, int val) {
	int len = sizeof(array)/sizeof(int);
	printf("Array length = %d\n", len);
	int pos = _binary_search(array, 0, len-1, 5);
	printf("position of 5 is : %d\n", pos);
	return 0;
}

int _binary_search(int *array, int start, int end, int val) {
	assert(array && " array can not be NULL");

	if (start > end){
		return -1;
	} else if (start == end) {
		return array[start] == val ? start: -1;
	}

	int mid = (start+end) / 2;
	int pos = val == array[start] ? start : (val == array[end] ? end : (val == array[mid] ? mid : -1));
	if (pos != -1) {
		return pos;
	} else if (val > array[mid]){
		return _binary_search(array, mid+1, end-1, val);
	}
	return _binary_search(array, start+1, mid-1, val);
}


