#include <cmath>
#include <cstdio>
#include <vector>
#include <string.h>

#include <iostream>
#include <algorithm>
using namespace std;

#define forall(i,a,b)                   for(int i=a;i<b;i++)

int main() 
{
    string str;
    cin>>str;
    int limit=1000000007;
    int array[26];
    forall(i,0,26)
        array[i]=0;
    forall(i,0,str.length())
        array[str[i]-'a']++;
    forall(i,0,26)
        array[i]/=2;
    int count=0;
    vector<int> chars;
    forall(i,0,26)
    {
        if(array[i]!=0)
        {
            chars.push_back(array[i]);
            count+=array[i];
        }
    }
   /* forall(i,0,chars.size())
        cout<<chars[i]<<"\n";
    cout<<count<<"\n";*/
    sort(chars.begin(),chars.end());
    int index=0,flag=1;
    unsigned long long ans=1;
    int j=1,k=chars[index];
    forall(i,1,count+1)
    {
        ans*=i;
        if(ans>(limit))
            ans%=limit;
        if(flag==1)
        {
            ans/=j;
            if(j==k)
            {
            j=1;
            if(index+1<chars.size())
                k=chars[++index];
            else
                flag=0;
            }
            else
                j++;
        }
    }
    cout<<ans;
    return 0;
}
        
            
            
        
        
    
    
        