#include<bits/stdc++.h>
using namespace std;

class BinaryExpressionTree{                                     // Binary Tree to expression.........

    
    char op;
    int data;

    BinaryExpressionTree* left;
    BinaryExpressionTree* right;

    public:

        BinaryExpressionTree(char c){
            op=c;
            data=c-'0';
            left=NULL;                                  // Important to initialize......
            right=NULL;
        }

        void set_left(BinaryExpressionTree* n){
            left=n;
        }

        void set_right(BinaryExpressionTree* n){
            right=n;
        }

        double evaluate(){
            if(this==NULL){
                return 0;
            }
            else if((left==NULL) && (right==NULL)){          // leaf node...
                return data;
            }
            else if(op=='+'){
                return left->evaluate()+right->evaluate();
            }
            else if(op=='-'){
                return left->evaluate()-right->evaluate();
            }
            else if(op=='*'){           
                return left->evaluate()*right->evaluate();
            }
            else if(op=='/'){             
                return left->evaluate()/right->evaluate();
            }
        }



        void inorder(BinaryExpressionTree* root){

        if(root==NULL){                                  // Just manage out with brackets......
        return;
        }
        cout<<"(";
        inorder(root->left);
        cout<<root->op<<"";
        inorder(root->right);
        cout<<")";
        }

      
};

int main(){
    BinaryExpressionTree* root =new BinaryExpressionTree('*');
    BinaryExpressionTree* n=new BinaryExpressionTree('/');
    root->set_left(n);
    root->set_right(new BinaryExpressionTree('4'));
    BinaryExpressionTree* n2=new BinaryExpressionTree('+');
    n->set_left(n2);
     BinaryExpressionTree* n3=new BinaryExpressionTree('3');
    n->set_right(n3);
    n2->set_left(new BinaryExpressionTree('4'));
    n2->set_right(new BinaryExpressionTree('2'));
    root->inorder(root);    
    return 0;
}







































