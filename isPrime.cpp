#include <bits/stdc++.h>

using namespace std;

// Fungsi untuk mengecek apakah bilangan n adalah prima
bool isPrime(int n) {
  // Bilangan kurang dari atau sama dengan 1 bukan prima
  if(n <= 1) return false;
  // Loop dari 2 hingga n-1 untuk mencari pembagi
  for(int i = 2; i < n; i++) {
    // Jika n habis dibagi i, maka bukan prima
    if(n % i == 0) return false;
  }
  return true;
}

void findPrimes(int l, int r) {
  // Flag untuk menandai jika ada bilangan prima ditemukan
  bool found = false;
  // Loop untuk mengecek setiap angka dalam rentang
  for(int i = 1; i <= r; i++) {
    // Mengecek apakah angka saat ini adalah prima
    if (isPrime(i)) {
      printf("%d ", i);
      found = true;
    }
  }

  if(!found){
    printf("No prime numbers found in given range.");
  }
}

int main(){
  int l = 10, r = 30;

  findPrimes(l, r);
  
  return 0;
}