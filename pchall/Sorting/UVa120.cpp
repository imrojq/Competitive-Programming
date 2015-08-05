#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define forall(i,a,b)               for(int i=a;i<b;i++)

void flip(vector<int> &a,int index)
{
    int limit=(a.size()+index)/2;
    forall(i,index,limit)
        swap(a[i],a[a.size()-i-1]);
}

void display(vector<int> v)
{
    forall(i,0,v.size())
        cout<<v[i]<<" ";
    cout<<"\n";
}

int findMin(vector<int> v, int n)
{
    int minindex=n;
    int min=v[n];
    forall(i,n,v.size())
    {
        if(v[i]<min)
        {
            minindex=i;
            min=v[i];
        }
    }
    return minindex;
}

void sortByFlips(vector<int> &panCakes)
{
    int n=panCakes.size();
    int i=0;
    while(i<n)
    {
        int index=findMin(panCakes,i);
        if (index==n-1 && index!=i)
        {
            flip(panCakes,i);
            cout<<i+1<<" ";
        }
        else if (index!=i)
        {
            flip(panCakes,index);
            flip(panCakes,i);

            cout<<index+1<<" "<<i+1<<" ";
        }
        i++;
    }
    cout<<0<<"\n";
}




int main()
{
    string line;
    int num;
    while(getline(cin,line))
    {
        if(line.length()==0)
            break;
        istringstream iss(line);
        vector <int> panCakes;
        while (iss>>num)
            panCakes.push_back(num);
        display(panCakes);
        sortByFlips(panCakes);    
    }
}