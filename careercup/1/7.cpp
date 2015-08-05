#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

void removeZero(int **a,int m,int n)
{
    bool rows[m],columns[n];
    memset(rows,0,m);
    memset(columns,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)  
            {
                columns[i]=true;
                rows[j]=true;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(rows[j] || columns[i]) a[i][j]=0;
    }
}
 
void display(int **a,int m,int n)
{
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
} 
        
    
    

int main()
{
    int m,n;
    cin>>m>>n;
    int *a[n];
    for(int i =0;i<n;i++)
        a[i]=new int[m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    display(a,m,n);
    removeZero(a,m,n);
    display(a,m,n);
    return 0;
}
    