#include <iostream>

using namespace std;

int comparisons = 0;

// Function to heapify a subtree rooted with node i which is an index in arr[]. 
// n is size of heap
void heapify(int arr[], int n, int i) {
  int largest = i;  // Initialize largest as root
  int left = 2 * i + 1;  // left = 2*i + 1
  int right = 2 * i + 2;  // right = 2*i + 2

  // If left child is larger than root
  comparisons++;
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than largest so far
  comparisons++;
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// Function to build a max heap from an array
void buildHeap(int arr[], int n) {
  // Start from bottommost and alternate halves to reach root
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

// Function to implement Heap Sort
void heapSort(int arr[], int n) {
  // Build a max heap
  buildHeap(arr, n);

  // One by one extract an element from heap
  for (int i = n - 1; i > 0; i--) {
    // Move current root to end
    swap(arr[0], arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  heapSort(arr, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  cout << "Number of comparisons: " << comparisons << endl;

  return 0;
}
