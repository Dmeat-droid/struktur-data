// Mengimpor library iostream untuk operasi input dan output
#include <iostream>

// Menggunakan namespace standar agar tidak perlu menulis std:: berulang kali
using namespace std;

int main() {
  // Mendeklarasikan variabel:
  // rows, columns: variabel iterator untuk loop
  // number: angka yang akan dicetak, diinisialisasi 1
  // n: batas jumlah baris
  int rows, columns, number = 1, n = 6;

  // Loop luar untuk mengatur baris
  for (rows = 0; rows <= n; rows++) {
    // Loop dalam untuk mencetak kolom sesuai jumlah baris saat ini
    for (columns = 0; columns < rows; columns++){
      // Menampilkan angka dan menambah nilainya
      cout << number << " ";
      number++;
    }
    // Pindah ke baris baru setelah satu baris selesai
    cout << "\n";
  }
  return 0;
}