// Bubble Sort Algorithm

#include <iostream>
using namespace std;

int main() {
    system("cls");
    int n;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n]; // nama_arr[n]

    cout << "Masukkan elemen: "; // 2 6 4 7 1
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Bubble sort
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            cout << "Iterasi [i,j]: " << i << ", " << j << endl;
            if (data[j] > data [j+1]) {
                int temp = data[j];
                data [j] = data[j+1];
                data [j+1] = temp;
            }
        }
    }

    cout << "Data setelah diurutkan secara bubble sort: " << endl;
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}