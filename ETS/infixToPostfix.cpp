#include<bits/stdc++.h>
#include <cctype>

using namespace std;

int getRank(char op){
    if(op == '^') return  3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else if (op == '=') return 0;
    else return -1;
}

int main(int argc, char *argv[]){
    string infix = argv[1];
    stack<char> st;
    // cout << infix << endl;
    string postfix = "";

    for(char c: infix){
        // cout << c << endl;
        if(isalnum(c)){
        //    cout << c << endl;
            postfix+=c;
        //   cout << postfix << endl;
        }else if(c == '('){
            st.push(c);
        }else if (c == ')'){
            while(!st.empty() && st.top() != '('){
                postfix+=st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.pop();
            }
        }else{
            int rank = getRank(c);
            //cout << "getRannk" << c << endl;
            while(!st.empty() && getRank(st.top()) >= getRank(c)){
                postfix+=st.top();
                // cout << postfix << endl;
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << postfix;

    return 0;
}
