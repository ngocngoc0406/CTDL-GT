#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 8, 2, 7, 3, 4, 9, 1, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Insertion Sort
    insertionSort(arr, n);
    cout << "Array sorted using Insertion Sort: ";
    printArray(arr, n);

    // Resetting the array
    int resetArr[] = {10, 8, 2, 7, 3, 4, 9, 1, 6, 5};

    // Selection Sort
    selectionSort(resetArr, n);
    cout << "Array sorted using Selection Sort: ";
    printArray(resetArr, n);

    // Resetting the array
    int resetArr2[] = {10, 8, 2, 7, 3, 4, 9, 1, 6, 5};

    // Bubble Sort
    bubbleSort(resetArr2, n);
    cout << "Array sorted using Bubble Sort: ";
    printArray(resetArr2, n);

    return 0;
}
