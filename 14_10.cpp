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
    cout << "By which method you want to implement queue? Enter 1 for array implementation and 2 for linked list implementation: "<<endl;
    int a;
    cin >> a;

    if (a == 1) {
        cout << "Enter the size of the array: "<<endl;
        int n;
        cin >> n;
        arrqueue a(n);
        while(true){
        cout<<"To push a element Enter 1 :"<<endl;
        cout<<"To pop a element Enter 2:"<<endl;
        cout<<"To print an element enter 3:"<<endl;
        int p;
        cin>>p;
        if(p==1){
            cout<<"enter the number youa want to push:"<<endl;
            int b;
            cin>>b;
            a.push(b);

        }
        else if(p==2){
            a.pop();
        }
        else if(p==3){
            a.print();
        }
        else{
            cout<<"Invalid Response:"<<endl;
            break;
        }
        }

    } else if (a == 2) {
        linkqueue pl;
        while(true){
            cout<<"To push a element Enter 1 :"<<endl;
            cout<<"To pop a element Enter 2:"<<endl;
            cout<<"To print an element enter 3:"<<endl;
            int p;
            cin>>p;
            if(p==1){
                cout<<"enter the number youa want to push:"<<endl;
                int b;
                cin>>b;
                pl.push(b);

            }
            else if(p==2){
                pl.pop();
            }
            else if(p==3){
                pl.print();
            }
            else{
                cout<<"Invalid Response:"<<endl;
                break;
            }

        }
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}