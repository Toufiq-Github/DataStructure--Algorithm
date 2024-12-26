#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    srand(time(0)); // Seed for random number generator
    int randomIndex = low + rand() % (high - low + 1);
    int pivot = arr[randomIndex];
    swap(arr[randomIndex], arr[high]); // Move pivot to the end for partitioning
    int left = low;
    int right = high - 1;

    while (left <= right) {
        while (left <= right && arr[left] <= pivot) {
            ++left;
        }
        while (right >= left && arr[right] > pivot) {
            --right;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
