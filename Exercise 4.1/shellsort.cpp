#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void shellSort(int arr[], int size) {
    // Big loop that covers halfing the spacing each iteration
    for (int spacing = size / 2; spacing > 0; spacing /= 2) {
        // Start checking numbers at spacing levels
        for (int i = spacing; i < size; i++) {
            int temp = arr[i];

            int j = i;

            while (j >= spacing && arr[j - spacing] > temp) {
                arr[j] = arr[j - spacing];
                j -= spacing;
            }

            arr[j] = temp;
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
        arr[i] = rand();
    }
}

int main() {

    srand(0);

    int size = 10000;
    int* arr = new int[size];

    generateArr(arr, size);

    auto start = chrono::high_resolution_clock::now();
    shellSort(arr, size);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);

    cout << "Shell took: " << duration.count() << "ms" << endl;

    return 0;
}
