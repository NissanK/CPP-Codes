#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

void permutations(string s, string ans){
    if (s.size()==0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i = 0;i<s.size();i++){
        
        string ros = s.substr(0,i) + s.substr(i+1);
        permutations(ros,ans+s[i]);
    }
}

int main(){
    string s;
    string ans = "";
    cin>>s;
    permutations(s,ans);
}
