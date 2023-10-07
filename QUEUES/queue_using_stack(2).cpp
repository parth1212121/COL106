#include<iostream>
#include<stack>
using namespace std;
class queue{                                // Using 1 stack......          [Recursion.....]
    stack<int>s1;
     public:
    void push(int x){      // O(1)
        s1.push(x);
    }

    int pop(){                                  //O(n)
        if(s1.empty()){
            cout<<"ERROR"<<endl;
            return -1;
}
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item=pop();
        s1.push(x);
        return item;
    }

    bool empty(){
        if(s1.empty()){            
            return true;
        }
        return false;
    }
};


int main(){
    queue q;
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    cout<<q.pop()<<endl;
    q.push(0);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}