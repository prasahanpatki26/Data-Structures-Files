#include<iostream>
using namespace std;
#define size 20

struct node
{
	char data;
	struct node *left;
	struct node *right;
};

//struct node *root=NULL;

class stack
{
	int top;
	struct node* data[size];
	
	public:
	stack();
	void push(struct node *);
	struct node* pop();
	int isEmpty();
	int isFull();
	void display();
};

stack::stack()
{
	top=-1;
}

int stack::isEmpty()
{
	if(top==-1)
		return 0;
	return 1;
}

int stack::isFull()
{
	if(top==(size-1))
		return 0;
	return 1;
}



void stack::push(struct node *newnode)
{
	if(isFull()==0)
	{
		cout<<"Stack is Full\n";
	}
	else
	{
		top++;
		data[top]=newnode;
	}
}

struct node* stack::pop()
{
	struct node *x;
	if(isEmpty()==0)
	{
		cout<<"Cannot pop element from empty stack\n";
		return '\0';
	}
	else
	{
		x=data[top];
		top--;
		return x;
	}
}

void stack::display()
{
	int i;
	if(isEmpty()==0)
	{
		cout<<"Stack is Empty\n";
		return;
	}
	cout<<"Elements in stack are:\n";
	for(i=0;i<=top;i++)
	{
		cout<<data[i]<<"\t";
	}
	cout<<"\n";
}

/*int main()
{
	stack s;
	struct node *newnode;
	int z;
	char ch;
	do
	{
		cout<<"Enter your choice\n1.push\n2.pop\n3.display\n4.exit\n";
		cin>>z;
		switch(z)
		{
			case 1:
				cout<<"Enter element to push\n";
				cin>>ch;
				s.push(newnode);
				break;
			
			case 2:
				s.pop();
				if(ch!='\0')
					cout<<"popped element is "<<ch<<"\n";
				
			case 3:
				s.display();
				break;
		}
	}while(z<4);
	return 0;
}*/
