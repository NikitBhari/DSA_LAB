//
// Created by bhari on 21-10-2024.
//
#include<iostream>
using namespace  std;

void Bubblesort(int *arr ,int n){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
    Bubblesort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }


}