#include<iostream>
#include<deque>
using namespace std;

class Queue{

    deque<int>d;
    int N=0;
    
    public:
        Queue(){

        }
        void enqueu(int x){
            d.push_back(x);
            N++;
        }
        void deq(){
            if(!N){
                cout<<"Queue is empty"<<endl;
                return;
            }
            d.pop_front();
            N--;
        }
        int front(){
            if(!N){
                return -1;
            }
            return d.front();
        }
        int size(){
            return N;
        }
        bool empty(){
            return (N==0);
        }
};

int main(){
        Queue  q;
        q.enqueu(4);
        q.enqueu(5);
        q.enqueu(6);
        cout<<q.front()<<endl;
        q.deq();
        cout<<q.front()<<endl;
    return 0;
}