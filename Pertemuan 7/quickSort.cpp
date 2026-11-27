// Quick Sort

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){ 
    int pivot = arr[low];       // 7[p] 6 4 2[j] 1[i]
    int i = low + 1;
    int j = high;
    while (true) {
        while (i <= j && arr[i] <= pivot){
            i++;
        }                                   
        while (i <= j && arr[j] >= pivot){
            j--;
        }                                   
        if (i > j){
            break;
        }
        swap(arr[i], arr[j]); 
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    system("cls");
    int n;

    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];

    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Algoritma Quickk Sort
    quickSort(data, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}