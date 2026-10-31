#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node(int x)
    {
        data=x;
        next=NULL;
    }
};
class queue
{
    private:
    node*front;
    node*rear;

    public:
    queue()
    {
        front=rear=NULL;
    }
    int empty(void)
    {
        if(front==NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int peek(void)
    {
        if(empty())
        {
            cout<<"\nqueue is empty";
            return-1;
        }
        return front->data;
    }
    void enqueue(int x)
    {
        node*p=new node(x);

        if (front==NULL)
        {
            front=p;
            rear=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
    }
    int dequeue(void)
    {
        if(empty())
        {
            cout<<"\nqueue is empty";
            return-1;
        }
        int x=front->data;
        node*p=front;

        front=front->next;

        if(front==NULL)
        {
            rear=NULL;
        }
        delete p;

        return x;
    }
    void display(void)
    {
        node*q=front;

        cout<<"\nqueue elements:";

        while(q!=NULL)
        {
            cout<<"\t"<<q->data;
            q=q->next;
        }
    }
};

int main()
{
    int x;
    queue q;

    q.enqueue(57);
    q.enqueue(43);
    q.enqueue(56);
    q.enqueue(48);
    q.enqueue(66);
    q.enqueue(50);

    q.display();
    
    if(!q.empty())
    {
        x=q.dequeue();
        cout<<"\nremoved:"<<x;
    }
    q.display();

    x=q.peek();
    cout<<"\nremoved:"<<x;
    
    return 0;
}

//PS D:\tejaswini> g++ "queue using linkedlist.cpp"
//PS D:\tejaswini> .\a.exe

//queue elements: 57      43      56      48      66      50
//removed:57
//queue elements: 43      56      48      66      50
//removed:43
//PS D:\tejaswini> 




