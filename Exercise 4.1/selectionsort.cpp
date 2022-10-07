#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int tempSmall = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[tempSmall] > arr[j]) {
                tempSmall = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[tempSmall];
        arr[tempSmall] = temp;
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
    selectionSort(arr, size);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);

    cout << "Selection took: " << duration.count() << "ms" << endl;

    return 0;
}
