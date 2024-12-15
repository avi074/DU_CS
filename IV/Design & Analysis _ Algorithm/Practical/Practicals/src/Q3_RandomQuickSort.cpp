#include "algo.hpp"

using namespace algo;

// Driver code
int main() {
  int data[] = {8, 70, 16, 1, 10, 9, 12, 1, 10, 3, 2};
  int n = sizeof(data) / sizeof(data[0]);

  cout << "\n\t\tPractical 3\n\t  Randomized Quick Sort\n";
  
  cout << "\n Unsorted Array: \n";
  printArray(data, n);
  
  // perform quicksort on data
  cout << "\n Comparisons in Randomized Quick Sort : " << random_quickSort(data, 0, n - 1) << endl;
  
  cout << "\n Sorted array in ascending order: \n";
  printArray(data, n);
}