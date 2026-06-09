#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SocialNetwork {
private:

    vector<string> users;
    vector<vector<int>> friendsList;

public:

    void addUser(string name) {
        users.push_back(name);
        friendsList.push_back({});
    }

    void addFriendship(int u, int v) {
        friendsList[u].push_back(v);
        friendsList[v].push_back(u);
    }

    void showNetwork() {

        cout << "\n=== Social Network ===\n";

        for(int i=0;i<users.size();i++) {

            cout << users[i] << " berteman dengan: ";

            for(int friendID : friendsList[i]) {
                cout << users[friendID] << " ";
            }

            cout << endl;
        }
    }
};

int main() {

    SocialNetwork sn;

    sn.addUser("Andi");
    sn.addUser("Budi");
    sn.addUser("Citra");
    sn.addUser("Dina");
    sn.addUser("Eko");

    sn.addFriendship(0,1);
    sn.addFriendship(0,2);
    sn.addFriendship(1,3);
    sn.addFriendship(2,4);

    sn.showNetwork();

    return 0;
}