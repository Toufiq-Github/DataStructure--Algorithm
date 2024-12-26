#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index) {
        if (index && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot() {
        if (heap.size() == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() {
        if (heap.size() == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap[0];
    }

    int getMin() {
        if (heap.size() == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return *min_element(heap.begin(), heap.end());
    }

    vector<int> getHeap() {
        return heap;
    }
};

class MinHeap {
private:
    vector<int> heap;

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int index) {
        if (index && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    vector<int> getHeap() {
        return heap;
    }
};

int main() {
    MaxHeap maxHeap;
    MinHeap minHeap;
    int choice, element;

    while (true) {
        cout << "\n1. Insert into Max Heap\n";
        cout << "\n2. Delete from Max Heap\n";
        cout << "\n3. Find Max Element\n";
        cout << "\n4. Find Min Element\n";
        cout << "\n5. Convert Max Heap to Min Heap\n";
        cout << "\n6. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                maxHeap.insert(element);
                break;
            case 2:
                maxHeap.deleteRoot();
                break;
            case 3:
                cout << "Max element: " << maxHeap.getMax() << endl;
                break;
            case 4:
                cout << "Min element: " << maxHeap.getMin() << endl;
                break;
            case 5: {
                vector<int> maxHeapArray = maxHeap.getHeap();
                for (int i : maxHeapArray) {
                    minHeap.insert(i);
                }
                vector<int> minHeapArray = minHeap.getHeap();
                cout << "Converted Min Heap: ";
                for (int i : minHeapArray) {
                    cout << i << " ";
                }
                cout << endl;
                break;
            }
            case 6:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

