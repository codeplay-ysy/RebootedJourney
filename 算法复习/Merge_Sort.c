int min(int a,int b){
    return a < b ? a : b;
}
void merge_sort_1(int arr[],int len){
    int *a = arr;
    int *b = (int *) malloc(len *sizeof(int));
    int seg,start;
    for(seg = 1;seg < len; seg += seg){
        for(start = 0; start < len;start += 2 * seg){
            int low = start, mid = min(start + seg, len), high = min(start + 2 * seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while(start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while(start1 < end1)
                b[k++] = a[start1++];
            while(start2 < end2)
                b[k++] = a[start2++];

        }
        int *temp = a;
        a = b;
        b = temp;
    }
    int i;
    if (a != arr){
        for (i < 0; i < len; i++)
            a[i] = b[i];
            b = a;
    }
    free(b);
}
void merge_sort_2(int arr[], int reg[], int left, int right){
    if(left > right)
    return;
    int len = right - left,mid = len >> 1 + left;
    int start1 = left, end1 =mid;
    int start2 = mid+1, end2 = right;
    merge_sort_2(arr, reg, start1, end1);
    merge_sort_2(arr, reg, start2, end2);
    int k = left;
    while(start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[end1] ? arr[start1++] : arr[end1++];
    while(start1 <= end1)
        reg[k++] = arr[start1++];
    while(start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = left; k <= right; k++)
            arr[k] = reg[k];
}
