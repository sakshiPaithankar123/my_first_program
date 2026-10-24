#include<iostream>
using namespace std;

const int MAX=5;

class queue
{
    private:
    int a[MAX];
    int front;
    int rear;

    public:
    queue()
    {
        front=-1;
        rear=-1;
    }
    int empty(void)
    {
        if (front==-1 && rear==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int full(void)
    {
        if(rear==MAX-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void enqueue(int x)
    {
        if(full())
        {
            cout<<"\nqueue is full";
            return;
        }
        if(front==-1 && rear==-1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        a[rear]=x;
    }
    int dequeue(void)
    {
        if(empty())
        {
            cout<<"\nqueue is empty";
            return-1;
        }
        int x=a[front];

        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
        return x;
    }
    int peek(void)
    {
        if(empty())
        {
            cout<<"\nqueue is empty";
            return-1;
        }
        return a[front];
    }
    void display(void)
    {
        if(empty())
        {
            cout<<"\nqueue is empty";
            return;
        }
        cout<<"\nqueue elements:";
        for(int i=front;i<=rear;i++)
        {
            cout<<"\t"<<a[i];
        }
    }

};

int main()
{
    int x;
    queue q;

    q.enqueue(35);
    q.enqueue(67);
    q.enqueue(35);
    q.enqueue(92);
    q.enqueue(88);

    q.display();

    if(!q.empty())
    {
        x=q.dequeue();
        cout<<"\nremoved:"<<x;
    }
    q.display();

    x=q.peek();
    cout<<"\nfront element is:"<<x;

    return 0;
}
//PS D:\tejaswini> g++ "queue using array.cpp"
//PS D:\tejaswini> .\a.exe

//queue elements: 35      67      35      92      88
//removed:35
//queue elements: 67      35      92      88
//front element is:67
//PS D:\tejaswini> 

