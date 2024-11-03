//
// Created by bhari on 02-09-2024.
//
#include<iostream>
using namespace  std;

void Delete1(int &n,int (&arr)[],int index){
    for(int i=index;i<n-1;++i){
        arr[i]=arr[i+1];
    }
    n--;
}

void Insert1(int &n,int arr[],int index,int target){
    for (int i = n; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = target;
    n++;
}

int main(){
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in sorted order:";
    for(int i=0;i<n;++i){
        int p;
        cin>>p;
        arr[i]=p;
    }
    cout<<"Enter Target element:";
    int target;
    cin>>target;
    int left=0;
    int right =n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target) {
            left=mid;
            break;}
        else if(arr[mid]>target){
            right=mid-1;
        }
        else {
            left = mid + 1;
        }
    }

    cout<<"array after:";

    if (arr[left] == target){
        Delete1(n, arr, left);

    }
    else{
       Insert1(n,arr,left,target);

    }
    cout<<"array after:";
    for(int i=0;i<n;++i){
        cout<<arr[i] << " ";
    }


   return 0;

}
