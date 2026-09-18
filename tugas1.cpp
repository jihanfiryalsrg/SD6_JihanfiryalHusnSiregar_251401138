#include <iostream>
using namespace std;

int main() {
    int arr[3][3][4];

    int nilai = 2;
    bool kurangi = true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = nilai;

                if (kurangi) {
                    nilai -= 1;
                } else {
                    nilai += 2;
                }
                kurangi = !kurangi;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << "Tabel " << (i + 1) << " : " << endl;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}