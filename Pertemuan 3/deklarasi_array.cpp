#include <bits/stdc++.h>

using namespace std;

int main(){
    int myarray[] = {2, 4, 6, 8};
    for (int i = 0; i < 4; i++){
        cout << myarray[i] << endl;
        cout << "id: " << &myarray[i] << endl;
    }
    return 0;
}
