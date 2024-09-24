#include <stdio.h>


int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (arr[mid] == x)
            return mid;

        
        if (arr[mid] < x)
            left = mid + 1;
    
        else
            right = mid - 1;
    }

    
    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    
    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int choice, x, result;

    do {
        
        printf("\nBinary Search Menu:\n");
        printf("1. Search for an element\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &x);
                result = binarySearch(arr, 0, n - 1, x);
                if (result == -1)
                    printf("Element %d is not present in array\n", x);
                else
                    printf("Element %d is present at index %d\n", x, result);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
                break;
        }

    } while (choice != 2);

    return 0;
}

