#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to decide the precedence
int precedence(char op) {
  if(op == '^') return 3;
  else if(op == '*' || op == '/') return 2;
  else if(op == '+' || op == '-') return 1;
  else return 0;
}

// Function to chec is it operator
bool isOperator(char op){
  return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

// Main function, converts infix to postfix
string infixToPostfix(string infix){
  stack<char> st;
  string postfix = "";

  for(int i = 0; i < infix.length(); i++){
    char c = infix[i];

    if(isalnum(c)) postfix += c;
    else if(c == '(') st.push(c);
    else if(c == ')') {
      while(!st.empty() && st.top() != '('){
        postfix += st.top();
        st.pop();
      }
      if(!st.empty())
        st.pop(); // delete '()'
    } 

    else if (isOperator(c)){
      while(!st.empty() && precedence(st.top()) >= precedence(c)){
        postfix += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Insert all of the remaining
  while(!st.empty()){
    postfix += st.top();
    st.pop();
  }

  return postfix;
}

// Main
int main(){
  string infix;

  cout << "Input the infix expression: ";
  cin >> infix;

  string postfix = infixToPostfix(infix);

  cout << "The Postfix form is: " << postfix << endl;
  
  return 0;
}