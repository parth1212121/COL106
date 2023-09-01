#include<iostream>
using namespace std;

void merge(int *A,int left,int mid,int right,int* T){
    // merges the sorted array A[left,....,mid-1] and A[mid,....,right-1].into the auxillary array T.
    int i=left;
    int j=mid;
    int d=0;
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
    for(int i=left;i<right;i++){           
        A[i]=T[i];
    }
}

void mergesort(int* A,int size,int *T){                   // Recursive.
    int mid=(size)/2;  
    if(size==1){
        T[0]=A[0];
        return;
    }
    mergesort(A,mid,T);
    mergesort(&A[mid],size-mid,T);    
    merge(A,0,mid,size,T);   
}


int main(){
    int A[]={30,14,24,13,2,89,76};
    int T[7];
    mergesort(A,7,T);
    for(int i=0;i<7;i++){
        cout<<T[i]<<" ";
    }cout<<endl;
    return 0;
}