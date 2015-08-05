#include <iostream>
#include <stdio.h>

using namespace std;

void rotate(int **a, int n)
{
    int layer,i,first,offset,last;
    for(layer=0;layer<n/2;layer++)
    {
        first=layer;
        last=n-1-layer;
        for(i=first;i<last;i++)
        {
            offset=i-first;
            
            int temp=a[first][i];   //saving top left corner;
            //topright ->top left
            a[first][i]=a[last-offset][first];
            //bottomright ->topright
            a[last-offset][first]=a[last][last-offset];
            //bottomleft ->bottomright
            a[last][last-offset]=a[i][last];
            //topleft->bottomleft
            a[i][last]=temp;
        }
    }
}
            
            

void display(int **a,int n)
{
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    int n;
    cin>>n;
    int *matrix[n];
    for (int i=0;i<n;i++)
        matrix[i]=new int[n];
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
            matrix[i][j]=(i*n)+j;
    }
    display(matrix,n);
    cout<<"\n";
    rotate(matrix,n);
    display(matrix,n);
    return 0;
}
    