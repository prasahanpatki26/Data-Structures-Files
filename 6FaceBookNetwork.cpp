#include<iostream>
#include<string.h>
#include"queue.h"
#include"stack.h"


using namespace std;
struct node
{
    char name[20];
    int date,month,year;
    int comment;
    int visited;
    int f;
    node* next;
};
class graph
{
    struct node* head[10];
    int n;
    public:
        void accept();
        void display();
        node maxFriends();
        void DFS();
        void BFS();
        void BDAY(int);
};

void graph::accept()
{
    node *newnode,*temp;
    char tname[20];
    int i=0,j=0,k=0,flag=0;
    cout<<"\nEnter number to people\n";
    cin>>n;
    cout<<"\nGive The Information of all People\n";
    while(i<n)
    {
        head[i]= new node;
        head[i]->visited=0;
        cout<<"\nEnter name of \t"<<i+1<<"st friend\n";
        cin>>head[i]->name;
        //strcpy(head[i]->name,array[i].name);
        cout<<"\nEnter Date of birth of "<<i+1<<"st friend\n";
        cout<<"\nDate: ";
        cin>>head[i]->date;
        while(head[i]->date>31 || head[i]->date<0)
        {
            cout<<"\nInvalid date";
            cout<<"\nEnter again";
            cin>>head[i]->date;
        }
       
        cout<<"\nMonth: ";
        cin>>head[i]->month;
        while(head[i]->month>12 || head[i]->month<0)
        {
            cout<<"\nInvalid month";
            cout<<"\nEnter again";
            cin>>head[i]->month;
        }
        cout<<"\nYear: ";
        cin>>head[i]->year;
        cout<<"\nEnter number of comments";
        cin>>head[i]->comment;
        i++;
    }
    cout<<"\n---Creating adjacency list---\n";
    i=0;
    while(i<n)
    {
        cout<<"\nEnter number of friends to "<<i+1<<"th friend";
        cin>>head[i]->f;
            
        while(head[i]->f>=n)
        {
            cout<<"\nNumber of friends can't be greater than n\nEnter again";
            cin>>head[i]->f;
        }
       
        j=0;
        while(j<head[i]->f)
        {
            flag=0;
            newnode=new node;
            newnode->next=NULL;
            cout<<"\nEnter name to search ";
            cin>>tname;
            for(k=0;k<n;k++)
            {
                if(strcmp(head[k]->name,tname)==0)
                {
                    if(k==i)
                    {
                        cout<<"\nCan't add anyone as his own friend";
                        j--;
                        delete newnode;
                        flag=1;
                        break;
                    }
                    strcpy(newnode->name,head[k]->name);
                    newnode->date=head[k]->date;
                    newnode->month=head[k]->month;
                    newnode->year=head[k]->year;
                    newnode->comment=head[k]->comment;
                    newnode->next=NULL;
                    cout<<"\nFriend added sucessfully\n";
                    break;
                }
                if(k==n-1)
                {
                    cout<<"\nNo user found";
                    j--;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                if(j==0)
                {
                    head[i]->next=newnode;
                    newnode->next=NULL;
                }
                else
                {
                    temp=head[i];
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
            }
            j++;
        }
        i++;
    }
}
void graph::display()
{
    int choice;
    int j;
    node *temp;
    cout<<"\nWho's Information do you want to see";
    cout<<n;
    for(j=0;j<n;j++)
    {
        cout<<"\n"<<j+1<<")";
        cout<<head[j]->name;
    }
    cin>>choice;
    while(choice>n&&choice<=0)
    {
        cout<<"\nEnter valid choice";
        cin>>choice;
    }
    cout<<"\nName: "<<head[choice-1]->name;
    cout<<"\nDOB: "<<head[choice-1]->date<<"/"<<head[choice-1]->month<<"/"<<head[choice-1]->year;
    cout<<"\nNumber of comments"<<head[choice-1]->comment;
    if(head[choice-1]->f!=0)
    {
        temp=head[choice-1]->next;
        cout<<"\nFriend list of"<<head[choice-1]->name;
        cout<<"\nName\tDOB\tComments";
        while(temp!=NULL)
        {
            cout<<endl<<temp->name<<"\t"<<temp->date<<"/"<<temp->month<<"/"<<temp->year<<"\t"<<temp->comment;
            temp=temp->next;
        }
    }
    else
        cout<<"\nEmpty friend list";
   
}

void graph::DFS()
{
   
    node *max;
    node *min;
    max=head[0];
    min=head[0];
    stack<node*> s1;
    node *temp;
    int i,m;
    for(i=0;i<n;i++)
    {
        head[i]->visited=0;
    }
    s1.push(head[0]);
    head[0]->visited=1;
  
    while(!s1.isempty())
    {
        temp=s1.pop();
        if(temp->comment>=max->comment)
            max=temp;
        if(temp->comment<=min->comment)
            min=temp;
        while(temp!=NULL)
        {
            temp=temp->next;
          
            if(temp != NULL)
            {
                for(m=0;m<n;m++)
                {
                    if(strcmp(temp->name,head[m]->name)==0)
                    {
                        if(head[m]->visited==0)
                        {
                           
                            s1.push(head[m]);
                            head[m]->visited=1;
                            break;
                        }
                        break;   
                    }
                }
            }
          
        }
      
    }
    cout<<"\nFriend with maximum Comments("<<max->comment<<")";
    cout<<"\nName: "<<max->name;
   
    cout<<"\nFriend with minimum Comments("<<min->comment<<")";
    cout<<"\nName: "<<min->name;
}
void graph::BFS()
{
    queue<node*> q1;
    node *temp;
    node *max;
    max=head[0];
    int i,m;
    for(i=0;i<n;i++)
    {
        head[i]->visited=0;
    }
    q1.enqueue(head[0]);
    head[0]->visited=1;
    while(!q1.isEmpty())
    {
        temp=q1.dequeue();
        if(temp->f>=max->f)
            max=temp;
        while(temp!=NULL)
        {
            temp=temp->next;
            if(temp != NULL)
            {
                for(m=0;m<n;m++)
                {
                    if(strcmp(temp->name,head[m]->name)==0)
                    {
                        if(head[m]->visited==0)
                        {
                           
                            q1.enqueue(head[m]);
                            head[m]->visited=1;
                            break;
                        }
                        break;   
                    }
                }
            } 
        }
      
    }
    cout<<"\nFriend with maximum friends("<<max->f<<")";
    cout<<"\nName: "<<max->name;
}
void graph::BDAY(int mn)
{
   
    stack<node*> s1;
    node *temp;
    int i,m;
    for(i=0;i<n;i++)
    {
        head[i]->visited=0;
    }
    s1.push(head[0]);
    head[0]->visited=1;
  
    while(!s1.isempty())
    {
        temp=s1.pop();
        if(temp->month==mn)
            cout<<"\n"<<temp->name;
        while(temp!=NULL)
        {
            temp=temp->next;
          
            if(temp != NULL)
            {
                for(m=0;m<n;m++)
                {
                    if(strcmp(temp->name,head[m]->name)==0)
                    {
                        if(head[m]->visited==0)
                        {
                           
                            s1.push(head[m]);
                            head[m]->visited=1;
                            break;
                        }
                        break;   
                    }
                }
            }
          
        }
      
    }

}

int main()
{
    int ch;
    do
    {
        cout<<"\n------------FRIENDS NETWORK-----------\n";
        cout<<"\n---MENU:---\n1)Create network\n2)Display\n3)Maximum Comments\n4)Maximum friends\n5)Birthday's this month\n6)Exit\n";
        cin>>ch;
        graph g;
        switch(ch)
        {
            case 1:
               
                g.accept();
                break;
               
            case 2:
                g.display();
                break;
            case 3:
                g.DFS();
                break;
               
            case 4:
                g.BFS();
                break;
               
            case 5:
                int mn;
                cout<<"\nEnter current month number\n";
                cin>>mn;
                while(mn>12||mn<0)
                {
                    cout<<"\nInvalid month\nEnter again\n";
                    cin>>mn;
                }
                cout<<"\nBirthdays this month\n";
                g.BDAY(mn);
                break;
           
           
            case 6:
                break;
               
            default:
                cout<<"\nEnter correct choice";
                break;
        }
    }while(ch!=6);
    return 0;
}

