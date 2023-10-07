#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int>s1;
    stack<int>s2;
    public:
    void push(int x){      // O(1)
        s1.push(x);
    }
    int pop(){                                  //O(n)
        if(s1.empty() && s2.empty()){
            cout<<"ERROR"<<endl;
            return -1;
        }
        if(s2.empty()){
        while(!s1.empty()){
            int topele=s1.top();
            s1.pop();
            s2.push(topele);
        }}
        int ele=s2.top();
        s2.pop();
        return ele;       
    }
    bool empty(){
        if(s1.empty() && s2.empty()){            
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