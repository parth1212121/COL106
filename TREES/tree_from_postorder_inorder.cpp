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


void inorderprint(Node* root){
    if(root==NULL){
        return ;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

Node* buildTree(int postorder[],int inorder[],int start,int end){


    
    static int idx=4;                                                           // elegant.


    if(start>end){
        return NULL;
    }

    int curr=postorder[idx];
    idx--;

    Node* node=new Node(curr);
    if(start==end){
        return node;
    }

    int pos=search(inorder,start,end,curr);
    node->right=buildTree(postorder,inorder,pos+1,end);
    node->left=buildTree(postorder,inorder,start,pos-1);

}


int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    Node* root=buildTree(postorder,inorder,0,4);
   
    inorderprint(root);
    return 0;
}