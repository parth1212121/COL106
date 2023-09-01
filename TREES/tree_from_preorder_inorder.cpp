#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
   Node(int val){
    data=val;
    left=NULL;
    right=NULL;
   } 
};
int search(int inorder[],int start,int end,int current){
    for(int i=start;i<=end;i++){
        if(inorder[i]==current){
            return i;
        }
    }
    return -1;                           // Will only reach if the inputs are invalid.......
}

Node* buildTree(int preorder[],int inorder[],int start,int end){


    static int idx=0;

    if(start>end){
        return NULL;
    }

    int curr=preorder[idx];
    idx++;

    Node* node=new Node(curr);
    if(start==end){
        return node;
    }

    int pos=search(inorder,start,end,curr);

    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);

   return node;
}


int main(){

    int preorder[]={-1};
    int inorder[]={-1};
    Node* root=buildTree(preorder,inorder,0,0);
    cout<<root->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->data<<endl;
    return 0;
}