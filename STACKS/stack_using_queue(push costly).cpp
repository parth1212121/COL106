#include<iostream>
#include<queue>
using namespace std;
class Stack{                          /// PUSH COSTLY ->METHOD(1)
<<<<<<< HEAD

    int N;
    queue<int>q1;
    queue<int>q2;

=======
    int N;
    queue<int>q1;
    queue<int>q2;
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
    public:
        Stack(){
            N=0;
       }
<<<<<<< HEAD
       
=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
       void push(int x){            // O(n)
       q2.push(x);
        N++;
        while(!q1.empty()){
           q2.push(q1.front());
            q1.pop();
        }
        queue<int>temp;
        q1=q2;
        q2=temp;
        }
        void pop(){                 // O(1)
        if(N==0){
            cout<<"Stack underfow"<<endl;
            return;
        }                         
        N--;
        q1.pop();
        }
        int top(){
            if(N==0){
                
                return -1;
            }
            return q1.front();
        }
        int size(){
            return N;
        }
};
int main(){
    Stack st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
return 0;
}