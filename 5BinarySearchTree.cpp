#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    node *left,*right;
    int info;
}*root;

void insert(node *newnode)
{
    node *temp;
    temp=root;
        if(root==NULL)
           {
             root=newnode;
             return;
            }
        else
            {
             while(1)
               {
                if(newnode->info<temp->info)
                  {
                     if(temp->left!=NULL)
                      {
                        temp=temp->left;  
                      }
                     else
                     {
                        temp->left=newnode;
                        break;
                     }
                  }
                else
                  {
                    if(temp->right!=NULL)
                    {
                       temp=temp->right;
                    }
                    else
                    {
                       temp->right=newnode;
                       break;
                    }
                 } 
               
               }
            }
               
}
   
void trav_inorder(node *root)
{
    node* temp;
    temp=root;
    if(temp==NULL)
    return;
    trav_inorder(temp->left);
    cout<<temp->info<<"-";
    trav_inorder(temp->right);
}

void search(node *root,int c)
{
    if(root==NULL)
    {
        cout<<"\nData absent\n";
        return;
    }
    if(root->info==c)
    {
        cout<<"\nData present in the tree\n";
        return;
    }
    else if(c>root->info)
        search(root->right,c);
    
    else if(root->info>c)
        search(root->left,c);
}

node* mirror(node *root)
{
        node *root1;
        if(root==NULL)
            return NULL;
        
        root1=new node;
        root1->info=root->info;
        root1->left=mirror(root->right);
        root1->right=mirror(root->left);
        return root1;

}

void delet(node *parent,node *root,int key)
{
        node *temp,*prev;
        if(root==NULL)
        {
            cout<<"\nKey not found";
            return;
        }
        else if(key<root->info)
        {
            delet(root,root->left,key); //recursive call for left subtree
            return;
        }
        else if(key>root->info)
        {
            delet(root,root->right,key);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
                {
                temp=root;
                if(parent->right!=NULL && parent->left->info==key)
                parent->left=NULL;
                if(parent->left!=NULL && parent->right->info==key)
                parent->right=NULL;
                delete temp;
                cout<<"\nDeleted successfully";
                return;
                }
        if(root->left==NULL)
        {
                temp=root;
                parent->right=root->right;
                delete temp;
                cout<<"\nDeleted successfully";
                return;
        }
        else if(root->right==NULL)
        {
                temp=root;
                parent->left=root->left;
                delete temp;
                cout<<"\nDeleted successfully";
                return;
        }
        
        }
}
struct node1
{

    node1 *next;
    struct node *s;

};
class queue
{
struct node1 *front,*rear;
public:
        void enqueue(node*);
        node* dequeue();
        int isempty();


}q1,q2,q;

void queue :: enqueue(node* a)
{
node1 *newnode;
newnode=new node1;
newnode->next=NULL;
newnode->s=a;
  if(front==NULL&&rear==NULL)
    {
        front=rear=newnode;
       
    }
    else if(front==rear)
    {
        front->next=newnode;
        rear=newnode;
       
       
    }
    else
    {
      rear->next=newnode;
        rear=newnode;  

    }
}

node* queue :: dequeue()
{
struct node1 *temp;
    if(!isempty())
    {
        temp=front;
        if(front==rear)
            rear=rear->next;
        //front=front->next;
        front=temp->next;
        return temp->s;
        //delete temp;
    }
}

int queue :: isempty()
        {
        if(front==NULL && rear==NULL)
        {
        return 1;
        }
        else
        return 0;
        }


void disp_level(node* root)
{
        int level=-1;
        node* temp;
        
        q1.enqueue(root);
        while( !q1.isempty() || !q2.isempty() )
        {
            level+=1;
            cout<<"\nLevel "<<level<<": ";
            while(!q1.isempty())
            {
                temp=q1.dequeue();
                cout<<temp->info<<" ";
                if(temp->right!=NULL)
                q2.enqueue(temp->right);
                if(temp->left!=NULL)
                q2.enqueue(temp->left);
            
            }
            q=q1;
            q1=q2;
            q2=q;
        }
}   


void deleter(int key,node* parent,node* root)
{
    node *temp,*prev;
    int inorder_sucessor;
        if(root==NULL)
        {
            cout<<"\nElement not found"; //if we traverse upto null and element not found
            return;
        }
        
        else if(key<root->info)
        {
            deleter(key,root,root->left); //recursive call for left subtree
        }
        
        else if(key>root->info)
        {
            deleter(key,root,root->right); //recursive call for right subtree
        }
        else //if key is found
        {
            if(root->left==NULL && root->right==NULL) //if leaf node
            {
                temp=root;
                if(parent->left!=NULL && parent->left->info==key) //if it is left leaf of its parent
                parent->left=NULL;
                if(parent->right!=NULL && parent->right->info==key) //if it is right leaf of its parent
                parent->right=NULL;
                delete temp;
                return;
            }
            else //if not a leaf node
            {
                if(root->right==NULL) //having only left child
                    {
                    
                    temp=root;
                    temp=root->left;
                    if(parent==NULL)
                      {
                        root->info=temp->info;
                        root->left=temp->left;
                        return;
                      }
                     if(parent->info<root->info) //if node occurs in right subtree
                        parent->right=root->left;
                     else
                        parent->left=root->left; //if node occurs in left subtree
                         delete temp;
                    }
                else if(root->left==NULL) //having only right child
                    {
                        temp=root;
                        temp=root->right;
                        if(parent==NULL)
                            {
                                root->info=temp->info;
                                root->right=temp->right;
                                return;
                            }
                        if(parent->info<root->info)
                            parent->right=root->right;
                        else
                            parent->left=root->right;
                            delete temp;
                    }       
                else //both right and left child present
                    {
                        temp=root;
                        temp=temp->right; //finding inorder sucessor
                        while(temp->left!=NULL) //it is leftmost node in right subtree
                            {
                                prev=temp; //storing previous node in prev for doing left/right NULL
                                temp=temp->left;
                            }
                        inorder_sucessor=temp->info; //store data of Inorder Sucessor
                        prev->left=NULL;
                        delete temp;
                         root->info=inorder_sucessor; //replace its contents in node which was supposed to deleted
        
                   }
       
            }
        
            
        }

    
}

int main()
{   node *newnode,*root2;
    root=NULL;
    int cho,n,i,j;
    int data,key;
   
    do
    {
    cout<<"\nMENU:\n1)Insert\n2)Delete\n3)Search\n4)Mirror Image\n5)Display\n6)Display Level wise\n7)Exit\n";
    cin>>cho;
    switch(cho)
    {
        case 1:cout<<"\nEnter the data you want to insert\n";
                cin>>data;
                newnode=new node;
                newnode->left=NULL;
                newnode->right=NULL;
                newnode->info=data;
                insert(newnode);
                break;
       
        case 2:
        cout<<"\nEnter the data you want to delete\n";
        cin>>key;
        deleter(key,NULL,root);
        break;
       
        case 3:
              cout<<"\nEnter the data you want to search\n";
              cin>>data;
              search(root,data);
        break;
       
        case 4:cout<<"\nMirror image of the tree is: \n";
        root2=mirror(root);
        trav_inorder(root2);
        break;
       
        case 5:cout<<"\nThe tree is : ";
        trav_inorder(root);
        break;
       
        case 6:
        disp_level(root);
        break;
       
       
       
    }
   
    }while(cho!=7);
}

