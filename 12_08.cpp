
// Created by bhari on 12-08-2024.

#include<iostream>

using namespace std;

void BubbleSort(int *arr,int n,bool flag){
    for(int i=0;i<n-1;++i){
        flag=true;
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                int a=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=a;
                flag=false;
            }

        }
        if(flag==true){
            return ;
        }

    }


}
int main(){
    cout<<"Enter the No. of elements in the array";
    int n;
    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;++i){
        int p;
        cin>>p;
        arr[i]=p;
    }
    bool flag=true;
    BubbleSort(arr,n,flag);

   for(int i=0;i<n;++i){
       cout<<arr[i]<<"  ";
   }
    return 0;
}

