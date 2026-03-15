#include <bits/stdc++.h>

using namespace std;

int main () {
    int nilai[5];// Deklarasi array dengan ukuran 5
     
    for(int i = 0; i < 5; i++){
        cout << "Masukkan nilai ke-" << i << " : ";
        cin >> nilai[i];// nilai dimasukkan kedalam array indeks ke i
    }

    cout << "\nData yang dimasukkan:" << endl;

    for(int i = 0; i < 5; i++){
        // Mencetak array nilai indeks ke-i
        cout << nilai[i] << endl;
    }

    return 0;
}
