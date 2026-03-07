// Mengimpor header file untuk operasi input dan output
#include <iostream>

// Menggunakan namespace standar agar tidak perlu menulis std:: berulang kali
using namespace std;

// Fungsi utama program
int main () {
  // Mendeklarasikan variabel integer 'i' untuk menyimpan angka
  int i;

  // Menampilkan pesan agar user memasukkan angka
  cout << "Masukkan angka!\n";
  // Membaca input angka dari user dan menyimpannya ke variabel 'i'
  cin >> i;

  // Mengecek apakah angka ganjil (sisa bagi dengan 2 tidak sama dengan 0)
  if(i % 2 != 0) cout << "Angka Ganjil";
  // Jika kondisi salah (berarti sisa bagi 0), maka angka genap
  else cout << "Angka Genap";
  cout << '\n';

  return 0;
}