#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int x){
        data=x;
        next=NULL;
    }

};

class linkedlist{
    private:
    node* head;

    public:
    linkedlist(){
        head=NULL;
    }

    void insert(int x){
        node* p=new node(x);
        if(head==NULL){
            head=p;
            return ;

        }

        node* q=head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
        
    }

    void display(){
        node* q=head;
        while(q!=NULL){
            cout<<"linked list";
            cout<<q->data<<"-> ";
            q=q->next;
            
        }
    }

    void remove(int x){
        node* p=NULL;
        node* q=head;

    
        if(head->data==x){
            p=head;
            head=q->next;
            delete p;
            return;
        }
        q=q->next;

    while(q->next!=NULL){
        if(q->next->data==x){
            p=q->next;
            q->next=p->next;
            delete p;
            return;
        }
        cout<<"the required data not found";
    }


    }



};


int main(){
    linkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();

    list.remove(30);
    list.display();

    list.remove(10);
    list.display();

    return 0;
}