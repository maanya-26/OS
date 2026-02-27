#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least two elements.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int smallest = arr[0];
    int second_smallest = -1;
    for (i = 1; i < n; i++) {
        if (arr[i] != smallest) {
            second_smallest = arr[i];
            break;
        }
    }

    if (second_smallest == -1)
        printf("No second smallest element (all equal).\n");
    else
        printf("Second smallest element is: %d\n", second_smallest);

    return 0;
}
