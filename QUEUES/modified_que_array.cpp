#include<iostream>
using namespace std;
                                            // The mod concept......     // For efficient memory utilization....
class queue{
    int * arr;
    int front;
    int back;
    int n=4;      // capacity of queue=(n-1)..
    
    public:                                                      // --->front -------queue--------- back<----- 
        queue(){
            arr= new int[n];                                    // Our queue can have a maximum of (n-1) lemnts in it.// This is done in order to distinguish between full and empty condition....
            front=0;
            back=0;           
        }
    void push(int x){
            if((back+1)%n==front){
            cout<<"Queue is full"<<endl;
        }  
        else{
            arr[(back)]=x;
            back=((back+1)%n);            
        }             
    }

    void pop(){
        if(back==front){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            front=((front+1)%n);
        }       
      }
    int peek(){
       if(front==back){
        cout<<"Empty"<<endl;
        return -1;
       }
       else{
        return arr[front];
       }
        
      }
    bool isempty(){
        return (front==back);
      }
};
int main(){                          // n=3;
    queue q;                   
    q.push(4);
    q.push(8);
    q.push(9);
    cout<<q.peek()<<endl;
    q.pop();
    q.push(6);                       // In a simpler array we would have expected an Queue overfolw error..... 
                                    // and 6 would not have got addede to the queue because of memory limitations ,, but here because of utilizing circular arrays we are able to store 6 .. and still permorming the function of queue...
    cout<<q.peek()<<endl; 
return 0;
}