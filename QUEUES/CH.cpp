#include<iostream>
using namespace std;




class Node {
    int data;
    Node *prev, *next;
    // Function to get a new node
    static Node* getnode(int data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};
  
// A structure to represent a deque
class Deque {
    Node* front;
    Node* rear;
    int Size;
  
public:
    Deque()
    {
        cout<<"hi";
        front = rear = NULL;
        Size = 0;
    }};
    int main(){
        Deque d;
        return 0;






    }