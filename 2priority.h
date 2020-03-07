#include<iostream>
#include<string.h>
using namespace std;

class queue
{
                struct node
                {
                    char name[10];
                    char bg[10];
                    int age,p;
                    struct node *next;
                }*front,*rear;

        public:
                queue();
                void enqueue(char n[10],char bg[10],int a);
                int delqueue();
                int isempty();
                void display();
};

queue::queue()
{
        front=NULL;
        rear=NULL;
}

int queue::isempty()
{
     if(front==NULL)
     {
        return 1;
     }
     else
        return 0;
}

void queue::enqueue(char n[10],char bg[10],int a)
{
     struct node *node=new struct node;;
     strcpy(node->name,n);
     
     node->age=a;
     node->next=NULL;
     if(isempty())
     {
        front=node;
        rear=node;
        return;
     }
     else
     {
        rear->next=node;
        node=rear;
     }

}

void queue::display()
{
struct node *temp;
     temp=front;
     while(temp!=NULL)
     {
      cout<<"\n";
      cout<<temp->name<<"\t";
      cout<<temp->age<<"\t";
      cout<<temp->bg<<"\t";
      temp=temp->next;
}
}

int queue::delqueue()
{
struct node *temp;
if(isempty())
     {
      cout<<"\nlist is empty";
        return 0;
     }
     temp=front;
     front=front->next;
     delete temp;
     return 1;
}

