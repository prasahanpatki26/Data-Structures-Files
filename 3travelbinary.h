#include<iostream>

using namespace std;

struct node
{
int data;
struct node* left;
struct node* right;
};

void trav_preorder(node *root)
{
node *temp;
temp=root;
if(temp==NULL)
return;

cout<<temp->data;
trav_preorder(temp->left);
trav_preorder(temp->right);

}


void trav_inorder(node *root)
{

node* temp;
temp=root;
if(temp==NULL)
return;
trav_inorder(temp->left);
cout<<temp->data;
trav_inorder(temp->right);prajwalpatki


}

void trav_postorder(node* root)
{
node *temp;
temp=root;
if(temp==NULL)
return;

trav_postorder(temp->left);
trav_postorder(temp->right);
cout<<temp->data;

}
