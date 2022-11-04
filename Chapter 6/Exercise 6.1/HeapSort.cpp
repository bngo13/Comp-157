#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void turnIntoHeap(int arr[], int heapSize, int rootNode) {
    // Set temporary root node for testing
    int root = rootNode;

    // Set left and right nodes
    int leftNode = 2 * rootNode + 1;
    int rightNode = 2 * rootNode + 2;

    if (rightNode < heapSize && arr[rightNode] > arr[root]) {
        root = rightNode;
    }

    // Test for left and right node being larger than root and swap
    if (leftNode < heapSize && arr[leftNode] > arr[root]) {
        root = leftNode;
    }

    // Check if root node has switched
    if (root != rootNode) {
        // Swap the two
        swap(arr[rootNode], arr[root]);

        // Recurse the subtree and continue with new root at the swapped out index
        turnIntoHeap(arr, heapSize, root);
    }

}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // Initially convert array into heap
        turnIntoHeap(arr, size, i);
    }

    // One by one replace first and last elements
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // swap first and last elements

        // turn the new array that got switched into another heap
        turnIntoHeap(arr, i, 0);
    }
}

void genRandomArray(int arr[], int wantedSize) {
    for (int i = 0; i < wantedSize; i++) {
        //arr[i] = rand() % wantedSize * 2 + 1; // Rand
        //arr[i] = i;// Inc
        arr[i] = wantedSize - i;// Dec
    }
}

static const int testSizes[] = {
    100,
    1000,
    10000,
    100000,
    1000000,
};

int main() {
    srand(0); // 0 For reproduction of results

    int totalTestSize = sizeof(testSizes) / sizeof(int);

    for (int i = 0; i < totalTestSize; i++) {
        int testSize = testSizes[i];

        int *arr = new int[testSize];
        genRandomArray(arr, testSize);

        auto start = chrono::high_resolution_clock::now();
        heapSort(arr, testSize);

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time Spent Sorting |" << testSize << "|: " << duration.count() << "ms" << endl;
    }
    return 0;
}
