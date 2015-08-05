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

void readLines(vector<string> &all_lines)
{
    string str;
    while(getline(cin,str))
    {
        if (str.length()==0)
            break;
        all_lines.push_back(str);
    }
}

void selectLines(vector<string> &all_lines,vector<string> &probable_lines,string ans)
{
    forall(i,0,all_lines.size())
    {
        if (all_lines[i].length()!=ans.length())
            continue;
      //  cout<<all_lines[i]<<"hi\n";
        forall(j,0,ans.length())
        {
            if(ans[j]==' ' && all_lines[i][j]!=' ')
                break;
            if(j==ans.length()-1)
                probable_lines.push_back(all_lines[i]);
        }
    }
}
 
bool create_map(map<char,char> &decryption,string ans,string str)
{
    map<char,char> encryption;
   forall(i,0,ans.length())
    {
        
        if ((decryption.find(str[i])==decryption.end()) && (encryption.find(ans[i]) == encryption.end()))
        {
            decryption[str[i]]=ans[i];
            encryption[ans[i]]=str[i];
        }
        else if ((decryption.find(str[i])!=decryption.end()) && (encryption.find(ans[i]) != encryption.end()))
        {
           // cout<<"hi"<<str[i]<<"hi"<<"\n";
            if (decryption[str[i]]==ans[i] && encryption[ans[i]]==str[i])
                continue;
            else
                return false;
        }
        else
        {   cout<<"hi"<<str[i]<<"hi"<<"\n";
            return false;}
    }
    return true;

}
    
void decrypt( map<char,char> &key,vector<string> &all_lines )
{
    forall(i,0,all_lines.size())
    {
        string str=all_lines[i];
        forall(j,0,str.length())
            str[j]=key[str[j]];
        cout<<str<<"\n";
    }
}
            
    

int main()
{
    int test_cases;
    cin>>test_cases;
    string str;
    string ans="the quick brown fox jumps over the lazy dog";
    //getline(cin,str);
    getline(cin,str);
    forall(i,0,test_cases)
    {
        vector<string> all_lines,probable_lines;
        readLines(all_lines);
        selectLines(all_lines,probable_lines,ans);
        // forall(k,0,3)
            // cout<<all_lines[k]<<all_lines[k].length()<<"\n";
       // cout<<probable_lines[0]<<"\n";
        cout<<ans;
        forall(j,0,probable_lines.size())
        {
            map<char,char> decryption;
            bool valid=create_map(decryption,ans,probable_lines[j]);
            tr(decryption,it)
                cout<<(*it).first<<" - "<<(*it).second<<"\n";
            if(valid)
                decrypt(decryption,all_lines);
            else if (!valid && j==probable_lines.size()-1)
                cout<<"No Solution";
        }
    }
    return 0;
}
           
            
        