#include<iostream>
using namespace std;      // Stack implementation using arrays...
#define n 10
class stack{
<<<<<<< HEAD

    int *arr;
    int top;

=======
    int *arr;
    int top;


>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
    public:
        stack(){
            arr= new int[n];
            top=-1;
        }
        void push(int x){
            if(top==(n-1)){
                cout<<"Stack overflow"<<endl;
                return;
            }
            top++;
            arr[top]=x;
        }
        void pop(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            top--;
        }
        int  Top(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return arr[top];
        }
        bool empty(){
                return (top==-1);
        }

};
int main(){

    stack st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}







