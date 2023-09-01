#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode{
    private:
        int data;
        BinaryTreeNode* left,*right,*parent;
    public:
        BinaryTreeNode(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
         void add_left(BinaryTreeNode* n){
            left=n;
                }
        void add_right(BinaryTreeNode* n){
            right=n;
                }
        void add_parent(BinaryTreeNode* n){
            parent=n;
                }

        int height(){
            if(this==NULL){                         // this --> pointer to the instantiated object.....
                return 0;                          // according to the classroom discusion.
            }
            return  (max(left->height(),right->height())+1);
        }
        int dia(){
            if(this==NULL){
                return 0;
            }
            return max((left->height()+right->height()+1),max(left->dia(),right->dia()));
        }
        int sumt(){
            if(this==NULL){
                return 0;
            }
            return (left->sumt()+right->sumt()+data);
        }
        int nodes(){
            if(this==NULL){
                return 0;
            }
            return (left->nodes()+right->nodes()+1);
        }
};
int main(){
BinaryTreeNode* root =new BinaryTreeNode(4);
BinaryTreeNode* n =new BinaryTreeNode(6);
root->add_left(n);
root->add_right(new BinaryTreeNode(9));
n->add_left(new BinaryTreeNode(5));
n->add_right(new BinaryTreeNode(11));
 cout<<root->nodes()<<endl;
 cout<<root->height()<<endl;
 cout<<root->sumt()<<endl;
 cout<<root->dia()<<endl;
return 0;
}