#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Postfix evaluation function
int evaluatePostfix(string exp){
  stack<int> st;

  for(char c : exp){
    if(isdigit(c)) {
      st.push(c-'0');// convert char to int
    } else{
      int val2 = st.top(); st.pop();
      int val1 = st.top(); st.pop();

      switch(c){
        case '+': st.push(val1+val2); break;
        case '-': st.push(val1-val2); break;
        case '*': st.push(val1*val2); break;
        case '/': st.push(val1/val2); break;
      }
    }
  }

  return st.top();
}


int main() {
  string postfix;
  
  cout << "Insert postfix expression:  ";
  cin >> postfix;

  cout << "Evaluation result: " << evaluatePostfix(postfix) << endl;

  return 0;
}