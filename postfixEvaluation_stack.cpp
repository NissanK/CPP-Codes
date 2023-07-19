#include <iostream>
#include<string>
#include<math.h>
#include<stack>

using namespace std;

int postfixEvaluation(string s){

    stack<int> st;
    for (int i = 0; i<s.size(); i++){
        
        if (s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op2+op1);
                break;
            case '-':
                st.push(op2-op1);
                break;
            case '/':
                st.push(op2/op1);
                break;
            case '*':
                st.push(op2*op1);
                break;
            case '^':
                st.push(pow(op2,op1));
                break;
            }
            //conversely u can switch op1 and op2 it would do the same trick
        }
    }
    return st.top();
}

int main(){
    string s = "46+2/5*7+";
    cout<<postfixEvaluation(s);
    return 0;
}
