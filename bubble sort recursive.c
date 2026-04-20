#include <stdio.h>

// Recursive Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, temp;

    // Base case
    if (n == 1)
        return;

    // One pass (largest element moves to end)
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recursive call for remaining array
    bubbleSort(arr, n - 1);
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call recursive function
    bubbleSort(arr, n);

    // Output sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
