#include<stdio.h>
void Shell_Sort(int arr[],int len) {
	int i, j, tmp, gap;
	for(gap = len >> 1; gap > 0; gap >>= 1){
		for(i = gap; i < len; i++){
		tmp = arr[i];
		for(j = i - gap; j >= 0 && arr[j] > tmp; j -= gap)
		    arr[j+gap] = arr[j];
		arr[j+gap] = tmp;
	}
    }
}