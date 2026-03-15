#include <bits/stdc++.h>

using namespace std;

int main(){
    int nilai[5];
    int max;

    for(int i = 0; i < 5; i++){
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai[i];
    }

    // Inisialisasi nilai max dimisalkan indeks pertama
    max = nilai[0];

    for(int i = 1; i < 5; i++){
        if(nilai[i] > max){ // Membandingkan nilai dengan nilai maksimum
            //Apabila nilai ke-i lebih dari max, maka ganti nilai max dengan nilai ke-i
            max = nilai[i];
        }
    }

    cout << "Nilai tertinggi adalah : " << max;

    return 0;
}
