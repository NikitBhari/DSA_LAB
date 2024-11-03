#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};
class Stack {
    Node* head;

public:
    Stack(){
        this->head = NULL;
    }

    bool isEmpty() {
        if(head == NULL){
            return 1;
        }
        else{
            return 0;
        }
    }

    void push(int value) {
        Node* newnode = new Node(value);

        newnode->next = head;
        head = newnode;
    }
    void pop() {
        if (this->isEmpty()) {
            cout << "Stackunderflow" << endl;
        }
        else {
            head = head->next;
        }
    }

    int top() {
        if (!isEmpty())
            return head->data;
        else {
            cout << "Stack is empty"<<endl;
            return 0;
        }
    }
};
bool valid( string s) {
    int cnt = 0;
    for (char ch : s) {
        if (isdigit(ch)) {
            cnt++;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (cnt < 2) {
                return false;
            }
            cnt--;
        }
        else {
            return false;
        }
    }
    return cnt == 1;
}

int main() {
    Stack st;
    string s;
    while(true){
        cout<<"Enter your postfix expression: ";
        cin>>s;
        if(valid(s)){
            break;
        }else{
            cout<<"Incorrect expression. Please enter again "<<endl;
        }
    }

    for(auto ch:s){
        if(ch!='+' && ch!='-' && ch!='/' && ch!='*'){
            int val=ch-'0';
            st.push(val);
        }
        else{
            int sec=st.top();
            st.pop();
            int f=st.top();
            st.pop();
            if(ch=='+'){
                st.push(f+sec);
            }
            else if(ch=='-'){
                st.push(f-sec);
            }
            else if(ch=='*'){
                st.push(f*sec);
            }
            else if(ch=='/'){
                st.push(f/sec);
            }
        }
    }
    cout<<st.top();
}