#include <iostream>

using namespace std;

void vowelOrConsonant(char x) {
  if (x == 'a' || x == 'i' || x == 'u'|| x == 'e' || x == 'o' || x == 'A'|| x == 'I'|| x == 'U'|| x == 'E' || x == 'O')
    cout << "Vowel" << endl;
  else 
    cout << "Consonant" << endl; 
}

int main() {
  vowelOrConsonant('a');
  vowelOrConsonant('H');

  return 0;
}

