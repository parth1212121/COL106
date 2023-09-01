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


    int i=left;                                // IN palce partitining .....
    int j=right-1;                              // NO memeory wastage...
    int pivot=A[right];
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
void  Quicksort(int A[],int left,int right){

if((right-left)<=1){
    return;
}

int pivot,pi;
pi=left+((rand())%(right-left));   // Pick a random element from the index....

pivot=A[pi];
swap(A[pi],A[right]);

pi=partition(A,left,right);

// Partitioning the array using the element A[right] as a pivot
// Returns the index of the pivot.
// S1 is the A[left,....,pi-1] ,,S2 is  A[pi+1,...,right]

Quicksort(A,left,pi-1);
Quicksort(A,pi+1,right);

}


int main(){

    int a[]={4,3,2,8};

    Quicksort(a,0,3);
    for(int i=0;i<4;i++){
        cout<<a[i]<<" ";
    }cout<<endl;

    return 0;
}