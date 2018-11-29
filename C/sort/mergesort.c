#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void print_array(int *arr, int len) {
	printf ( "\nArray: { " );
	for (int i = 0; i < len; i++ ) {
		printf(" %d ", arr[i]);
	}
	printf(" }\n");
}

/* Marge two arrays
	First = arr[l..m]
	Second = arr[m+1..r]
*/
void merge(int* arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int a1[n1], a2[n2];
	printf("\nMerge l=%d, m=%d, r=%d", l, m, r);
	memcpy(a1, &arr[l], sizeof(int) * n1);
	memcpy(a2, &arr[m+1], sizeof(int) * n2);
	int pos=l, i=0, j=0;
	for( ; i < n1 && j < n2; pos++){
		if( a1[i] <= a2[j] ){
			arr[pos] = a1[i];
			i++;
		}else{
			arr[pos] = a2[j];
			j++;	
		}
		printf("\npos: %d:%d", pos, arr[pos]);
	}
	while( i < n1 ) arr[pos++] = a1[i++];
	while( j < n2 ) arr[pos++] = a2[j++];
	printf("\nSorted array: " );
	print_array(&arr[l], r-l+1);
} 

void merge_sort(int *arr, int l, int r){
    assert(arr && "arr argument can not be null");
	printf("\nMerge_sort(l=%d, r=%d)", l , r);
	print_array(arr, 5);

    if ( l >= r ){
		return;
	}
    int m = l + ( r - l )/2;
	merge_sort(arr, l, m);
	merge_sort(arr, m+1, r);
	merge(arr, l, m, r);
}

int main() {
	int arr[] = { 11, 4, 23, 5, 66, 44, 33 };
	int len = (sizeof(arr)/sizeof(int)) - 1 ;  
	printf("\nBefore:");
	print_array(arr, len);
	merge_sort(arr, 0, len-1);
	printf("\nAfter:");
	print_array(arr, len);
	return 0;
}
