#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define forall(i,a,b)   for(int i=a;i<b;i++)

int main()
{
    string str1,str2,ans;
    while (getline(cin,str1))
    {
        ans="";
        getline(cin,str2);
        map<char,int> letter_count;
        forall(i,0,str1.length())
        {
            if (letter_count.find(str1[i]) !=letter_count.end())
                letter_count[str1[i]]+=1;
            else
                letter_count[str1[i]]=1;
        }
        forall(i,0,str2.length())
        {
            if (letter_count.find(str2[i]) !=letter_count.end())
            {
                ans+=str2[i];
                if (letter_count[str2[i]]==1)
                    letter_count.erase(str2[i]);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<"\n";
        
    }
    return 0;
}
        
        
    