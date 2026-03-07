// Mengimpor header file untuk operasi input (cin) dan output (cout)
#include <iostream>
// Menggunakan namespace standar agar tidak perlu menulis std::cin atau std::cout
using namespace std;

// Fungsi utama, titik awal eksekusi program
int main() {
  // Mendeklarasikan sebuah variabel integer bernama 'i' untuk menyimpan input dari user
  int i;

  // Membaca input integer dari keyboard (standard input) dan menyimpannya ke dalam variabel 'i'
  cin >> i;
  // Menampilkan nilai dari variabel 'i' ke layar (standard output), diikuti dengan karakter baris baru
  cout << i << '\n'; 

  // Mengembalikan nilai 0, menandakan program selesai dengan sukses
  return 0;
}