#include <iostream>

using namespace std;

int comparisons = 0;

// Function to merge two sorted subarrays
void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temporary arrays
  int left[n1], right[n2];

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++)
    left[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    right[j] = arr[m + 1 + j];

  // Merge the temporary arrays back into arr[l..r]
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    comparisons++;
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of left[] if there are any
  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  // Copy the remaining elements of right[] if there are any
  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

// Recursive function to implement Merge Sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

int main() {
  int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  mergeSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  cout << "Number of comparisons: " << comparisons << endl;

  return 0;
}
