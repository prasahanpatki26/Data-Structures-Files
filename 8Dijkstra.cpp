#include<iostream>
using namespace std;
#define INFINITY 999;

class graph
{
  int n;
  int cost[10][10];

  
  public:
       void accept();
       void display();
       void dijkstra();
      
};

void graph::accept()
{
    int i,j,ch1;
    
    cout<<"\nHow Many Vertices are there ?\n";
    cin>>n;
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                cost[i][j]=0;
            }
            else
            {
                cout<<"\nIs Link Present Between V"<<i+1<<"& V"<<j+1<<"\n";
                cout<<"\n1.Yes\n2.No\n";
                cin>>ch1;
                if(ch1==1)
                {
                    cout<<"\nEnter The Distance Between Them\n";
                    cin>>cost[i][j];
                }
                if(ch1==2)
                {
                    cost[i][j]=999;
                }
            }
        }
    }
    
    
}

void graph::display()
{
    int i,j;
    {
	    int i,j;
	    for(i=0 ; i<n ; i++)
	    {
	        cout<<"\n\t"<<i<<"]";
	        for(j=0 ; j<n ; j++)
	            cout<<"\t"<<cost[i][j];
	    }
	}
}

    
void graph::dijkstra()
{
    int i,j,k,min;
    int final[10],dist[10];
    for(i=0;i<n;i++)
    {
        final[i]=0;
        dist[i]=cost[0][i];
    }
    for(i=1;i<n;i++)
    {
        min=999;
        for(j=1;j<n;j++)
        {
            if(!(final[j])&&(dist[j]<min))
            {
                k=j;
                min=dist[j];
            }
        }
        final[k]=1;
        for(j=1;j<n;j++)
        {
            if(!(final[j])&&(min+cost[k][j]<dist[j]))
            {
                dist[j]=min+cost[k][j];
            }
        }
    }
    cout<<"\nShortest distance from Source V1:-";
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<"V"<<i+1<<"-"<<dist[i];
    }
}


int main()
{
    int ch;
    graph g;
    g.accept();
    
    
    
    
    do
    {
        cout<<"\nEnter The Option\n";
        cout<<"1.Display Adjacancy Matrix\n2.Find Shortest Path\n3.Exit\n";
        cin>>ch;
        
        switch(ch)
             {
                 case 1:
                       g.display();
                       
                 case 2:
                       g.dijkstra();
                     
             }
        
    }while(ch!=3);
 
 return 0;
    
}
