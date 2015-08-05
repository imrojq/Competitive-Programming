#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <numeric>

using namespace std;

bool isAnagram(string s1,string s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}

bool isAnagram1(string s1,string s2)
{
    int char_set[26];
    memset(char_set,0,26*4);
   for(int i =0;i<s1.length();i++)
        char_set[s1[i]-'a']+=1;
    for(int i =0;i<s2.length();i++)
        char_set[s2[i]-'a']-=1;
  /*  for(int i =0;i<26;i++)
        cout<<char_set[i]<<" ";*/
    return  accumulate(char_set,char_set+26,0)==0;
}
    

int main()
{
    string str1,str2;
    while(true)
    {
        getline(cin,str1);
        getline(cin,str2);
        if(str1.length()==0)
            break;
        if(isAnagram1(str1,str2))
            cout<<"yes it is a anagram\n";
        else
            cout<<"NO sir\n";
    }
            
}    