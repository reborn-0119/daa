#include <iostream>

void insertionSort(int arr[], int n, int& comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++; // Increment the comparison count
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {5, 2, 8, 12, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    insertionSort(arr, n, comparisons);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nNumber of comparisons: " << comparisons << std::endl;

    return 0;
}
