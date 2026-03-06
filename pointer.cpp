#include <bits/stdc++.h>
using namespace std;

int main() {
  int var = 10;

  int* ptr = &var;

  cout << "Nilai x: " << var << endl;
  cout << "Alamat x: " << &var << endl;
  cout << "Nilai di ptr: " << ptr << endl;
  cout << "Nilai yang ditunjuk ptr: " << *ptr << endl;
}