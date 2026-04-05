#include <bits/stdc++.h>
using namespace std;

// Struktur node untuk merepresentasikan setiap elemen dalam linked list
struct Node
{
  int data;   // Menyimpan nilai dari elemen
  Node* next; // Pointer yang menunjuk ke node berikutnya di bawahnya
};

class Stack{
private:
  Node* top; // Pointer untuk melacak node paling atas pada stack

public:
  // Constructor: Menginisialisasi top dengan NULL yang menandakan stack masih kosong
  Stack(){
    top = NULL;
  }

  // Fungsi push: Menambahkan elemen baru ke posisi paling atas (top) pada stack
  void push(int x){
    // Membuat node baru di memori secara dinamis
    Node* newNode = new Node();
    newNode->data = x;   // Memasukkan nilai x ke dalam node baru
    newNode->next = top; // Menghubungkan node baru ke node yang sebelumnya ada di top
    top = newNode;       // Memperbarui top agar menunjuk ke node baru tersebut

    cout << x << " ditambahkan ke stack\n";
  }

  // Fungsi pop: Menghapus elemen yang berada di posisi paling atas (top) pada stack
  void pop(){
    // Cek apakah stack kosong (Underflow) sebelum melakukan penghapusan
    if(top == NULL){
      cout << "Stack underflow\n";
      return;
    }

    // Gunakan pointer sementara (temp) untuk menyimpan node teratas saat ini
    Node* temp = top;
    cout << temp->data << " dihapus dari stack\n";
    
    // Geser top ke node berikutnya di bawah node teratas saat ini
    top = top->next;
    
    // Hapus node teratas dari memori secara permanen untuk mencegah memory leak
    delete temp;
  }

  // Fungsi peek: Menampilkan nilai dari elemen paling atas tanpa menghapusnya
  void peek(){
    // Pastikan stack tidak kosong sebelum mencoba mengakses elemen teratas
    if(top == NULL){
      cout << "Stack kosong!\n";
    }else{
      cout << "Elemen teratas: " << top->data << endl;
    }
  }

  // Fungsi isEmpty: Mengecek apakah stack kosong atau tidak
  bool isEmpty(){
    // Mengembalikan true jika top bernilai NULL, dan false jika tidak
    return (top==NULL);
  }
};



int main(){
  Stack s;

  // Proses memasukkan 3 elemen ke dalam stack
  s.push(10);
  s.push(43);
  s.push(93); // Nilai 93 akan berada di posisi teratas (top)

  // Melihat elemen paling atas saat ini (harus 93)
  s.peek();
  
  // Menghapus elemen teratas (menghapus 93)
  s.pop();
  
  // Melihat elemen paling atas setelah penghapusan (sekarang 43)
  s.peek();

  return 0;
}