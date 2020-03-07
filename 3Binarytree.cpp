#include<iostream> 
#include"travelbinary.h"
using namespace std;

void insert(node* newnode, node** root)
{
    int ch;
    node *temp;
    temp=*root;
    if(*root==NULL)
        {
            *root=newnode; //if root is NULL then make newnode the root
            return;
        }
    while(1)
        {
            cout<<"\nWhere do you want to enter ("<<temp->data<<")\n1)Left\n2)Right";
            cin>>ch;
            if(ch==1) //for inserting left
            {
                if(temp->left!=NULL)
                {
                    temp=temp->left; //if left isn't NULL then traverse to left
                }
                else
                {
                    temp->left=newnode; //if left is null then insert to left
                    break;
                }
            }
            else if(ch==2) //for inserting right
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right; //if right isn't NULL then traverse to right
                }
                else
                {
                    temp->right=newnode; //if right is null then insert to right
                    break;
                }
            }
        }
}

int depth(node* root)
{

    if (root == NULL) //if root is null then return 0
    return 0;
    
    else
    {
        int left_depth = depth(root->left); //calculate left_depth
        int right_depth = depth(root->right); //calculate right_depth
        if (left_depth > right_depth) //check the greater one
        return(left_depth + 1); //if left is greater then return previous left value+1
        else 
        return(right_depth + 1); //else return right value +1
        
    }
}

void leaf(node *root)
{
    node* temp;
    temp=root;
    if(temp==NULL)
        return;
        leaf(temp->left);
    if( (temp->left==NULL) && (temp->right==NULL) ) //traverse each node and check whether its left and right are NULL
        cout<<temp->data<<" ";
        leaf(temp->right);
}

node* copy(node* root)
{
    node *root2;
    if(root==NULL)
        return NULL;

    root2=new node; //allocate memory for new node
    root2->data = root->data; //copy data
    root2->left=copy(root->left); //call recursively for left part
    root2->right=copy(root->right); //call recursively for right part
    
    return root2; //return root of subtree
}
int main()
{
    int ch,d,sear;
    node *root,*root2;
    root=NULL;
    root2=NULL;
    
    do
    {
        cout<<"\n-----------BINARY TREE OPERATIONS----------";
        cout<<"\nMENU:\n1)Insert\n2)Display\n3)Depth\n4)Display leaf\n5)Create copy\n6)Exit\nEnter choice\n";
        cin>>ch;
        switch(ch)
            {
            case 1:
                    node* newnode;
                    newnode= new node; //allocate memory for newnode
                    cout<<"\nEnter data";
                    cin>>d;
                    newnode->data=d;
                    newnode->left=NULL;
                    newnode->right=NULL;
                    insert(newnode,&root);
                    break;
            case 2:
                    cout<<"\nInorder:- ";
                    trav_inorder(root);
                    cout<<"\nPreorder:- ";
                    trav_preorder(root);
                    cout<<"\nPostorder:- ";
                    trav_postorder(root);
                    
                    break;
            case 3:
                    cout<<"\nDepth of tree is:-\n";
                    break;
                    case 4:
                    cout<<"\nLeaf nodes are:-\n";
                    leaf(root);
                    
                    break;
            case 5:
                    root2=copy(root);
                    cout<<"\nCopy of tree is\n";
                    cout<<"\nInorder:- ";
                    trav_inorder(root2);
                    cout<<"\nPreorder:- ";
                    trav_preorder(root2);
                    cout<<"\nPostorder:- ";
                    trav_postorder(root2);
                    
                    break;
            case 6:
            
                    break;
                    
            default:
                    cout<<"Enter correct choice";
                    break;
            }
}while(ch!=6);
return 0;
}
