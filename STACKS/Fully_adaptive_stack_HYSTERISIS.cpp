#include<iostream>
using namespace std;      // Stack implementation using arrays...
#define n 1
#define C 2
class stack{                             // Fully adaptive stack using Hysterisis.....
    int *arr;
    int top;
    int size;
    public:
        stack(){
            arr= new int[n];
            size=n;
            top=-1;
        }
        void push(int x){                     // Memory increment when needed...
            if(top==(size-1)){
                int *temp=new int[2*n];                          // Reallocate and copy...
                for(int i=0;i<size;i++){          
                    temp[i]=arr[i];
                }
                delete arr;
                arr=temp;
                size*=2;
            }
           top++;
            arr[top]=x;
        }
        void pop(){                                       // Memory decrement when needed...
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            if(top<(size/C)){                      // Reallocate memory and copy....
                int* temp=new int[size/C];
                for(int i=0;i<top;i++){
                    temp[i]=arr[i];
                }
                delete arr;
                arr=temp;
           }
            top--;
            size=size/C;
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
        int sizel(){
            return size;
        }

};
int main(){
    stack st;
    st.push(5);
    cout<<st.sizel()<<endl;
    st.push(4); 
    cout<<st.sizel()<<endl;
    st.push(3);
    cout<<st.sizel()<<endl;
    st.push(2);
    st.push(6);
    cout<<st.sizel()<<endl;
    st.pop();
    cout<<st.sizel()<<endl;
    st.pop();
    cout<<st.sizel()<<endl;
    st.pop();
    cout<<st.sizel()<<endl;
    return 0;
}







