#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fixes a broken heap by pushing an element down (Top-Down)
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Converts an arbitrary array into a valid Min-Heap (Bottom-Up)
void buildMinHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Inserts a new element dynamically and bubbles it up (Bottom-Up)
void insertMinHeap(int arr[], int* n, int value) {
    if (*n >= MAX_CAPACITY) {
        printf("\n[Error] Heap Overflow! Cannot insert %d.\n", value);
        return;
    }

    int i = *n;
    arr[i] = value;
    (*n)++;

    // Bubble up path to the parent node
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("\nSuccessfully inserted %d into the heap.\n", value);
}

// Removes and returns the minimum element (the root)
int extractMin(int arr[], int* n) {
    if (*n <= 0) {
        printf("\n[Error] Heap Underflow! The heap is empty.\n");
        return -1;
    }

    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    int rootValue = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;

    heapify(arr, *n, 0);
    return rootValue;
}

// Helper function to print the current state of the heap array
void printHeap(int arr[], int n) {
    printf("Current Min-Heap Array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[MAX_CAPACITY];
    int n = 0;
    int choice, value, minVal;

    // Initial Setup Phase
    printf("=== Min-Heap Initial Setup ===\n");
    printf("Enter the initial size of the array: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > MAX_CAPACITY) {
        printf("Invalid size entry. Exiting.\n");
        return 1;
    }

    if (n > 0) {
        printf("Enter %d integers separated by spaces:\n", n);
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid integer entry. Exiting.\n");
                return 1;
            }
        }
        // Build the heap right after user input
        buildMinHeap(arr, n);
        printf("\nInitial array structured successfully!\n");
    }

    // Menu Interactive Loop
    while (1) {
        printf("\n---------------------------------\n");
        printHeap(arr, n);
        printf("1. Insert new element\n");
        printf("2. Extract minimum value\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection parameter. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the integer value to insert: ");
                scanf("%d", &value);
                insertMinHeap(arr, &n, value);
                break;

            case 2:
                minVal = extractMin(arr, &n);
                if (minVal != -1) {
                    printf("\nExtracted Minimum Value: %d\n", minVal);
                }
                break;

            case 3:
                printf("\nExiting program. Goodbye!\n");
                return 0;

            default:
                printf("\n[Invalid Choice] Please select an option between 1 and 3.\n");
        }
    }

    return 0;
}
