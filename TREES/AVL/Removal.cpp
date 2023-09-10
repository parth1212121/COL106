#include<iostream>
using namespace std;

class Node{

    public:

    int data;
    Node* left;
    Node* right;
    Node* parent;

   Node(int val){
    data=val;
    left=NULL;
    right=NULL;
   } 
};

int height(Node* n){
    
    if(n==NULL){
        return -1;
    }
 
    return (max(height(n->left),height(n->right))+1);
    

}

bool is_balanced(Node* n){
    if(n==NULL){
        return true;
    }
    else{

        if(abs(height(n->left)-height(n->right))<=1){
            return true;
        }
        return false;
    }
}
Node* find(int key,Node* root){                                 // O(log_2_n)

    // searches for the key in the BST rooted at root
    // Returns  the node pointer if found and null o.w

    // Assumes short circuit evaluation of boolean expressions

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

Node* find_min(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* find_max(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

Node* Successor(Node* u){                                                 // O(h) ... 
    if(u->right!=NULL){
        return find_min(u->right);
    }
    else{
        while((u->parent!=NULL && (u==u->parent->right))){
            u=u->parent;
        }
        return u->parent;
    }
}

void insert(Node* root,Node* v){                   
    
                                                  // Worst Case -->O(n).
                                                  // Average case--> O(log n)
    // Inserts node v into the BST.
    //Assumes that v->left and v->right are null
    // Assumes that v->key is not present in TREE.
    if(root==NULL){
        return ;
    }
    if(v->data<root->data){
        // Insert on the left side of the root.
        if(root->left==0){
            // We have found the right place to insert.
            root->left=v;
            v->parent=root;
        }
        else{
            insert(root->left,v);
        }
  }
  else{
     // Insert on the right side of the root.
        if(root->right==0){
            // We have found the right place to insert.
            root->right=v;
            v->parent=root;
        }
        else{
            insert(root->right,v);
        }
  }
}

void Remove_leaf(Node* &root,Node* n){
    if(n==root){
    n=NULL;
    return;
    }

    else{
        if(n->parent->left==n){          
            n->parent->left=NULL;
        }
        else if(n->parent->right==n){
            n->parent->right=NULL;                    
        }
    }
}

void Remove_leaf_balance(Node* &root,Node* n){

    if(n==NULL){
        n=NULL;
        return;
    }
    Node* tmp=n;

    while(is_balanced(tmp->parent)){
    
        tmp=tmp->parent;
        if(tmp==root){
           
            return;
        }
    }           // tmp->parent will be unbalnced....

    // Case_T1


    if(tmp->parent->data>tmp->data){   // leaf removed from the left sub_tree..

        Node* u=tmp->parent;
        Node* v=tmp->parent->right;
        Node* w=tmp->parent->right->left;
        Node* t1=tmp->parent->left;
        Node* t4=tmp->parent->right->right;

        // Case_1 [h(w)=h(T4)=(h-2)]

        if(height(w)==height(t4)){
                
              
                v->parent=u->parent;
                if(u!=root){
                if(u->parent->left==u){
                    u->parent->left=v;
                }
                else if(u->parent->right==u){
                    u->parent->right=v;
                }}
                if(u==root){
                    root=v;
                }
                u->parent=v;
                u->right=w;

                if(w!=NULL){
                w->parent=u;}

                v->left=u;

                delete tmp;
                // The entire tree is balanced now....
        }

        // Case_2 : [h(w)=h-3 && h(t4)=h-2]

        if(height(w)<height(t4)){
               
            v->parent=u->parent;
            if(u!=root){
            if(u->parent->left==u){
                u->parent->left=v;
            }
            else if(u->parent->right==u){
                u->parent->right=v;
            }}
            if(u==root){
                root=v;
            }
            u->parent=v;
            u->right=w;

            if(w!=NULL){
            w->parent=u;}

            v->left=u;
            delete tmp;

            Remove_leaf_balance(root,v);    // Further parent checking.....
       }
        
       // Case_3 : [h(w)=h-2 && h(t4)=h-3]

       if(height(w)>height(t4)){
       
        w->parent=u->parent;
        if(u!=root){
        if(u->parent->left==u){
            
            w->parent->left=w;
        }

        else if(u->parent->right==u){
            w->parent->right=w;
        }}
        if(u==root){
            root=w;
        }

        Node* t2=w->left;
        Node* t3=w->right;
      
        w->left=u;
        w->right=v;

        u->parent=w;
        v->parent=w;
    
        if(t2!=NULL){
        t2->parent=u;}

        if(t3!=NULL){
        t3->parent=v;}

        u->right=t2;
        v->left=t3;

        delete tmp;

        Remove_leaf_balance(root,w);        // check for the parents.....

       }

    }
    
    // Case_T2:

    if(tmp->parent->data<n->data){   // leaf removed from the right sub_tree..

        Node* u=tmp->parent;
        Node* v=tmp->parent->left;
        Node* w=tmp->parent->left->right;
        Node* t1=tmp->parent->right;
        Node* t4=tmp->parent->left->left;

        // Case_1 [h(w)=h(T4)=(h-2)]

        if(height(w)==height(t4)){
                
              
                v->parent=u->parent;
                if(u!=root){
                if(u->parent->left==u){
                    u->parent->left=v;
                }
                else if(u->parent->right==u){
                    u->parent->right=v;
                }}
                if(u==root){
                    root=v;
                }
                u->parent=v;
                u->left=w;

                if(w!=NULL){
                w->parent=u;}

                v->right=u;

                delete tmp;
                // The entire tree is balanced now....
        }

        // Case_2 : [h(w)=h-3 && h(t4)=h-2]

        if(height(w)<height(t4)){
               
            v->parent=u->parent;
            if(u!=root){
            if(u->parent->left==u){
                u->parent->left=v;
            }
            else if(u->parent->right==u){
                u->parent->right=v;
            }}
            if(u==root){
                    root=v;
                }
            u->parent=v;
            u->left=w;

            if(w!=NULL){
            w->parent=u;}

            v->right=u;
            delete tmp;

            Remove_leaf_balance(root,v);    // Further parent checking.....

       }
        
       // Case_3 : [h(w)=h-2 && h(t4)=h-3]

       if(height(w)>height(t4)){
       
        w->parent=u->parent;
        if(u!=root){
        if(u->parent->left==u){
            
            w->parent->left=w;
        }

        else if(u->parent->right==u){
            w->parent->right=w;
        }}
        if(u==root){
                    root=w;
        }
        Node* t2=w->right;
        Node* t3=w->left;
      
        w->right=u;
        w->left=v;

        u->parent=w;
        v->parent=w;
    
        if(t2!=NULL){
        t2->parent=u;}

        if(t3!=NULL){
        t3->parent=v;}

        u->left=t2;
        v->right=t3;

        delete tmp;

        Remove_leaf_balance(root,w);        // check for the parents.....

       }
    }

}


void Remove(Node* &root,Node* &n){


    if(n->left==NULL && n->right==NULL){     // No child.
        Remove_leaf(root,n);
        Remove_leaf_balance(root,n);
    }

    else if(n->left==NULL){                 // Single child.

        n->data=n->right->data;
        Remove(root,n->right);

    }

    else if(n->right==NULL){                 // Single child.

        n->data=n->left->data;
        Remove(root,n->left);

    }

    else{                                    // Dual child.

    Node* copy= Successor(n);
    n->data=copy->data;
    Remove(root,copy);

    }

}


int main(){  

    Node* root=new Node(15);
    Node* n10=new Node(10);
    Node* n2=new Node(2);
    Node* n12=new Node(12);
    Node* n11=new Node(11);
    Node* n14=new Node(14);
    Node* n24=new Node(24);
    Node* n20=new Node(20);
    
    Node* n29=new Node(29);
    
    insert(root,n10);
    insert(root,n2);
    insert(root,n12);
    
    insert(root,n11);
    insert(root,n24);
    
    insert(root,n20);
    insert(root,n29);


    Remove_leaf(root,n2);
 
    Remove_leaf_balance(root,n2);
                                                     // Whatever node was added just....
    std::cout<<root->data<<endl;
    // std::cout<<root->left->data<<endl;
    // std::cout<<root->right->data<<endl;    
    // std::cout<<root->left->right->data<<endl;
    // std::cout<<root->left->left->data<<endl;
    // std::cout<<root->right->left->data<<endl;
    // std::cout<<root->right->right->data<<endl;
    
    return 0;
}