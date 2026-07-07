// Organizing library book id's

#include <stdio.h>

// Function to sort the array using the simple Quick Sort method
void quicksort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = first; // Set the first element as the pivot
        int i = first;
        int j = last;
        int temp;

        // Rearrange elements around the pivot
        while (i < j) {
            while (arr[i] <= arr[pivot] && i < last) {
                i++;
            }
            while (arr[j] > arr[pivot]) {
                j--;
            }
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap the pivot element into its correct sorted position
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        // Recursively sort the left and right parts
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main() {
    int n;

    // Read total number of books
    printf("Enter the number of books:");
    scanf("%d", &n);

    // create an array of name ids
    int ids[n];

    // Read the book IDs dataset
    for (int i = 0; i < n; i++) {
      printf("enter the id of  %d book:",i+1);
      scanf("%d", &ids[i]);
    }

    // Run simple quicksort from index 0 to n-1
    quicksort(ids, 0, n - 1);

    // Print the sorted elements separated by spaces
    for (int i = 0; i < n; i++) {
        printf("%d", ids[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
