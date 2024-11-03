//
// Created by bhari on 14-10-2024.
//
#include <iostream>

using namespace std;

class arrqueue {
public:
    int n;
    int front;
    int *arr;
    int rear;

    arrqueue(int n1) {
        n = n1;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % n == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void push(int a) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % n;
        arr[rear] = a;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }

        int item = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % n;
        }

        return item;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i = (i + 1) % n) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class linkqueue {
public:
    Node* front;
    Node* rear;

    linkqueue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void push(int a) {
        Node* newNode = new Node(a);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }

        int item = front->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        return item;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "By which method you want to implement queue? Enter 1 for array implementation and 2 for linked list implementation: ";
    int a;
    cin >> a;

    if (a == 1) {
        cout << "Enter the size of the array: ";
        int n;
        cin >> n;
        arrqueue a(n);
        a.push(10);
        a.print();
    } else if (a == 2) {
        linkqueue pl;
        pl.push(10);
        pl.print();
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}