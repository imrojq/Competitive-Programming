#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define forall(i,a,b)                   for(int i=a;i<b;i++)

int main()
{
    int t;
    cin>>t;
    string str;
    cin.ignore(100,'\n');
    forall(i,0,t)
    {
        vector<int> dist;
        getline(cin,str);
        istringstream is(str);
        int temp;
        while(is>>temp)
            dist.push_back(temp);
    }
    return 0;
}
        