#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <queue>

#define s(n)            scanf("%d",&n);
#define forall(i,a,b)   for(int i=a;i<b;i++)
#define tr(container,it)        for(typeof(container.begin()) it =container.begin();it!=container.end();it++)

using namespace std;

bool customCompare(const string &a,const string &b)
{
    return a.length() < b.length() ;
}

set<string> allPossible(vector<string> &bits,int &i ,int &j)
{
    int mov_i=1,mov_j=1;
    set <string> combinations;
    if(bits[i+1].length()==bits[i].length())
        mov_i++;
    if(bits[j-1].length()==bits[j].length())
        mov_j++;
    forall(k,i,i+mov_i)
    {
        forall(l,j-mov_j+1,j+1)
        {
            combinations.insert(bits[k]+bits[l]);
            combinations.insert(bits[l]+bits[k]);
        }
    }
    i+=mov_i;
    j-=mov_j;
    return combinations;

}
    
            
    

int main()
{
    int t;
    string str;
    cin>>t;
    forall(i,0,t)
    {
        cin.ignore(100,'\n');
        vector<string> bits;
        set<string> combinations;
        while(getline(cin,str))
        {
            if(str=="")
                break;
            bits.push_back(str);
        }
        sort(bits.begin(),bits.end(),customCompare);
        int j=0,k=bits.size()-1;
        
        combinations=allPossible(bits,j,k);
        while(j<k)
        {
            set <string> intersect,returned; 
            returned=allPossible(bits,j,k);
            set_intersection(combinations.begin(),combinations.end(),returned.begin(),returned.end(),inserter(intersect,intersect.begin()));
            combinations=intersect;
        }
        cout<<*(combinations.begin());
    }
    return 0;
}
        