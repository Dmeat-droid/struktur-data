#include <bits/stdc++.h>

using namespace std;

#define MAX 5

class Stack{
private:
  int arr[MAX];
  int top;
public:
  // Constructor: Menginisialisasi nilai awal top dengan -1 yang menandakan stack masih kosong
  Stack(){
    top = -1; // stack kosong
  }

  // Fungsi push: Menambahkan elemen baru ke posisi paling atas (top) pada stack
  void push(int x){
    if(top == MAX-1){
      cout << "Stack Overflow!\n";
    } else {
      arr[++top] = x;
      cout << x << " ditambahkan ke stack\n";
    }
  }
  
  // Fungsi pop: Menghapus elemen yang berada di posisi paling atas (top) pada stack
  void pop(){
    if(top == -1){
      cout << "Stack Underflow\n";
    }else{
      cout << arr[top--] << " dihapus dari stack\n";
    }
  }

  // Fungsi peek: Menampilkan nilai dari elemen paling atas (top) tanpa menghapusnya dari stack
  void peek(){
    if(top == -1) {
      cout << "Stack kosong\n";
    }else{
      cout << "Elemen teratas: " << arr[top] << endl;
    }
  }
};

// Fungsi utama: Titik awal eksekusi program
int main(){
  Stack s;

  s.push(23);
  s.push(43);
  s.push(33);

  s.peek();

  s.pop();

  s.peek();

  return 0;
}