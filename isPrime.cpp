#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
  if(n <= 1) return false;
  for(int i = 2; i < n; i++) {
    if(n % i == 0) return false;
  }
  return true;
}

void findPrimes(int l, int r) {
  // Flag to check any prime numbers found
  bool found = false;
  for(int i = 1; i <= r; i++) {
    // Checking if its prime
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