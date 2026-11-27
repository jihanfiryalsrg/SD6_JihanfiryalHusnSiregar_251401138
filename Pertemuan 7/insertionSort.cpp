// Insertion sort

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

    //Insertion sort
    for (int i = 1; i < n; i++){ // 2 4 6 7[j] 1[i][key]
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key){ 
            data[j+1] = data[j];   // 2[j] 2[j+1] 4 6 7
            for (int k = 0; k < n; k++){
                cout << data[k] << " ";
            }
            cout << endl;
            j--;        // [j] 2 2 4 6 7
        }
        data[j+1] = key; // 1 2 4 6 7
        for (int k = 0; k < n; k++){
            cout << data[k] << " ";
        }
        cout<< endl;
    }

    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}