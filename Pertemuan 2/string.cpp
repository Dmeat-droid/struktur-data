#include <iostream>      // untuk std::cout dan I/O lainnya

using namespace std;     // agar tidak perlu menulis std:: di mana-mana

int main() {
  // inisialisasi std::string dengan literal
  string str = "HelloWorld!";

  // cetak panjang string ke output standar
  cout << str.size() << endl;

  return 0;
}