#include<iostream>
#include<stack>
using namespace std;
<<<<<<< HEAD
class queue{                                // Using 1 stack......          [Recursion.....]
=======
class queue{
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
    stack<int>s1;
     public:
    void push(int x){      // O(1)
        s1.push(x);
    }
<<<<<<< HEAD

=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
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
<<<<<<< HEAD

=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
    bool empty(){
        if(s1.empty()){            
            return true;
        }
        return false;
    }
};
<<<<<<< HEAD


=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
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