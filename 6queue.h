//---------------------------------------queue-----------------------

#include<iostream>
using namespace std;
template<class t>
class queue
{
    struct node
    {
        t data;
        node* next;
         
    }*rear,*front;
    public:
        void enqueue(t);
        t dequeue();
        int isEmpty();
        void display();
    queue()
    {
        front=rear=NULL;
    }
};
template <class t>
void queue <t> ::enqueue(t x)
{
    node *newnode;
    newnode = new node;
    newnode->next = NULL;
    newnode->data = x;
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=rear->next;
    }
}
template <class t>
t queue <t> ::dequeue()
{
        t x;
        node *node_del;
        node_del = front;
        x = node_del->data;
        if(front==rear)
        {         
            rear=NULL;
            front=NULL;
            delete node_del;
            return x;
        }
        front = front->next;
         
        delete node_del;
        return x;
}
template <class t>
int queue <t> ::isEmpty()
{
    if(front==NULL && rear==NULL)
    {
        return 1;
    }
    else 
        return 0;
}
