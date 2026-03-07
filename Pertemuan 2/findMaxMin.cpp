// Mengimpor semua library standar C++
#include <bits/stdc++.h>

using namespace std;

// Fungsi untuk mendapatkan nilai minimum dari array
int getMin(int arr[], int n) {
  int res = arr[0];
  // Iterasi dari elemen kedua hingga terakhir
  for (int i = 1; i < n; i++)
    // Membandingkan dan menyimpan nilai yang lebih kecil
    res = min(res, arr[i]);
  return res;
}

// Fungsi untuk mendapatkan nilai maksimum dari array
int getMax(int arr[], int n) {
  int res = arr[0];
  // Iterasi dari elemen kedua hingga terakhir
  for(int i = 1; i < n; i++)
    // Membandingkan dan menyimpan nilai yang lebih besar
    res = max(res, arr[i]);
  return res;
}

int main () {
  int arr[] = {12, 1234, 45, 45, 9};
  // Menghitung jumlah elemen dalam array
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Minimum element of array:" << getMin(arr, n) << " ";
  cout << "Maximum element of array:" << getMax(arr, n) << " ";
  return 0;
}