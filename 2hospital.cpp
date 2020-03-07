#include<iostream>
#include "priority.h"
using namespace std;

int main()
{
queue a1,a2,a3;
char name[10];
char bg[10];
int ch,age,i,p;
do
    {
        cout<<"\n------------PATKI'S HOSPITAL-------------\n";
        cout<<"WELCOME\nWHAT DO YOU WANT TO DO ?\n";
        cout<<"\n1.ADD PATIENT\n2.DELETE PATIENT\n3.DISPLAY\n4.EXIT\n ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    cout<<"\nEnter The Name of The Patient: \n";
                    cin>>name;
                    cout<<"\nEnter The Age of The Patient\n: ";
                    cin>>age;
                    cout<<"\nEnter The BloodGroup:\n";
                    cin>>bg;
                    cout<<"\nEnter The Category Of the Patient:\n";
                    cout<<"\n1.Critical patients\n2.Medium patients\n3.Normal patients\n";
                    cin>>p;
                    switch(p)
                    {
                       
                        case 1: a1.enqueue(name,bg,age);
                                break;
                       
                        case 2: a2.enqueue(name,bg,age);
                                break;
                       
                        case 3: a3.enqueue(name,bg,age);
                                break;
                    }
                    break;
           
           
            case 2:
                    if(!a1.isempty())
                    {
                        a1.delqueue();
                        break;
                    }
                    else if(!a2.isempty())
                    {
                        a2.delqueue();
                        break;
                    }
                    else if(!a3.isempty())
                    {
                        a3.delqueue();
                        break;
                    }
                    else
                    {
                        cout<<"NOTHING TO DELETE";
                    }
                    break;
            case 3:
                    if(a1.isempty() && a2.isempty() && a3.isempty())
                    {
                        cout<<"\nlist is empty";
                        break;
                    }
                    cout<<"\nNAME\tAGE\tBLOODGROUP";
                    a1.display();
                    a2.display();
                    a3.display();
                    break;
        }
    }while(ch!=4);
    return 0;
}
