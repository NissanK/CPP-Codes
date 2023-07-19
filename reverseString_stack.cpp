#include<iostream>
#include<stack>
#include<string>

using namespace std;

void reversestring (string s){

    stack<string> st;

    for (int i = 0; i < s.size(); i++){
        string word ="";
        while (i<s.size() && s[i]!=' '){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

int main(){
    string s = "Hey how are you doing?";
    cout<<s<<endl;
    reversestring(s);
}