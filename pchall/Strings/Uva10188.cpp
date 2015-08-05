#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <functional>
#include <numeric>
#include <map>
#include <queue>

#define s(n)            scanf("%d",&n);
#define forall(i,a,b)   for(int i=a;i<b;i++)
#define tr(container,it)        for(typeof(container.begin()) it =container.begin();it!=container.end();it++)

using namespace std;

bool compare_string(vector<string> &correct,vector<string> &output)
{
    if(correct.size()!=output.size())
        return false;
    forall(i,0,correct.size())
        if (correct[i]!=output[i]) return false;
    return true;
}
        
 
string numericals (vector<string> &lines)
{
    string numbers="";
    forall(i,0,lines.size())
    {
        forall(j,0,lines[i].size())
            if (lines[i][j]>='0' && lines[i][j]<='9') numbers+=lines[i][j];
    }
    return numbers;
}

int main()
{
    int a,b,counter=1;
    string str;
    cin>>a;
    while(a!=0)
    {
        vector<string> correct(a);
        //getline(cin,str);
        cin.ignore(100,'\n');
        forall(i,0,a)
            getline(cin,correct[i]);
        cin>>b;
        //getline(cin,str);
        cin.ignore(100,'\n');
        vector<string> output(b);
        forall(i,0,b)
            getline(cin,output[i]);
        bool string_match=compare_string(correct,output);
        if (string_match)
            cout<<"Run #"<<counter<<": Accepted\n";
        else
        {
            bool numeric_match=(numericals(correct)==numericals(output));
            if (numeric_match)
                cout<<"Run #"<<counter<<": Presentation Error\n";
            else
                cout<<"Run #"<<counter<<": Wrong Answer\n";
        
        }
        counter++;
        cin>>a;
    }
}
        
            
        
           