#include <iostream>

using namespace std;

#define MAX 5

class Queue{
private:
  string arr[MAX];
  int front, rear;

public:
  // Inisialisasi queue: front dan rear diatur ke -1 menandakan queue kosong
  Queue(){
    front = -1;
    rear = -1;
  }

  // Mengecek apakah queue kosong
  bool isEmpty(){
    return (front == -1);
  }

  // Mengecek apakah queue sudah penuh berdasarkan kapasitas MAX
  bool isFull(){
    return (rear == MAX - 1);
  }

  // Menambahkan elemen ke belakang (rear) queue
  void enqueue(string str){
    if(isFull()){
      cout << "Queue Overflow!\n";
      return;
    }
    if(isEmpty()){
      front = 0;
    }
    rear++;
    arr[rear] = str;
  }

  // Menghapus elemen dari depan (front) queue (Prinsip FIFO: First In First Out)
  void dequeue(){
    if(isEmpty()){
      cout << "Queue Underflow!\n";
      return;
    }
    
    // Jika hanya ada satu elemen, reset front dan rear ke -1
    if(front == rear){
      front = rear = -1;
    }else{
      front++;
    } 
  }

  // Menampilkan seluruh isi queue dari front ke rear
  void display(){
    if(isEmpty()){
      cout << "Queue Kosong!\n";
      return;
    }
    for(int i = front; i <= rear; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  // Mengambil nilai elemen yang berada di posisi paling depan
  string getFront(){
    if(isEmpty()){
      ///// cout << "Queue Kosong!\n";
      return "Queue Kosong!";
    }else{
      return arr[front];
    } 
  }
};

int main(){
  Queue q;
  
  for(int i = 0; i < MAX; i++){
    string str;
    cin >> str;
    q.enqueue(str);
  }

  cout << "\nDaftar Tugas: \n";

  for(int i = 0; i < MAX; i++){
    cout << i+1 << ". " << q.getFront() << '\n';
    q.dequeue();
  }

  return 0;
}