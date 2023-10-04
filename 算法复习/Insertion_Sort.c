#include <stdio.h>

int main() {
    int arr[10] = {123, 23, 231, 2, 45, 25, 23, 1, 24, 3};
    int n, i, j, key;

    for (i = 1; i < 10; i++) {
        key = arr[i];
        j = i - 1;

        // 移动元素，直到找到适当的位置
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
