// Double Hashing
#include <iostream> 
#include <vector> 
#include <string> 
 
using namespace std; 
 
const int TABLE_SIZE = 10;
 
class HashTable { 
private: 
    vector<pair<int, string>> table;
 
    // Fungsi hash pertama 
    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    // Fungsi hash kedua 
    int hash2(int key) {
        // Menggunakan metode hash "division" 
        return 7 - (key % 7);
    }

public: 
    HashTable() { 
        table.resize(TABLE_SIZE, make_pair(-1, "")); 
    } 
 
    // Fungsi untuk menambahkan data ke hash table dengan Double Hashing 
    void insert(int key, const string& value) { 
        int index = hash1(key); 
        int step = hash2(key); 
        int initialIndex = index; 
 
        while (table[index].first != -1) { 
            if (table[index].first == key) { 
                cout << "Kunci sudah ada dalam hash table. Memperbarui nilai." << endl; 
                table[index].second = value; 
                return; 
            } 
 
            index = (index + step) % TABLE_SIZE; 
 
            // Jika sudah mengelilingi seluruh tabel, maka hentikan 
            if (index == initialIndex) { 
                cout << "Tabel penuh. Tidak dapat menambahkan data." << endl; 
                return; 
            } 
        } 
 
        table[index] = make_pair(key, value); 
    } 
 
    // Fungsi untuk mencari nilai berdasarkan kunci 
    string search(int key) { 
        int index = hash1(key); 
        int step = hash2(key); 
        int initialIndex = index; 
 
        while (table[index].first != -1) { 
            if (table[index].first == key) { 
                return table[index].second; 
            } 
 
            index = (index + step) % TABLE_SIZE; 
 
            // Jika sudah mengelilingi seluruh tabel, maka kunci tidak ditemukan 
            if (index == initialIndex) { 
                return "Kunci tidak ditemukan"; 
            } 
        } 
 
        return "Kunci tidak ditemukan"; 
    } 
    // Fungsi untuk menghapus data dari hash table berdasarkan kunci 
    void remove(int key) { 
        int index = hash1(key); 
        int step = hash2(key); 
        int initialIndex = index; 
 
        while (table[index].first != -1) { 
            if (table[index].first == key) { 
                table[index] = make_pair(-1, "");  // Hapus data dengan menandai lokasi kosong 
                return; 
            } 
 
            index = (index + step) % TABLE_SIZE; 
 
            // Jika sudah mengelilingi seluruh tabel, maka kunci tidak ditemukan 
            if (index == initialIndex) { 
                return; 
            } 
        } 
    } 
}; 
 
int main() { 
    HashTable ht; 
 
    // Menambahkan data ke hash table 
    ht.insert(1, "Nilai 1"); 
    ht.insert(11, "Nilai 11"); 
    ht.insert(21, "Nilai 21"); 
    ht.insert(31, "Nilai 31"); 
 
    // Mencari nilai berdasarkan kunci 
    cout << "Nilai untuk kunci 11: " << ht.search(11) << endl; 
    cout << "Nilai untuk kunci 2: " << ht.search(2) << endl; 
 
    // Menghapus data dari hash table 
    ht.remove(11); 
    cout << "Nilai untuk kunci 11 setelah dihapus: " << ht.search(11) << endl; 
 
    return 0; 
}