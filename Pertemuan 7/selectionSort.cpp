// Selection Sort

#include <iostream>
using namespace std;

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

    // Selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;   
        for (int j = i + 1; j < n; j++) {
            if (data[minIndex] > data[j]) {
                minIndex = j;
            }
        }
        int temp = data[i]; 
        data[i] = data[minIndex]; 
        data[minIndex] = temp; 
        for (int k = 0; k < n; k++){
            cout << data[k] << " ";
        }
        cout << endl;
    }

    cout << "Array setelah selesai sorting: ";
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}