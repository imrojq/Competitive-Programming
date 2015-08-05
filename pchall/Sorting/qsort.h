#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define forall(i,a,b)                   for(int i=a;i<b;i++)

void display(int array[],int l,int h)
{
    forall(i,l,h+1)
        cout<<array[i]<<" ";
    cout<<"\n";
}

void quickSort(int array[],int l,int h)
{
    if((h-l)<2)
        return;
    int counter=l+1;
    int pivot=l;
    int firsthigh=l+1;
    forall(i,l+1,h+1)
    {
        if(array[i]<array[pivot])
        {
            swap(array[i],array[firsthigh]);
            firsthigh++;
        }
    }
    swap(array[pivot],array[firsthigh-1]);
    int p=firsthigh;
    quickSort(array,l,p-1);
    quickSort(array,p+1,h);
    display(array,l,h);
    
}

int main()
{
    int n;
    cin>>n;
    int array[n];
    forall(i,0,n)
        cin>>array[i];
    quickSort(array,0,n-1);
}
       