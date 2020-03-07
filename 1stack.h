#include<iostream>
using namespace std;


class stack
{
struct node
{
char data;
struct node *next;
}*top;
public:
stack()
{
top=NULL;
}
void push(char x);
char pop();
~stack()
{
node *temp;
temp=top;
while(temp!=NULL)
{
top=temp->next;
delete temp;
temp=top;
}
}
};

void stack::push(char x)
{
node *newnode;
newnode=new node;
newnode->data=x;
newnode->next=NULL;
if(top==NULL)
{
top=newnode;
}
else
{
newnode->next=top;
top=newnode;
}
}

char stack::pop()
{
char x;
node *del;
if(top==NULL)
{
return '#';
}
del=top;
x=del->data;
top=top->next;
delete del;
return x;
}
