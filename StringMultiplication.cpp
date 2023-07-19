#include<bits/stdc++.h>

using namespace std;
//incomplete code
string stringMultiply(string num1 , string num2, int idx){
    string Multiplied(410,'0');
    for(int i = 0;i<idx;i++){
        Multiplied[410-i-1] = '0';
    }
    int len1 = num1.size();
    int carry = 0;
    int counter = idx;
    int n2 = num2[idx]-'0';
    for(int i = len1-1;i>=0;i--){
        int n1 = num1[i]-'0';
        int multiplied = n1*n2;
        if(carry){
            multiplied += carry;
            carry = 0;
        }
        int remainder = 0;
        if(multiplied>9){
            remainder = multiplied%10;
            carry = multiplied/10;
        }
        else{
            remainder = multiplied;
        }
        char x =(char)remainder + '0';
        Multiplied[410-counter-1] = x;
        counter++;
    }
    if(carry){
        Multiplied[410-counter-1] = char(carry) + '0';
    }
    return Multiplied;
}

string stringAddition(string Addition, string Multiplied){
    int carry = 0;
    int i = 0;
    for(i = 0;i<Multiplied.size();i++){
        int add = (char(Addition[410-i-1]) - '0') + (char(Multiplied[410-i-1]) - '0');
        cout<<add<<endl;
        int remainder = 0;
        if(add>9){
            remainder = add%10;
            carry = add/10;
        }
        else{
            remainder = add;
        }
        char x =(char)remainder + '0';
        Addition[410-i-1] = x;
    }
    if(carry){
        Addition[410-i-1] = char(carry) + '0';
    }
    return Addition;
}

string multiply(string num1, string num2) {
    int len2 = num2.size();
    string ans(410,'0');
    for(int i = len2-1;i>=len2-2;i--){
        string Multiplied = stringMultiply(num1,num2,i);
        ans = stringAddition(ans,Multiplied);
    }
    for(int i = 0;i<ans.size();){
        if(ans[i]=='0'){
            ans = ans.substr(1);
        }
    }
    return ans;
}

int main(){
    string s1 = "4567";
    string s2 = "4567";
    cout<<multiply(s1,s2)<<endl;
}