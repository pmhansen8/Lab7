
#include <stdio.h>
#include <stdbool.h>

int count = 0;



typedef struct nums{
    int num;
    int moved;
} nums;

void swap(nums* xp, nums* yp) {
    nums temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(nums arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].num > arr[j + 1].num) {
                arr[j].moved++;
                swap(&arr[j], &arr[j + 1]);
                count++;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void selectionSort(nums arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j].num < arr[min_idx].num) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            
            arr[i].moved++;
            arr[min_idx].moved++;
            swap(&arr[min_idx], &arr[i]);
            count++; 
        }
    }
}




void printArray(nums arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d (moved %d times) \n ", arr[i].num, arr[i].moved);
    }
    printf("\nTotal swaps: %d\n", count);
}




int main() {
    int size;
    printf("How long should the array be: ");
    scanf("%d", &size);

    nums array[size], arrayCopy[size]; 

    
    for (int i = 0; i < size; i++) {
        printf("Input num %d: ", i + 1);
        scanf("%d", &array[i].num);
        array[i].moved = 0;
        arrayCopy[i] = array[i]; 
    }

    
    printf("Bubble Sort: \n");
    bubbleSort(array, size);
    printArray(array, size);
    count = 0; 

    
    for (int i = 0; i < size; i++) {
        array[i] = arrayCopy[i];
    }

    
    printf("\nSelection Sort: \n");
    selectionSort(array, size);
    printArray(array, size);

    return 0;
}
