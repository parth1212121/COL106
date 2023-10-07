#include<bits/stdc++.h>
using namespace std;

class Element{
public:
    int key;
    string val;
    Element(){

    }
    Element(int ke,string va){
    key=ke;
    val=va;
        }
};

class sorted_array_dic{

    private:
        Element* e;
        int capacity,count;

    public:

        sorted_array_dic(int size){
            capacity=size;
            count=0;
            e=new Element[size];
        }

        ~sorted_array_dic(){
            capacity=0;
            count=0;
            delete e;
        }


        Element* find(int key){
            // use binary search to find the element sice all the elemnts are sorted...

            int lo=0;
            int hi=count-1;
            int mid;
             while(lo<=hi){
                 mid=(lo+(hi-lo)/2);
                if(e[mid].key==key){
                    return &e[mid];
                }
                else if(e[mid].key<key){
                    lo=mid+1;
               }
               else{
                hi=mid-1;
               }               
            } 
          
        cout<<"Element not found!!"<<endl;
        return 0;
      
        }

        Element* find_recursive(Element* e,int key,int lo,int hi){

            int mid;
            mid=(lo+hi)/2;
            if(lo>hi){
                cout<<"Element not found!!"<<endl;
                return 0;
            }
           
            else if(e[mid].key==key){
                return &e[mid];
                            }
            else if(e[mid].key>key){
                return find_recursive(e,key,mid+1,hi);
            }
            else{
                 return find_recursive(e,key,lo,mid-1);
            }   
        }

        
          void insert(Element* ein){                       // O(nlogn).

            int lo=0;
            int hi=count-1;
            int mid;
            int key=(*ein).key;
                                                         // No meaning of doing Binary Search here....
            while(lo<=hi){
                 mid=(lo+(hi-lo)/2);
                if(e[mid].key==key){
                    break;
                }
                else if(e[mid].key<key){
                    lo=mid+1;
               }
               else{
                hi=mid-1;
               }
               
            }                                           // append after the resulting e[mid]...

            for(int i=mid;i<count;i++){
                e[i+1]=e[i];
            }
            e[lo]=*ein;
            count++;
        }


        void remove(int key){
            Element* toremove=find(key);
            if(toremove==0){
                return ;
            }
            int i=toremove-e;
            for(int j=i+1;j<count;j++){
                e[j-1]=e[j];
            }
            count--;
        }

};
int main(){
   sorted_array_dic Dic(6);

    Element e1(1,"HI");
    Element e2(2,"bi");
    Element e3(3,"Earth");
    Element e4(4,"Neptune");
     Dic.insert(&e1);
     Dic.insert(&e2);
     Dic.insert(&e3);
     Dic.insert(&e4);
    cout<<(*Dic.find(3)).val<<endl;
    Dic.remove(2);
    cout<<(*Dic.find(1)).val<<endl;

    return 0;
}