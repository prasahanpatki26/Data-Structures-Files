#include<iostream>
using namespace std;
#include"stack.h"
#include<ctype.h>

struct node* create(char postfix[20],stack s,struct node *root)
{
	int i=0;
	while(postfix[i]!='\0')
	{
		struct node *newnode;
		newnode=new struct node;
		newnode->data=postfix[i];
		newnode->left=NULL;
		newnode->right=NULL;

		if(isalnum(postfix[i]))
		{
			s.push(newnode);
		}
		else
		{
			struct node *n1,*n2;
			n2=s.pop();
			n1=s.pop();
			newnode->right=n2;
			newnode->left=n1;
			s.push(newnode);
		}
		i++;
	}
	root=s.pop();
	return root;
}

void rec_preorder(struct node *temp)
{
	if(temp)
	{
		cout<<temp->data<<" ";
		rec_preorder(temp->left);
		rec_preorder(temp->right);
	}
}

void rec_inorder(struct node *temp)
{
	if(temp)
	{
		rec_inorder(temp->left);
		cout<<temp->data<<" ";
		rec_inorder(temp->right);
	}
}

void rec_postorder(struct node *temp)
{
	if(temp)
	{
		rec_postorder(temp->left);
		rec_postorder(temp->right);
		cout<<temp->data<<" ";
	}
}

void preorder(struct node *root,stack s)
{
	struct node *temp=root;
	while(temp!=NULL || (s.isEmpty()!=0))
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			s.push(temp);
			temp=temp->left;
		}
		temp=s.pop();
		temp=temp->right;
	}
	cout<<"\n\n";
}

void inorder(struct node *root,stack s)
{
	struct node *temp=root;
	while(temp!=NULL || (s.isEmpty()!=0))
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		temp=s.pop();
		cout<<temp->data<<" ";
		temp=temp->right;
	}
	cout<<"\n\n";
}

void postorder(struct node *root,stack s)
{
	stack o;
	struct node *temp=root;
	s.push(temp);
	while(s.isEmpty()!=0)
	{
		temp=s.pop();
		if(temp->left!=NULL)
			s.push(temp->left);
		if(temp->right!=NULL)
			s.push(temp->right);
		o.push(temp);
	}
	while(o.isEmpty()!=0)
	{
		temp=o.pop();
		cout<<temp->data<<" ";
	}
}

/*int main()
{
	char postfix[20];
	stack s;
	int i=0;
	struct node *root=NULL;


    cout<<"enter postfix expression\n";	cin>>postfix;
    root=create(postfix,s,root);
	
	cout<<"\nPreorder traversal with reursion is:\n";
	rec_preorder(root);
	cout<<"\n\n";
	cout<<"Inorder traversal with reursion is:\n";
	rec_inorder(root);
	cout<<"\n\n";
	cout<<"Postorder traversal with reursion is:\n";
	rec_postorder(root);
	cout<<"\n\n\n";
	
	cout<<"Preorder traversal without reursion is:\n";
	preorder(root,s);
	cout<<"Inorder traversal without reursion is:\n";
	inorder(root,s);
	cout<<"Postorder traversal without reursion is:\n";
	postorder(root,s);
	return 0;
}*/
