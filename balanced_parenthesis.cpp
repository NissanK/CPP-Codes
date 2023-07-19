#include <bits/stdc++.h>
using namespace std;

bool balanced_parenthesis(string s){
    stack<char> balance;
    for (int i = 0; i < s.size(); i++){
        switch (s[i]){
        case '(':
            balance.push(s[i]);
            break;
        case '[':
            balance.push(s[i]);
            break;
        case '{':
            balance.push(s[i]);
            break;
        case ')':
            if (!balance.empty() && balance.top()=='('){
                balance.pop();               
            }
            else return false;
            break;
        case ']':
            if (!balance.empty() && balance.top()=='['){
                balance.pop();               
            }
            else return false;
            break;
        case '}':
            if (!balance.empty() && balance.top()=='{'){
                balance.pop();               
            }
            else return false;
            break;
        }
    }
    if(balance.empty()){
        return true;
    }
    return false;
}

int main(){
    cout<<"Enter the string: ";
    string s;
    cin>>s;
    if(balanced_parenthesis(s)){
        cout<<"The string is balanced"<<endl;
    }
    else cout<<"The string is not balanced"<<endl;
}

// "([{}])"