//
// Created by bhari on 02-09-2024.
//

#include <iostream>
using namespace std;

void Delete1(int &n, int arr[], int index) {
    for (int i = index; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void Insert1(int &n, int arr[], int index, int target) {

    int* arr1 = new int[n + 1];

    for (int i = 0; i < index; ++i) {
        arr1[i] = arr[i];
    }
    arr1[index] = target;


    for (int i = index + 1; i < n + 1; ++i) {
        arr1[i] = arr[i - 1];
    }

    n++;
    for (int i = 0; i < n; ++i) {
        arr[i] = arr1[i];
    }
    delete[] arr1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter target element: ";
    int target;
    cin >> target;

    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            left = mid;
            break;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (arr[left] == target) {
        Delete1(n, arr, left);
    } else {
        Insert1(n, arr, left, target);
    }

    cout << "Array after: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}
