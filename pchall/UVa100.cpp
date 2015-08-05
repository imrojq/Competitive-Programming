//UVa 100 3n+1 or Collatz problem 

#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    int t; 
    t=a;
    a=b;
    b=t;
}

int main()
{
    int iter;
    int left,right,i,j,maxlen,cycle_length,n;
    while (cin>>left>>right)
    {
        i=left;
        j=right;
        maxlen=0;
        if (i > j ) swap(i,j); 
        while ( i <= j )
        {
            n=i;
            cycle_length=1;
            while (n!=1 )
            {
                if (n & 1 ) n=(3*n)+1;    //if n is odd
                else n/=2;
                cycle_length++;
            
            }
            if (cycle_length>maxlen) maxlen=cycle_length;
            i++;
         
        }
        cout<<left<<" "<<right<<" "<<maxlen<<"\n";
    }
    return 0;
}
            
