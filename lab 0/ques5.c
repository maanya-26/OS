#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int largest, secondLargest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = secondLargest = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second largest element = %d\n", secondLargest);

    return 0;
}
