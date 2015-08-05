#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

bool isStringRepeat(string str)
{
  /*  bool char_set[256];
    memset(char_set,0,256);
    for(int i =0; i<str.length() ; i++)
    {
        int value=str[i];
        cout<<value<<"\n";
        if(char_set[value])
            return true;
        char_set[value]=true;
    }
    return false;*/
    
    // alternate approach
    int checker=0;
    for (int i=0; i<str.length();i++)
    {
        int pos=str[i]-'a';
        if ((checker & (1<<pos)) >0)
            return true;
         checker|=(1<<pos);
    }
    return false;
}
    

int main()
{
    string str;
    while(true)
    {
        cin>>str;
        if(str.length()==0)
            break;
        if(isStringRepeat(str))
            cout<<"Yes there was repetition\n";
        else
            cout<<"No Repetition\n";
    }
}