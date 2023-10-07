#include<iostream>
#include<stack>
using namespace std;
<<<<<<< HEAD

=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
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
<<<<<<< HEAD

=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
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