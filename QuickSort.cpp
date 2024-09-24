#include <stdio.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);

void quick_sort(int a[], int l, int u) {
    int j;
    if (l < u) {
        j = partition(a, l, u);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, u);
    }
}

int partition(int a[], int l, int u) {
    int v = a[l];
    int i = l;
    int j = u + 1;
    do {
        do {
            i++;
        } while (a[i] < v && i <= u);
        do {
            j--;
        } while (a[j] > v);
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    a[l] = a[j];
    a[j] = v;
    return j;
}

int main() {
    int a[100], n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    quick_sort(a, 0, n - 1);
    
    printf("The sorted array is: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    return 0;
}

