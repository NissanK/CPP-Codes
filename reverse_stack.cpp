#include<iostream>
#include<stack>

using namespace std;
void InsertAtBottom (stack<int> &st,int ele){

    if (st.empty()){
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    InsertAtBottom(st,ele);
    st.push(topele);
}

void reverse(stack<int> &st){

    if (st.empty()){
        return;
    }
    
    int ele = st.top();
    st.pop();
    reverse(st);
    InsertAtBottom(st,ele);
}

void stack_display(stack<int> &st){
    while (!st.empty()){
        int num = st.top();
        st.pop();
        cout<<num<<endl;
    }
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    reverse(st);
    stack_display(st);
}