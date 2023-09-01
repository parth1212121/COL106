#include<iostream>
using namespace std;      // Stack implementation using arrays...
#define n 1
class stack{
    int *arr;
    int top;
    public:
        stack(){
            arr= new int[n];
            top=-1;
        }
        void push(int x){
            if(top==(n-1)){
                int *temp=new int[2*n];          // Reallocate and copy...
                for(int i=0;i<n;i++){          
                    temp[i]=arr[i];
                }
                delete arr;
                arr=temp;
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
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(45);

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







