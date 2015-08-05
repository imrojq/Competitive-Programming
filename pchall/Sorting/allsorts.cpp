#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define forall(i,a,b)                   for(int i=a;i<b;i++)

void insertionSort(int array[],int n)
{
    int i,j,min;
    forall(i,0,n)
    {
        min=i; 
        forall(j,i+1,n)
            if(array[j]<array[min]) min=j;
        swap(array[i],array[min]);
    }
}

void selectionSort(int array[],int n)
{
    int i,j,count=0;
    forall(i,0,n)
    {
        j=i;
        while(j>0)
        {
            if(array[j]<array[j-1])
                swap(array[j],array[j-1]);
            j--;
        }
    }
}

void quickSort(int array[],int l,int h)
{
    if((h-l)<2)
        return;
    int counter=l;
    int pivot=h;
    int firsthigh=l;
    forall(i,l,h)
    {
        if(array[i]<array[pivot])
        {
            swap(array[i],array[firsthigh]);
            firsthigh++;
        }
    }
    swap(array[pivot],array[firsthigh]);
    int p=firsthigh;
    quickSort(array,l,p-1);
    quickSort(array,p+1,h);
    
}

void copy(int a[],int ai[],int left, int right)
{
    forall(i,left,right)
        ai[i-left]=a[i];
}

void merge(int a[],int a1[],int a2[],int size1,int size2)
{
    int i=0,j=0;
    while(i<size1 && j<size2)
    {
        if(a1[i]<a2[j])
        {
            a[i+j]=a1[i];
            i++;
        }
        else
        {
            a[i+j]=a2[j];
            j++;
        }
    }
    if(i<size1)
    {
        forall(k,i,size1)
            a[k+j]=a1[k];
    }
    if(j<size2)
    {
        forall(k,j,size2)
            a[i+k]=a2[k];
    }
}
    
void mergeSort(int a[],int n)
{
    if(n<2)
        return;
    int size1=n/2;
    int size2=n-size1;
    int a1[size1];
    int a2[size2];
    copy(a,a1,0,size1);
    copy(a,a2,size1,n);
    mergeSort(a1,size1);
    mergeSort(a2,size2);
    merge(a,a1,a2,size1,size2);
}
    
    
    
    
void display(int a[],int n)
{
    forall(i,0,n)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    int array[n];
    forall(i,0,n)
        array[i]=rand()%100;
    display(array,n);
    mergeSort(array,n);
    display(array,n);
    quickSort(array,0,n-1);
    display(array,n);
    return 0;
}
        
            