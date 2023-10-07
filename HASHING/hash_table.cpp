#include<bits/stdc++.h>
using namespace std;
static int HT[100]; 

int hashfunc1(int x){
                return (x%10+1);
        }


bool occupied(int x){
    if(!HT[x]){
        return false;
    }
    else{
        return true;
    }
}

bool tablefull(){
    for(int i=0;i<100;i++){
        if(!occupied(HT[i])){
            return false;
        }
        
    }
    return true;
}
void deletion(int x){                                // ideally we mark it with X and then do...(change accordingly)...
    HT[hashfunc1(x)]=0;
}

void linear_probing(int k){                         // insertion!!!!

        if(tablefull()){
            cout<<"TABLE IS FULL, IMPROVE THE ARCHITECTURE!!!"<<endl;
        }
<<<<<<< HEAD

        
=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
        else{

            int ind=hashfunc1(k);
            while(occupied(ind)){
                ind=(ind+1)%100;
            }
            HT[ind]=k;
            return ;
        }
}

int main(){
        
        linear_probing(10);
        linear_probing(31);
        linear_probing(32);
        linear_probing(53);
        linear_probing(84);
        deletion(53);
        linear_probing(13);
        cout<<HT[4]<<endl;
       

return 0;
}