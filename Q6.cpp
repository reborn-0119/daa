#include <iostream>

using namespace std;

void countSort(int arr[], int n, int k) {
  // Create a count array to store the frequency of each element
  int count[k + 1] = {0};

  // Store the count of each element in the count array
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  // Cumulative sum of the count array
  for (int i = 1; i <= k; i++) {
    count[i] += count[i - 1];
  }

  // Output array to store the sorted elements
  int output[n];

  // Place elements back into the original array based on their count
  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--; // Decrement count after placing the element
  }

  // Copy the sorted elements back to the original array
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

int main() {
  int arr[] = {1, 3, 4, 2, 7, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 7; // Assuming the maximum element is 7

  cout << "Unsorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  countSort(arr, n, k);

  cout << "\nSorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}

