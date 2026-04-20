#include <stdio.h>

// Recursive Selection Sort
void selectionSort(int arr[], int n, int index) {
    int i, minIndex, temp;

    // Base case
    if (index >= n - 1)
        return;

    minIndex = index;

    // Find minimum element in remaining array
    for (i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap
    temp = arr[index];
    arr[index] = arr[minIndex];
    arr[minIndex] = temp;

    // Recursive call for next position
    selectionSort(arr, n, index + 1);
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
    selectionSort(arr, n, 0);

    // Output sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
