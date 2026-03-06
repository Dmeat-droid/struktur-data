// Mengimpor library untuk input dan output
#include <iostream>

using namespace std;

// Fungsi untuk menentukan apakah karakter adalah vokal atau konsonan
void vowelOrConsonant(char x) {
  // Mengecek apakah karakter x adalah salah satu huruf vokal (huruf kecil atau besar)
  if (x == 'a' || x == 'i' || x == 'u'|| x == 'e' || x == 'o' || x == 'A'|| x == 'I'|| x == 'U'|| x == 'E' || x == 'O')
    cout << "Vowel" << endl;
  else 
    cout << "Consonant" << endl; 
}

int main() {
  // Memanggil fungsi dengan input 'a'
  vowelOrConsonant('a');
  // Memanggil fungsi dengan input 'H'
  vowelOrConsonant('H');

  return 0;
}
