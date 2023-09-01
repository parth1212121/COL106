#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
  
    void inorder(Node* root ,vector<int> &inorder_v){
       
    if(root==NULL){        
        return ;    
    }
    
    inorder(root->left,inorder_v);
    inorder_v.push_back(root->data);    
    inorder(root->right,inorder_v);
    
    }



    void preorder(Node* root ,vector<int> &preorder_v){
        
    if(root==NULL){        
        return ;       
    }

    preorder_v.push_back(root->data);  
    preorder(root->left,preorder_v);     
    preorder(root->right,preorder_v);
    
    }
    
    
     Node* find(int key,Node* root){ 
            if(root==NULL){
                return NULL;
            }                                

        while((root!=NULL) && (key!=root->data)){
        if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
        }

        return root;
        }
        
        
    
    Node *lca(Node *root, int v1,int v2) {
        
        vector<int>ino;
        inorder(root,ino);
        vector<int>pre;
        preorder(root,pre);
        // for(int i=0;i<ino.size();i++){
        //     cout<<ino[i]<<" ";
        // }cout<<endl;
        // for(int i=0;i<pre.size();i++){
        //     cout<<pre[i]<<" ";
        // }cout<<endl;

        
        map<int,bool>mp;

        bool see=false;

        for(int i=0;i<ino.size();i++){
           
            if(ino[i]==v1 || ino[i]==v2){
                see=true;
                mp[ino[i]]=true;               
            }
            else if((ino[i]==v1 || ino[i]==v2) && see){
                see=false;   
                mp[ino[i]]=true;
            }
            else if(see){
                cout<<ino[i]<<" ";
                mp[ino[i]]=true;
            }
                                   
        }

        

        int ans=0;
        for(int i=0;i<pre.size();i--){
            if(mp[pre[i]]){
                ans=pre[i];
                break;
            }
        }
        Node* res= find(ans,root);
        return res;
          }

int main() {

    Node* root= new Node(10);             //                                 1
    root->left=new Node(7);              //                                / \*
    root->right=new Node(13);              //                              2   3
    root->left->left=new Node(3); 
    root->left->left->left=new Node(1); 
    root->left->left->right=new Node(4); 
     root->left->right=new Node(9);      //                             4  5  6 7
    root->right->left=new Node(11);
    root->right->right=new Node(15);
    root->right->right->left=new Node(14);
    root->right->right->right=new Node(18);
    root->right->right->right->left=new Node(17);
    root->right->right->right->right=new Node(20);


    cout<<lca(root,1,9)->data<<endl;










    return 0;
}
