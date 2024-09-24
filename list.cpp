#include <stdio.h>
#include <stdlib.h>

void create(int[100], int *);
void insert(int[100], int *);
void deleteItem(int[100], int *);
void update(int[100], int *);
void traverse(int[100], int *);
void searching(int[100], int *);
void merging(int[100], int[100], int *, int *);

int main()
{
    int a[100], b[100], m, nel, pos, i, n, choice;

    printf("\nMenu for list program:\n");
    printf("1.Create\n2.Insert\n3.Delete\n4.Update\n5.Traverse\n6.Searching\n7.Merging\n");

    do
    {
        printf("\n---------------------------------------------------------------\n");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter no of elements of first list:\t");
            scanf("%d", &n);
            create(a, &n);
            break;
        case 2:
            insert(a, &n);
            break;
        case 3:
            deleteItem(a, &n);
            break;
        case 4:
            update(a, &n);
            break;
        case 5:
            traverse(a, &n);
            break;
        case 6:
            searching(a, &n);
            break;
        case 7:
            printf("\nEnter the size of the second list\t:");
            scanf("%d", &m);
            merging(a, b, &n, &m);
            break;
        default:
            printf("Invalid choice !!!");
        }
    } while (choice < 8);

    return 0;
}

void create(int a[100], int *n)
{
    int i;
    printf("Enter %d elements:\t", *n);
    for (i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void insert(int a[100], int *n)
{
    int pos, nel, i;
    printf("Enter position at which you want to insert new element:\t");
    scanf("%d", &pos);
    printf("Enter new element:\t");
    scanf("%d", &nel);
     for (i = *n - 1; i >= pos; i--)
     {
      a[i + 1] = a[i];
     }
     a[pos] = nel;
     *n = *n + 1;
}

void deleteItem(int a[100], int *n)
{
    int pos, i;
    printf("Enter position at which you want to delele an element: \t");
    scanf("%d", &pos);
    for (i = pos; i < *n; i++)
    {
        a[i] = a[i + 1];
    }
    *n = *n - 1;
}

void update(int a[100], int *n)
{
    int pos, num;
    printf("Enter position at which you want to update an element:\t");
    scanf("%d", &pos);
    printf("Enter new element\n");
    scanf("%d", &num); 
    a[pos] = num;
}

void traverse(int a[100], int *n)
{
    int i;
    printf("Current elements of list are:\n");
    for (i = 0; i < *n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void searching(int a[100], int *n)
{
    int k, i;
    printf("Enter term to search:\t");
    scanf("%d", &k);
    for (i = 0; i < *n; i++)
    {
        if (k == a[i])
        {
            printf("Search succesfull, %d found at index", i);
        }
    }

    if (i == *n)
        printf("Search Unsucessfull");
}

void merging(int a[100], int b[100], int *n, int *m)
{
    int i, j = *n;
    printf("Enter element of second list:\t");
    for (i = 0; i < *m; i++)
    {
        scanf("%d", &b[i]);
        a[j] = b[i];
        j++;
        *n = *n + 1;
    }
}

