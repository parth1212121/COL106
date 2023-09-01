#include<bits/stdc++.h>
using namespace std;

class Element{ 
    public:
        int key;
        string val;
        Element* prev;
        Element* next;
        Element(int ke,string va){
        key=ke;
        val=va;
        prev=NULL;
        next=NULL;
    }
};
class DLL_Dic{                                                        // Using doubly linked list.......
    public:
    Element *head=new Element(0,"");   // sentinal_head
    Element *tail=new Element(0,"");   // sentinal_tail
    DLL_Dic(){
         head->next=tail;
         tail->prev=head;
    }
    
    void insert(Element* n){             // O(1)a
       
         tail->prev->next=n;
         n->prev=tail->prev;
         n->next=tail;
         tail->prev=n;
     }  

     Element* find(int key){                     // O(n)
        Element* tmp=head;
        while(tmp!=tail){
             
        if(tmp->key==key){           
            return tmp;
        }
        tmp=tmp->next;
        }
        cout<<"No element found!!!"<<endl;
        return 0;
     }
    
     void remove(int key){  
        Element* n=find(key);                                // O(n)
        Element* todelete=n;
        n->prev->next=n->next;
        n->next->prev=n->prev;
        delete todelete;
     }

   ~DLL_Dic(){
        delete head;
        delete tail;
   }
};
int main(){
    DLL_Dic Dic;    
    Element e1(1,"HI");
    Element e2(2,"bi");
    Element e3(3,"Earth");
    Element e4(4,"Neptune");
    Dic.insert(&e1);      
    cout<<(*Dic.find(1)).val<<endl; 
     Dic.insert(&e2);   
     cout<<(*Dic.find(2)).val<<endl; 
     Dic.insert(&e3);   
     cout<<(*Dic.find(3)).val<<endl; 
     Dic.insert(&e4);
     cout<<(*Dic.find(4)).val<<endl;   
     Dic.remove(3); 
     cout<<(*Dic.find(4)).val<<endl;      
    return 0;   
}


