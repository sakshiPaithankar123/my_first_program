#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int x){
        data=x;
        next=NULL;
    }
};

class stack{
    private:
    node*top;

    public:
    stack(){
        top=NULL;
    }
    int empty(){
        if(top==NULL){
            return 1;
        }else{
            return 0;
        }
    }
    void push(int x){
        node*p=new node(x);
        p->next=top;
        top=p;
    }
    int pop(void){
        int x=top->data;
        node*p=top;
        top=top->next;
        delete p;
        return x;
    }
    int peek(){
        return top->data;
    }
    void display(){
        node*q=top;
        while(q!=NULL){
            cout<<endl<<q->data;
            q=q->next;
        }
    }
};
int main(){
    int x;
    stack s;

    s.push(880);
    s.push(710);
    s.push(444);
    s.push(578);
    s.push(200);
    s.push(330);

    s.display();
    if(!s.empty()){
        x=s.pop();
        cout<<endl<<"removed"<<x;
    }
    s.display();
    
    x=s.peek();
    cout<<endl<<"top element is:"<<x;

    return 0;


}
//PS D:\tejaswini> g++ "stack using linkedlist.cpp"
//PS D:\tejaswini> .\a.exe

//330
//200
//578
//444
//710
//880
//removed330
//200
//578
//444
//710
//880
//top element is:200
//PS D:\tejaswini> 