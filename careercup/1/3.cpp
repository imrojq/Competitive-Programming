#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

string removeDuplicates(string s)
{
    int i,j,jump=0;
    for(i=1;i<s.length();i++)
    {
        s[i-jump]=s[i];
        for(j=0;j<(i-jump);j++)
            if(s[i]==s[j]) jump+=1;
    }
    return s.substr(0,s.length()-jump);
     
}

string removeDuplicates1(string s)
{
    int i,jump=0;
    bool char_set[26];
    memset(char_set,0,26);
    for(i=0;i<s.length();i++)
    {
        s[i-jump]=s[i];
        if (char_set[s[i]-'a'])
            jump+=1;
        else
            char_set[s[i]-'a']=true;
    }
    return s.substr(0,s.length()-jump);
    
};       
            

int main()
{
    string str;
    while(true)
    {
        getline(cin,str);
        if(str.length()==0)
            break;
        cout<<removeDuplicates1(str)<<"\n";
    }
}