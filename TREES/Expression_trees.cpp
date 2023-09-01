#include<bits/stdc++.h>
using namespace std;
class BinaryExpressionTree{
    double data;
    char op;
    BinaryExpressionTree* left;
    BinaryExpressionTree* right;
    public:
        BinaryExpressionTree(char c,int val){
            op=c;
            data=val;
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
               // cout<<op<<endl;
                return left->evaluate()*right->evaluate();
            }
            else if(op=='/'){             
                return left->evaluate()/right->evaluate();
            }
        }
};

int main(){
    BinaryExpressionTree* root =new BinaryExpressionTree('*',0);
    BinaryExpressionTree* n=new BinaryExpressionTree('/',0);
    root->set_left(n);
    root->set_right(new BinaryExpressionTree(' ',4));
    BinaryExpressionTree* n2=new BinaryExpressionTree('+',0);
    n->set_left(n2);
     BinaryExpressionTree* n3=new BinaryExpressionTree(' ',3);
    n->set_right(n3);
    n2->set_left(new BinaryExpressionTree(' ',4));
    n2->set_right(new BinaryExpressionTree(' ',2));
    cout<<root->evaluate()<<endl;
    return 0;
}







































