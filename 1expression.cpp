#include<iostream>
#include<math.h>
#include"stack.h"
using namespace std;


int pr(char a)
{
if(a=='$')
return 3;
if(a=='*'||a=='/')
return 2;
if(a=='+'||a=='-')
return 1;
}
void values(char eqn[20])
{
    int i=0,j=0,k;
    char temp,opr;

    while(eqn[i]!='\0')
    {
        if((eqn[i]>='a' && eqn[i]<='z') || (eqn[i]>='A' && eqn[i]<='Z'))
        {
            cout<<"\nEnter the value of "<<eqn[i]<<" - ";
            cin>>temp;
            opr=eqn[i];

            while(eqn[j]!='\0')
            {
                if(opr==eqn[j])
                {
                    eqn[j]=temp;
                }
                j++;
            }
            j=0;
            i++;
        }
        else
        {
            i++;
        }
    }
}
void postf(char r[],char infix[])
{
stack s;
char y;
int i=0,j=0;
while(infix[i]!='\0')
{
if(infix[i]=='(')
{
s.push(infix[i]);
i++;
continue;
}
if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='$')
{
y=s.pop();
if(y=='#')
{
s.push(infix[i]);
}
else if(y=='(')
{
s.push(y);
s.push(infix[i]);
}
else
{
while(pr(y)>=pr(infix[i]) && y!='(' && y!='#')
{
r[j]=y;
j++;
y=s.pop();
}
if(y!='(' && y!='#')
{
if(pr(y)<pr(infix[i]))
{
s.push(y);
s.push(infix[i]);©
}
}
else
{
s.push(infix[i]);
}
}©
i++;
continue;
}
if(infix[i]==')')
{
y=s.pop();
while(y!='(')
{
r[j]=y;
j++;
y=s.pop();
}
}
else
{
r[j]=infix[i];
j++;
}
i++;
}
y=s.pop();
while(y!='#')
{
r[j]=y;
j++;
y=s.pop();
}
r[j]='\0';
}


void pref(char r[],char infix[])
{
stack s;
char y,temp;
int i,j,count=0;
for(i=0;*(infix+i)!='\0';i++)
{
count++;
}
for(i=0,j=count-1;i<j;i++,j--)
{
temp=infix[i];
infix[i]=infix[j];
infix[j]=temp;
}
infix[count]='\0';
i=0;
j=0;
while(infix[i]!='\0')
{
if(infix[i]==')')
{
s.push(infix[i]);
i++;
continue;
}
if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='$')
{
y=s.pop();
if(y=='#')
{
s.push(infix[i]);
}
else if(y==')')
{
s.push(y);
s.push(infix[i]);
}
else
{
while(pr(y)>=pr(infix[i]) && y!=')' && y!='#')
{
r[j]=y;
j++;
y=s.pop();
}
if(y!=')' && y!='#')
{
if(pr(y)<pr(infix[i]))
{
s.push(y);
s.push(infix[i]);
}
}
else
{
s.push(infix[i]);
}
}
i++;
continue;
}
if(infix[i]=='(')
{
y=s.pop();
while(y!=')')
{
r[j]=y;
j++;
y=s.pop();
if(y=='#')
break;
}
}
else
{
r[j]=infix[i];
j++;
}
i++;
}
y=s.pop();
while(y!='#')
{
r[j]=y;
j++;
y=s.pop();
}
count=0;
for(i=0;*(r+i)!='\0';i++)
{
count++;
}
for(i=0,j=count-1;i<j;i++,j--)
{
temp=r[i];
r[i]=r[j];
r[j]=temp;
}
//r[i]='\0';
}
void eval(char r[])
{
stack c;
char n1,n2;
int i=0;
int val;
values(r);
while(r[i]!='\0')
{
if(r[i]=='+' || r[i]=='-' || r[i]=='*' || r[i]=='/' || r[i]=='$')
{
n2=c.pop();
n1=c.pop();
if(r[i]=='+')
{
val=n1+n2;
c.push(val);
}
if(r[i]=='-')
{
val=n1-n2;
c.push(val);
}
if(r[i]=='*')
{
val=n1*n2;
c.push(val);
}
if(r[i]=='/')
{
val=n1/n2;
c.push(val);
}
if(r[i]=='$')
{
val=pow(n1,n2);
c.push(val);
}
}
else
{
c.push(r[i]-48);
}
i++;
}
val=c.pop();
cout<<"\nValue of expression is: ";
cout<<val;
}

void evalp(char r[])
{
int i,j,val,count=0;
char temp,n1,n2;
for(i=0;*(r+i)!='\0';i++)
{
count++;
}
for(i=0,j=count-1;i<j;i++,j--)
{
temp=r[i];
r[i]=r[j];
r[j]=temp;
}
values(r);
stack c;
i=0;
while(r[i]!='\0')
{
if(r[i]=='+' || r[i]=='-' || r[i]=='*' || r[i]=='/' || r[i]=='$')
{
n1=c.pop();
n2=c.pop();
if(r[i]=='+')
{
val=n1+n2;
c.push(val);
}
if(r[i]=='-')
{
val=n1-n2;
c.push(val);
}
if(r[i]=='*')
{
val=n1*n2;
c.push(val);
}
if(r[i]=='/')
{
val=n1/n2;
c.push(val);
}
if(r[i]=='$')
{
val=pow(n1,n2);
c.push(val);
}
}
else
{
c.push(r[i]-48);
}
i++;
}
val=c.pop();
cout<<"\nValue of expression is: ";
cout<<val;
}


int main()
{
char infix[20],r[20],temp;

int ch;
do
{
cout<<"\nEnter infix expression: ";
cin>>infix;
cout<<"\n1.Postfix\n2.Prefix\n3.Exit";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
postf(r,infix);
cout<<"\nPostfix expression is: ";
cout<<r;
eval(r);
break;
case 2:
pref(r,infix);
cout<<"\nPrefix expression is: ";
cout<<r;
evalp(r);
break;
case 3:
cout<<"\nExit\n";
break;
}
}while(ch!=3);
return 0;
}

