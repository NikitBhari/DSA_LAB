//
// Created by bhari on 21-10-2024.
//
#include<iostream>
using namespace  std;

void Insertionsort(int *arr ,int n){
    for(int i=1;i<n;++i){
        int j=i;
        while(j>=1 && arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }

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
    Insertionsort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }


}