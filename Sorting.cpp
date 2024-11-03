//
// Created by bhari on 21-10-2024.
//

#include<iostream>
using namespace  std;

void selectionsort(int * &arr,int n){
     for(int i=0;i<n-1;++i){
         int max=arr[0];
         int index=0;

         for(int j=0;j<n-i;++j){
             if(arr[j]>max){
                 max=arr[j];
                 index=j;
             }
         }
         int temp = arr[n - i - 1];
         arr[n - i - 1] = max;
         arr[index] = temp;

     }


}
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

int  partition(int *arr,int start,int end){
    int pivot=arr[end];
    int j=start-1;
    for(int i=start;i<end;++i){
        if(arr[i]<=pivot){
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
        Quicksort(arr, mid + 1, end);
    }
}

void merge(int *arr, int start, int mid, int end) {
    int n = mid - start + 1;
    int left[n + 1];
    left[n] = INT_MAX;

    int m = end - mid;
    int right[m + 1];
    right[m] = INT_MAX;

    int j = 0;
    for (int i = start; i <= mid; ++i) {
        left[j] = arr[i];
        j++;
    }


    j = 0;
    for (int i = mid + 1; i <= end; ++i) {
        right[j] = arr[i];
        j++;
    }


    int i = 0;
    j = 0;
    for (int k = start; k <= end; ++k) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

void Mergesort(int *arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        Mergesort(arr, start, mid);      // Include mid
        Mergesort(arr, mid + 1, end);    // Start from mid + 1
        merge(arr, start, mid, end);
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
    cout<<"Enter which algo you want to use :"<<endl;
    cout<<"1 : for slelction sort:"<<endl<<"2: for insertion sort: "<<endl<<"3: for Bubble sort"<<endl<<"4 :for quick sort:"<<endl;
    cout<<"5: for merge sort:"<<endl;
    int p;
    cin>>p;
    if(p==1){
        selectionsort(arr,n);
    }
    else if(p==2){
        Insertionsort(arr,n);
    }
    else if(p==3){
        Bubblesort(arr,n);
    }
    else if(p==4){
        Quicksort(arr,0,n);
    }
    else if(p==5){
        Mergesort(arr,0,n);
    }
    else{
        cout<<"Enter a valid option"<<endl;
    }
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }


}