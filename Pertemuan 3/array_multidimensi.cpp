#include <iostream>

using namespace std;

int main(){
    //  Inisialisasi array multidimensi dengan 3 baris dan 4 kolom beserta isinya
    int matriks[3][4] = 
    {{255, 255, 250, 240},
     {150, 200, 255, 255},
     {  0,  50, 150, 200}
    };

    // Menggunakan nested loop untuk print array multidimensi
    for (int baris = 0; baris < 3; baris++){
        for(int kolom = 0; kolom < 4; kolom++){
            cout << matriks[baris][kolom] << " ";
        }
        cout << "\n";
    }
}
