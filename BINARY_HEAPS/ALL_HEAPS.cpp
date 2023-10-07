#include<bits/stdc++.h>
using namespace std;                                 // Vector implementation.......

int Parent(int i){
    return (i-1)/2;
}
int leftchild(int i){
    return (2*i+1);
}
int rightchild(int i){
    return (2*i+2);
}

void heapifyUp(int index,vector<int>& heap){             //O(logn)

    if(index==0){
        return;   
    }
    else{
        int parent_index=Parent(index);
        if(heap[parent_index]>heap[index]){
            swap(heap[parent_index],heap[index]);
            heapifyUp(parent_index,heap);
        }
        return;
    }
}

void HeapifyDown(int index,vector<int>& heap){          //O(logn)

    int left=leftchild(index);
    int right=rightchild(index);
    int minindex=index;
    if(left>=heap.size()){
        return;
    }    
    if(left<heap.size() && heap[left]<heap[minindex]){
        minindex=left;
    }
    if(right<heap.size() && heap[right]<heap[minindex]) {
        minindex=right;
    }
    if(index!=minindex){
        swap(heap[minindex],heap[index]);
        HeapifyDown(minindex,heap);
    }
}

void insertion1(int val,vector<int>& heap){       //O(logn)

    heap.push_back(val);
    heapifyUp(heap.size()-1,heap);
    return;

}

void Deletemin(vector<int>& heap){                 //O(nlogn)

    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    HeapifyDown(0,heap);
}

void BuildHeap(vector<int>& arr){                   // O(n)

    int n=arr.size();
    for
(int i=(n/2-1);i>=0;i--){
        HeapifyDown(i,arr);
    }
}

void HeapifyDown_2(int index,vector<int>& heap,int i){          //O(logn)

    int left=leftchild(index);
    int right=rightchild(index);
    int minindex=index;
    if(left>=i){
        return;
    }    
    if(left<i && heap[left]<heap[minindex]){
        minindex=left;
    }
    if(right<i && heap[right]<heap[minindex]) {
        minindex=right;
    }
    if(index!=minindex){
        swap(heap[minindex],heap[index]);
        HeapifyDown_2(minindex,heap,i);
    }

}

void HeapSort(vector<int>& arr){           // O(nlogn)                // MEMORY---> O(1)

BuildHeap(arr);
for(int i=arr.size()-1;i>0;i--){
     swap(arr[0],arr[i]);
     HeapifyDown_2(0,arr,i);
}
reverse(arr.begin(),arr.end());

}

int k_largest(int k,vector<int> heap){


    vector<int>arr;
    for(int i=0;i<k;i++){
    arr.push_back(heap[i]);
        }

    BuildHeap(arr);
    for(int i=k;i<heap.size();i++){

            if(arr[0]<heap[i]){
                swap(arr[0],heap[i]);
            }
            HeapifyDown(0,arr);  
            }

return arr[0];

}

int k_small(int k,vector<int> &arr){

    BuildHeap(arr);

    for(int i=0;i<k-1;i++){
        Deletemin(arr);
    }
    return arr[0];

}



int main(){

    vector<int>heap;
    heap={10,1,2,3,4,5,6};
    HeapifyDown(0,heap);
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }cout<<endl;
    Deletemin(heap);
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }cout<<endl;
    vector<int>arr={3,8,1,2,5,6,9,13};
    BuildHeap(arr);                
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<k_largest(4,arr)<<endl;
    cout<<k_small(4,arr)<<endl;
    return 0;

}