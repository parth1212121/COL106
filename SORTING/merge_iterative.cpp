#include<iostream>
using namespace std;

void merge(int *A,int left,int mid,int right,int* T){

    // merges the sorted array A[left,....,mid-1] and A[mid,....,right-1].into the auxillary array T.
    
    int i=left;
    int j=mid;
    int d=left;
    while(i<mid && j<right){                     // O(n).
        if(A[i] >A[j]){
            T[d]=A[j];
            d++;
            j++;
        }
        else{
            T[d]=A[i];
            d++;
            i++;
        }
    }
    while(i<mid){
        T[d]=A[i];
        i++;
        d++;
    }
    while(j<right){
        T[d]=A[j];
        j++;
        d++;
    }
    // for(int i=left;i<right;i++){                              // Just one auxillary array "T"....
    //     A[i]=T[i];
    // }
}

void mergesort_iter(int* A,int size,int *T){  

    int cap;  // no of elements to be sorted.
    int left;
    int x=1;
    for(cap=1;cap<=size-1;cap=cap*2)
    {
       for(left=0;left<size-1;left+=2*cap){
        int mid=min(size,(left+cap));
        int right=min(size,(left+2*cap));
        if(x%2==1){                                      // Reduction in copying..[only in Iterative version]..
        merge(A,left,mid,right,T);}
        else{
            merge(T,left,mid,right,A);
        }
            }    
            x++;    
    } 
    if(x%2==0){
        for(int i=0;i<size;i++){
            A[i]=T[i];            
        }
    }
} 

int main(){
    int A[]={30,14,56,12,53,22,1000,6,2,892};    
    int T[]={30,14,56,12,53,22,1000,6,2,892};
   mergesort_iter(A,10,T);
 
    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }cout<<endl;

    return 0;
}





