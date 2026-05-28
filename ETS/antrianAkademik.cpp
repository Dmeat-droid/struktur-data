#include <bits/stdc++.h>
#include <string>
#define MAX 9

using namespace std;


class Antrian{
private:
    string ARR[MAX];
    int front, rear;
    //int totalAntrian = rear - front;
public:
    Antrian(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return (front == -1);
    }

    bool isFull(){
        return (rear == MAX -1);
    }

    void enqueue (string nama) {
        if (isFull()){
            cout << "Antrian Penuh!\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        ARR[++rear] = nama;
        cout << "Mahasiswa " << nama << " masuk antrian\n";
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Antrian Kosong!\n";
            return;
        }

         cout << "Mahasiswa "<< ARR[front] << " dipanggil\n";

         if(front == rear) {
             front = rear = -1;
         }else {
            front++;
         }
    }

    void dispAntrian(){
        if(isEmpty()) {
            cout << "Antrian Kosong!\n";
            return;
        }
        cout << "Isi antrian:\n";
        for(int i = front; i <= rear; i++){
            cout << ARR[i] << " ";
        }
        cout << endl;
    }

    void getFront(){
        cout << "Mahasiswa "<< ARR[front] << " sedang dilayani\n";
    }

    void getRear(){
        cout << "Mahasiswa "<< ARR[rear] << " ada di urutan terakhir\n";
    }
};

int main(){
    Antrian q;
    string cmd, nama;
    
    while (1){
        cin >> cmd;
        if (cmd == "Enqueue"){
            cin >> nama;
            q.enqueue(nama);
        }else if(cmd == "Dequeue"){
            q.dequeue();
        }else if(cmd == "Front"){
            q.getFront();
        }else if (cmd == "Rear") {
            q.getRear();
        }else if (cmd == "Display"){
            q.dispAntrian();
        }else if (cmd == "Exit"){
            break;
        }else {               
            cout << "command tidak dikenal\n";
        }
    }
    return 0;
}
