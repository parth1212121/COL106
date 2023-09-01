#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int partition(int A[],int left,int right){  

       
    // partition A[left,...,right-1] using pivot.
    // Return i such that A[i] is pivot.
    // for all j<i A[j]<=A[i].
    // for all j>i A[j]>=A[i].

    int i=left;                                // IN palce partitining .....  // NO memeory wastage...
    int j=right-1;   
    int pivot,pi;
    pi=left+((rand())%(right-left));                   // Randomized..... O(nlogn)
    pivot=A[pi];
    swap(A[pi],A[right]);
    while(i<j){
        while(A[i]<pivot && i<right){
            i++;
        }
        while(A[j]>pivot && j>=0){
            j--;
        }
        if(i<j){
            swap(A[i],A[j]);;
        }
    }
    swap(A[i],A[right]);
    return i;
}

void  Quicksort(int A[],int n){                     // ITERATIVE!!!!!

       int start=0;
       int end=n-1;

       stack<pair<int,int>>st;
       st.push(make_pair(start,end));
       while(!st.empty()){

        start=st.top().first;                           // Elegeant.......
        end=st.top().second;
        st.pop();

        int p=partition(A,start,end);

        if(start<(p-1)){
            st.push(make_pair(start,p-1));
        }
        if(end>(p+1)){
            st.push(make_pair(p+1,end));
        }
       }
}


int main(){

    int a[]={8,4,7,1};

    Quicksort(a,4);    
   
    for(int i=0;i<4;i++){
        cout<<a[i]<<" ";
    }cout<<endl;

    return 0;
}