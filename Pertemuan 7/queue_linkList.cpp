#include <iostream>
using namespace std;

// Struktur node untuk merepresentasikan setiap elemen dalam antrean (queue) menggunakan linked list
struct Node {
  string namaTugas; // Menyimpan data, dalam hal ini nama tugas
  Node *next;       // Pointer yang menunjuk ke node berikutnya dalam antrean
};

class Queue{
private:
  Node *front, *rear; // Pointer front menunjuk ke elemen paling depan, rear menunjuk ke elemen paling belakang

public:
  // Constructor: Inisialisasi queue dalam keadaan kosong (front dan rear bernilai NULL)
  Queue(){
    front = rear  = NULL;
  }

  // Fungsi untuk mengecek apakah queue kosong
  bool isEmpty(){
    return (front == NULL);
  }

  // Fungsi untuk menambahkan elemen baru ke bagian belakang (rear) antrean
  void enqueue(string x){
    // Membuat node baru secara dinamis
    Node *newNode = new Node();
    newNode->namaTugas = x;
    newNode->next = NULL;

    // Jika antrean kosong, node baru akan menjadi elemen front dan rear sekaligus
    if(rear == NULL){
      front = rear  = newNode;
    } else {
      // Jika tidak kosong, tambahkan node baru di belakang rear saat ini, 
      // lalu perbarui pointer rear agar menunjuk ke node yang baru ditambahkan
      rear->next = newNode;
      rear = newNode;
    }
  }

  // Fungsi untuk menghapus elemen dari bagian depan (front) antrean (Prinsip FIFO)
  void dequeue(){
    // Cek apakah antrean kosong sebelum melakukan penghapusan
    if(isEmpty()){
      cout << "Queue Kosong";
      return;
    }

    // Simpan elemen front saat ini di pointer sementara (temp)
    Node* temp = front;
    // Geser front ke elemen berikutnya
    front = front->next;

    // Jika setelah digeser front menjadi NULL (artinya queue menjadi kosong), 
    // maka rear juga harus diatur menjadi NULL
    if(front == NULL) rear = NULL;
    // Hapus node yang sebelumnya ada di depan untuk membebaskan memori
    delete temp;
  }

  // Fungsi untuk menampilkan seluruh isi antrean dari front ke rear
  void display(){
    if(isEmpty()){
      cout << "Queue kosong\n";
      return;
    }

    // Gunakan pointer sementara untuk melakukan iterasi dari front hingga akhir (NULL)
    Node* temp = front;
    cout << "Daftar Tugas :\n";
    int i = 1;
    while(temp   !=  NULL){
      cout << i << ". " << temp->namaTugas << "\n";
      // Pindah ke node berikutnya
      temp = temp->next;
      i++;
    }
    cout << endl;
  }
};

int main (){
  Queue q;

  for(int i = 0; i < 5;i++){
    string str;
    cin >> str;
    q.enqueue(str);
  }

  q.display();

  return 0;
}
