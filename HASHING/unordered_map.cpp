#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
   map<int,int>mp;
    for(int i=0;i<n;i++){                                      // Red black Trees
        mp[i]=i+9;
    }
    
    map<int,int>:: iterator it;
    for( it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"---- difference-----"<<endl;
    unordered_map<int,int>mp2;
    for(int i=0;i<n;i++){
        mp2[i]=i+9;
    }                                                         // Hash Tables
    
    unordered_map<int,int>:: iterator it2;
    for( it2=mp2.begin();;it2++){
        cout<<it2->first<<" "<<it2->second<<endl;
    }
return 0;
}