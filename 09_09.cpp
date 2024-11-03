//
// Created by bhari on 09-09-2024.
//
#include<iostream>
using namespace  std;

class Node{
public:
    int val;
    Node * next;
    Node(){
        next=NULL;
    }
};

Node * Insert(int index,Node * head,Node * node){
    int n=0;
    Node * dummy=head;
    while(dummy != NULL){
        n++;
        dummy=dummy->next;
    }
    if(index<=n+1){
        if(index==1){
            node->next=head;
            head=node;
        }
        else{
        int i=1;
        dummy=head;
        while(i<index-1){
            dummy=dummy->next;
            i++;
        }
        Node * right= dummy->next;
        dummy->next=node;
        node->next=right;}
        return head;
    }
    return nullptr;
}
Node * Delete(int index,Node * head){
    int n=0;
    Node * dummy=head;
    while(dummy != NULL){
        n++;
        dummy=dummy->next;
    }
    if(index<=n){
        if(index==1){
            head=head->next;
        }
        else{
        int i=1;
        dummy=head;
        while(i<index-1){
            dummy=dummy->next;
            i++;
        }
        dummy->next=dummy->next->next;}
        return head;
    }
    return nullptr;
}


int main(){
    Node * fir1=new Node();
    fir1->val=1;

    Node * fir2=new Node();
    fir2->val=2;
    fir1->next=fir2;
    Node * fir3=new Node();
    fir3->val=3;
    fir2->next=fir3;
    Node * fir4=new Node();
    fir4->val=4;
    fir3->next=fir4;
    Node * fir5=new Node();
    fir5->val=5;
    fir4->next=fir5;
    Node * fir6=new Node();
    fir6->val=6;
    fir5->next=fir6;
    Node * fir7=new Node();
    fir7->val=7;
    fir6->next=fir7;

    int n=7;
   Node * Head=fir1;

    cout<<"Enter what and where you want to insert:";
    int k;
    int l;
    cin>>k;
    cin>>l;
    Node * in=new Node();
    in->val=k;
   Head= Insert(l,Head,in);
    Node * Head1=Head;

    while(Head1!=NULL){
        cout<<Head1->val<<endl;
        Head1=Head1->next;
    }
    cout<<"index you want to delete:";
    int h;
    cin>>h;
   Head= Delete(h,Head);
     Head1=Head;
    while(Head1!=NULL){
        cout<<Head1->val<<endl;
        Head1=Head1->next;
    }
    return 0;
}
