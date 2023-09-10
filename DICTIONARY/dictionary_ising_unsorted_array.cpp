#include<bits/stdc++.h>
using namespace std;
class Element{
public:
    int key;
    string val;

};
class unsorted_array{

    private:
        Element* e;
        int capacity,count;

    public:
        unsorted_array(int size){
            capacity=size;
            count=0;
            e=new Element[size];
        }

        ~unsorted_array(){
            capacity=0;
            count=0;
            delete e;
        }

        void insert(Element* ein){                         // O(1)
            if(count==capacity){
                cout<<"Ditionary full!!!"<<endl;
            }
            else{
                    e[count++]=*ein;
            }
        }

        Element* find(int key){                        // O(n)
            int i=0;
            for(int i=0;i<count;i++){
                if(e[i].key==key){
                    return &e[i];
                }
            }            
                cout<<"Sorry not present!!!"<<endl;
      }
        

        void remove(int key){                  // O(n)
            int i=0;
            for(int i=0;i<count;i++){
                if(e[i].key==key){
                  
                    for(int j=i+1;j<count;j++){
                        e[j-1]=e[j];             // These are pointers....
                    }
              }
            }
            count--;
        }
};



int main(){

    Element e1;
    e1.key=1;
    e1.val="hi";

    Element e2;
    e2.key=2;
    e2.val="bi";


    unsorted_array Dic(10);
    Dic.insert(&e1);
    Dic.insert(&e2);

    cout<<(*(Dic.find(2))).val<<endl;

return 0;
}