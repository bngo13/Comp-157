#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void bubbleSort(int arr[], int size) {
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[i - 1]) {
                isSorted = false;
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
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

void generateIncArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void generateIncDec(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

int main() {

    srand(0);

    int size = 1000000;
    int* arr = new int[size];

    generateIncDec(arr, size);

    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, size);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);

    cout << "Bubble took: " << duration.count() << "ms" << endl;

    return 0;
}
