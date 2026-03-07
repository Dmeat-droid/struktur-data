// Mengimpor header file untuk operasi input dan output
#include <iostream>

// Menggunakan namespace standar agar tidak perlu menulis std:: berulang kali
using namespace std;

// Fungsi utama program, titik awal eksekusi
int main() {
  // Menampilkan teks "Hello World" ke layar (standard output)
  cout << "Hello World" << '\n';

  // Menampilkan teks menggunakan fungsi puts (gaya C), otomatis menambah baris baru di akhir
  puts("Hello world dengan puts");

  // Mengembalikan nilai 0 menandakan program selesai dengan sukses
  return 0;
}