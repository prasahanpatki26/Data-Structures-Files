#include<iostream>
using namespace std;

#include"traversal.h"
int main()
{
	
	char postfix[20];
	stack s;
	int i=0,rec;
	struct node *root=NULL;
	
	cout<<"Enter The PostFix Expression\n";
	cin>>postfix;
	root=create(postfix,s,root);
	
 do
	{
	cout<<"Which way you want to perform action ?\n";
	cout<<"1.With Recursion\n2.Without Recursion\n3.Enter Another Expression\n4.Exit\n";
	cin>>rec;
	

	    switch(rec)
	{
	    case 1:
            	cout<<"\nPreorder traversal is:\n";
            	rec_preorder(root);
            	cout<<"\n\n";
            	cout<<"Inorder traversal is:\n";
            	rec_inorder(root);
            	cout<<"\n\n";
            	cout<<"Postorder traversal is:\n";
            	rec_postorder(root);
            	cout<<"\n\n\n";
            	break;
        case 2:    	
            	cout<<"Preorder traversal without reursion is:\n";
            	preorder(root,s);
            	cout<<"Inorder traversal without reursion is:\n";
            	inorder(root,s);
            	cout<<"Postorder traversal without reursion is:\n";
            	postorder(root,s);
            	cout<<"\n\n\n";
            	break;
        case 3:
            	cout<<"Enter The PostFix Expression\n";
    	        cin>>postfix;
    	        root=create(postfix,s,root);
    	        break;
        
            	
    }
    }while(rec!=4);
}
