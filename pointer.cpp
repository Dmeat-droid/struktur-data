#include <bits/stdc++.h>
using namespace std;

int main() {
  // Variabel integer biasa
  int var = 10;

  // Variabel pointer yang menyimpan alamat memori dari var
  int* ptr = &var;

  // Menampilkan nilai var
  cout << "Nilai x: " << var << endl;
  // Menampilkan alamat memori var
  cout << "Alamat x: " << &var << endl;
  // Menampilkan nilai yang disimpan di ptr (alamat var)
  cout << "Nilai di ptr: " << ptr << endl;
  // Menampilkan nilai yang ditunjuk oleh ptr (dereference)
  cout << "Nilai yang ditunjuk ptr: " << *ptr << endl;
}