#include <stdio.h>

// Recursive function
int linearSearch(int arr[], int n, int key, int index) {
    // Base case: reached end
    if (index >= n)
        return -1;

    // If element found
    if (arr[index] == key)
        return index;

    // Recursive call
    return linearSearch(arr, n, key, index + 1);
}

int main() {
    int n, i, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Call recursive function
    result = linearSearch(arr, n, key, 0);

    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result + 1);

    return 0;
}
