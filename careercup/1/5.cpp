#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

string newString(string s)
{
    int count=0;
    for(int i=0;i<s.length();i++)
        if(s[i]==' ') count++;
    int newlength=s.length()+(2*count);
    string str(newlength,' ');
    for(int i =0,j=0;i<s.length();i++,j++)
    {
        if(s[i]==' ')
        {
            str[j]='%';
            str[j+1]='2';
            str[j+2]='0';
            j+=2;
        }
        else
            str[j]=s[i];
    }
    return str;
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        if(str=="")
            break;
        cout<<newString(str)<<"\n";
    }
    return 0;
}
        
