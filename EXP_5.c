#include <stdio.h>

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}


void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}


void quickSort(int a[], int low, int high) {
    int i, j, pivot, temp;
    if (low < high) {
        pivot = a[low];
        i = low + 1;
        j = high;

        while (i <= j) {
            while (a[i] <= pivot)
                i++;
            while (a[j] > pivot)
                j--;

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main() {
    int n, i, choice;
    int arr[50];
    char ch;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    do {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Quick Sort\n");

        printf("Select one sort:\n");
        scanf("%d", &choice);

        
        printf("Enter array elements:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("\nYour unsorted array is:\n");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                break;
            case 2:
                selectionSort(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                break;
            case 4:
                quickSort(arr, 0, n - 1);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printf("\nYour sorted array is:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y');

    
}
