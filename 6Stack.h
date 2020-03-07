//----------------------------stack-------------------

#include <iostream>
using namespace std;
#include<string.h>
template<class t>
class stack
{
    struct node
    {
        t data;
        struct node *next;
    } * top;

  public:
    void push(t);
    t pop();
    int isempty();
    stack()
    {
        top = NULL;
    }
    ~stack()
    {
        node *del;
        while (top != NULL)
        {
            del = top;
            top = del->next;
            delete del;
        }
    }
};
template <class t>
int stack <t> ::isempty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
        return 0;
}
template <class t>
void stack <t> ::push(t x)
{
    node *newnode;
    newnode = new node;
    newnode->next = NULL;
    newnode->data = x;
    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
template <class t>
t stack <t> ::pop()
{
   
        t x;
        node *node_del;
        node_del = top;
        x = node_del->data;
        top = top->next;
        delete node_del;
        return x;
   
}

