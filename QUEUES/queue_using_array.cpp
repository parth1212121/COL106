#include<iostream>
using namespace std;
                                            // The mod concept.......
class queue{
    int * arr;
    int front;
    int back;
    int n=20;
    
    public:                                                      // --->front -------queue--------- back<----- 
        queue(){
            arr= new int[n];
            front=-1;
            back=-1;
        }
        void push(int x){
            if(back==(n-1)){
                cout<<"Queue overflow"<<endl;
                return ;
            }
            if(front==-1){
                front++;
            }
            back++;
<<<<<<< HEAD
            arr[back]=x;           
      }

      void pop(){
=======
            arr[back]=x;
            
      }
      void pop(){

>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
        if(front==-1 || front>back ){ 
            cout<<"Empty"<<endl;
            return;
        }
        front++;
      }
<<<<<<< HEAD
      
=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
      int peek(){
        if(front==-1 || front>back ){            
            return -1;
        }
        return arr[front];
      }
      bool isempty(){
        if(front==-1 || front>back ){            
            return true;
        }
        return false;

      }
};
int main(){

    queue q;
    q.push(4);
    q.push(8);
    q.push(9);
    cout<<q.peek()<<endl;
    q.pop();
    q.push(6);
    cout<<q.peek()<<endl;

return 0;
}