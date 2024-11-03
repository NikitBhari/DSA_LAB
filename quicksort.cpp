//
// Created by bhari on 21-10-2024.
//

#include<iostream>
using namespace  std;

int  partition(int *arr,int start,int end){
     int pivot=arr[end];
     int j=start-1;
     for(int i=start;i<end;++i){
         if(arr[i]<pivot){
             j++;
             int temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
         }
     }
     j++;
     arr[end]=arr[j];
     arr[j]=pivot;
     return j;
}

void Quicksort(int *arr ,int start,int end){
    if(start<end) {
        int mid = partition(arr, start, end);
        Quicksort(arr, start, mid - 1);
        Quicksort(arr, mid+1 , end);
    }
}


int main(){
    cout<<"Enter the size of the array You want  to sort:";
    int n;
    cin>>n;
    int * arr;
    arr= new int[n];
    cout<<"Enter the elements:";
    int a;
    for(int i=0;i<n;++i){
        cin>>a;
        arr[i]=a;
    }
    Quicksort(arr,0,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }


}