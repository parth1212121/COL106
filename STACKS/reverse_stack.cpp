#include<iostream>
#include<stack>
using namespace std;
void insertAtbottom(stack<int> &st,int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        int topele=st.top();
        st.pop();
        insertAtbottom(st,ele);
        st.push(topele);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtbottom(st,ele);
}

int main(){

    stack<int>st;
    st.push(4);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);

    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
return 0;
}