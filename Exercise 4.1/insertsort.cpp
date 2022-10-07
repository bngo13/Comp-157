#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void insertSort(int arr[], int size) {
    int i, j, origVal;

    for (int i = 1; i < size; i++) {
        origVal = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] >= origVal) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = origVal;
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void generateArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {

    srand(0);

    int size = 10000;
    int* arr = new int[size];

    generateArr(arr, size);

    auto start = chrono::high_resolution_clock::now();
    insertSort(arr, size);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);

    cout << "Insert took: " << duration.count() << "ms" << endl;

    return 0;
}
