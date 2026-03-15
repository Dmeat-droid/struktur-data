#include <bits/stdc++.h>

using namespace std;

// Penerapan record dengan struct

struct mahasiswa{
    string npm, nama, jurusan;
    int umur;
    string hobi[3];
};

int main(){
    // inisialisasi array of record
    mahasiswa mhs[3];

    // Input data mahasiswa
    for(int i = 0; i < 3; i++){
        cout << "Data mahasiswa ke-" << i+1 << endl;

        cout << "NPM        : ";
        cin >> mhs[i].npm;

        cout << "Nama       : ";
        cin >> mhs[i].nama;

        cout << "Jurusan    : ";
        cin >> mhs[i].jurusan;

        cout << "Umur       : ";
        cin >> mhs[i].umur;

        cout << "Masukkan 3 hobi:" << endl;
        for(int j = 0; j < 3; j++){
            cout << "Hobi ke-" << j+1 << " : ";
            cin >> mhs[i].hobi[j];
        }
        cout << endl;
    }

    // Display data mahasiswa
    cout << "\n===== DATA MAHASISWA ====\n";
    
    for(int i = 0; i < 3; i++){
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "NPM        : " << mhs[i].npm << endl;
        cout << "Nama       : " << mhs[i].nama << endl;
        cout << "Jurusan    : " << mhs[i].jurusan << endl;
        cout << "Umur       : " << mhs[i].umur << endl;

        cout << "Hobi       : ";
        for(int j = 0; j < 3; j++){
            cout << mhs[i].hobi[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
