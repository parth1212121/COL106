#include<bits/stdc++.h>
using namespace std;
class Employee{
        protected:
            int password;
        public:
            int id;
            void work(){
                cout<<"I am Employee <"<<id<<" and I am working";
            }
            Employee(int iden){
                id=iden;
           }
            Employee(){    // default constructor...

           }      
           void login(int pass){
                if(pass==password){
                    cout<<"Login succesful!!"<<endl;
                }
                else{
                    cout<<"Login unsuccessful"<<endl;
                }
            }           
};
class Developer : public Employee{
    public:
        Developer(int iden){
            iden=id;
      }
};
class Manager : public Employee{
        public:
        Manager(int iden){
            id=iden;
       }
        int manager_id;
        void work(){
            cout<<"I am Manager "<<manager_id<<"and I am working"; 
        }
        void change_password(int new_password){
            password=new_password;
        }
};

int main(){















return 0;
}