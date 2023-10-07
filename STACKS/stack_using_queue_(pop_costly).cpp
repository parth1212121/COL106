#include<iostream>
#include<queue>
using namespace std;
class Stack{
        int N;
        queue<int>q1;
        queue<int>q2;
        public:
            Stack(){
                    N=0;
            }
            void push(int x){
                q1.push(x);
                    N++;
            }
            void pop(){
                if(q1.empty()){
                    cout<<"Stack underflow"<<endl;
                    return ;
                }
                while(q1.size()!=1){
                    q2.push(q1.front());
                    q1.pop();
                }
                N--;
                q1.pop();
                queue<int>temp;
                q1=q2;
                q2=temp;
            }
            int top(){
                if(q1.empty()){
                    return -1;
                }
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            int ans=q1.front();
            q2.push(q1.front());
            q1.pop();
            queue<int>temp;
            q1=q2;
            q2=temp;
            return ans;
            }
            int size(){
                if(N<=0){
                    return 0;
                }
                return N;
            }
};
int main(){

Stack st;
st.push(3);
st.push(4);
st.push(5);
st.push(6);
cout<<st.top()<<endl;
st.pop();
cout<<st.top()<<endl;
st.pop();
st.pop();
st.pop();
st.pop();
st.pop();
cout<<st.top()<<endl;
<<<<<<< HEAD
=======


>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
    return 0;
}
