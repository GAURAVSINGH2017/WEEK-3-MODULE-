// Online store sales ranking   

#include <stdio.h>

// Function to sort the array in descending order using the simple Quick Sort method
void quicksort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = first; // Set the first element as the pivot
        int i = first;
        int j = last;
        int temp;

        // Rearrange elements around the pivot for DESCENDING order
        while (i < j) {
            while (arr[i] >= arr[pivot] && i < last) {
                i++;
            }

            while (arr[j] < arr[pivot]) {
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

    // Read total number of sellers
    printf("enter the number of sellers:");
    scanf("%d", &n);

    // CREATE AN ARRAY OF NAMED sales 
    int  sales[n];

    // Read the sales dataset
    for (int i = 0; i < n; i++) {
      printf("enter the data of %d sales:",i+1);
        scanf("%d", &sales[i]);
    }

    // Run simple quicksort from index 0 to n-1
    quicksort(sales, 0, n - 1);

    // 1. Print the sorted sales figures in descending order
    for (int i = 0; i < n; i++) {
        printf("%d", sales[i]);
        if (i < n - 1) { 
            printf(" ");
        }
    }
    printf("\n");

    // 2. Print Top 3 highest sales values
    printf("Top 3: %d %d %d\n", sales[0], sales[1], sales[2]);

    // 3. Calculate and print the average of the top 3 values
    int  sum = sales[0] + sales[1] + sales[2];
    int average = sum / 3;
    printf("Average: %d\n", average);

    return 0;
}
