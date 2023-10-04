typedef struct _Range{
    int start, end;
} Range;
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
Range new_range(int left, int right){
    Range r;
    r.start = left;
    r.end = right;
    return r;
}
void Quick_Sort_1(int arr[],int len){
    if(len <= 0)
    return;
    Range reg[len];
    int p = 0;
    reg[p++] = new_range(0, len - 1);//创建新的range
    while (p) {
        Range range = reg[--p];//我们创建了一个Range数组，所以每循环一次，就p--，这样就会实现一个栈式的顺序进行了排列。
        if(range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2];
        int left = range.start, right = range.end;
        do {
            while (arr[left] < mid) ++left;
            while (arr[right] > mid) --right;
            if (left <= right) {
                swap(&arr[left], &arr[right]);
                left++;
                right--;
            }
        } while(left <= right);
    if (range.start < right) reg[p++] = new_range(range.start, right);
    if (range.end > left) reg[p++] = new_range(left, range.end);//这里将接下来需要的循环排进数组，根据p--依次完成接下来的运算循环
    }
  
}