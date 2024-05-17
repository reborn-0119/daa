#include <iostream>

using namespace std;

int comparisons = 0;

// Function to partition the array around a pivot element
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Select last element as pivot
  int i = (low - 1); // index of smaller element

  for (int j = low; j <= high - 1; j++) {
    comparisons++;
    // If current element is smaller than or equal to pivot
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

// Recursive function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[p] is now at right place
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  quickSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  cout << "Number of comparisons: " << comparisons << endl;

  return 0;
}
