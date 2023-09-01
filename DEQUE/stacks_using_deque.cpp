#include<iostream>
#include<deque>
using namespace std;

class Stack{

    int N;
    deque<int>d;
    public:
     Stack(){
        N=0;
     }
    void push(int x){
        d.push_front(x);
        N++;
    }
    void pop(){
        if(N==0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        d.pop_front();
        N--;
    }
    int top(){
        if(N==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return d.front();
    }
    int size(){
        return N;
    }
    bool empty(){
        return (N==0);
    }
};

int main(){
    Stack st;
    st.push(4);
    st.push(5);
    st.push(8);
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
return 0;

}