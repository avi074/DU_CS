// Quick sort in C++
#include <iostream>
#include "sort.hpp"
using namespace std;

// Driver code
int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2, 5};
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "\nUnsorted Array: \n";
  printArray(data, n);
  
  // perform quicksort on data
  cout << "\n\nComparisons in Randomized Quick Sort : " << quickSort(data, 0, n - 1) << endl;
  
  cout << "\nSorted array in ascending order: \n";
  printArray(data, n);
}