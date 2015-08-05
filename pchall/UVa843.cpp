#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define forall(i,a,b)                   for(int i=a;i<b;i++)
#define all(c)                          c.begin(),c.end()
#define tr(container,it )               for(typeof(container.begin()) it = container.begin(); it!=container.end();it++)



typedef vector<string> vs; 
typedef map<int,vs> ivs;
typedef map<string,vs> svs;
typedef map<char,char> cc;
typedef pair<int,string> is;
typedef vector<is> vis;
typedef map<string,string> ss;

void readDict ( ivs &wordLengths , int n)
{
    forall(i,0,n)
    {
        string str;
        cin>>str;
        wordLengths[str.length()].push_back(str);
    }
}

void createClass( svs &eqclass , ivs &wlen, vs &words, string line)
{
    string word;
    istringstream iss(line);
    while (iss >> word )
    {
        eqclass[word] = wlen[word.length()];
        words.push_back(word);
    }
}

void orderWord ( vis &worder , svs &eqClass)
{
    tr(eqClass,it)
        worder.push_back(is(((*it).second).size(),(*it).first));
    sort(all(worder));
}

bool locallyConsistent(string word1,string word2)
{
    cc temp;
    forall(i,0,word1.length())
    {
        if (temp.find(word1[i])==temp.end())
            temp[word1[i]]=word2[i];
        else
        {
            if (temp[word1[i]]!=word2[i])
                return false;
        }
    }
    return true;
}


bool globallyConsistent(string word1,string word2,cc &mp,vector<char> &changes)
{
    forall(i,0,word1.length())
    {
        if (mp.find(word1[i])==mp.end())
        {
            changes.push_back(word1[i]);
            mp[word1[i]]=word2[i];
        }
        else
        {
            if (mp[word1[i]]!=word2[i])
                return false;
        }
    }
    return true;
}    
 
void rollBack(vector<char> changes, cc &mp)
{
    forall(i,0,changes.size())
        mp.erase(changes[i]);
}
        
        
 
bool correctMapping ( svs &eqClass , vis &wordOrder, cc &mapping1 ,cc &mapping2, int i,ss &decrypt)
{
    if (i==wordOrder.size())
        return true;
    string word1=wordOrder[i].second;
    vs v = eqClass[word1];
    forall(j,0,v.size())
    {
        vector<char> changes1,changes2;
        string word2=v[j];
        if (!locallyConsistent(word1,word2) || !locallyConsistent(word2,word1))
            continue;
        if (!globallyConsistent(word1,word2,mapping1,changes1) || !globallyConsistent(word2,word1,mapping2,changes2))
        {
            rollBack(changes1,mapping1);
            rollBack(changes2,mapping2); 
            continue;
        }
        if (!correctMapping(eqClass,wordOrder,mapping1,mapping2,i+1,decrypt))
        {   
            rollBack(changes1,mapping1);
            rollBack(changes2,mapping2);
            continue;
        }
        else
        {
            decrypt[word1]=word2;
            return true;
        }
            
    }
    return false;
}
        

int main()
{
    int n;
    cin>>n;
    ivs wordLengths;
    string line;
    readDict(wordLengths,n);
    getline(cin,line);
    while(getline(cin,line))
    {
        if (line.empty())
            break;
        svs eqClass;
        vs words;
        createClass(eqClass,wordLengths,words,line);
        vis wordOrder;
        orderWord(wordOrder,eqClass);
        cc mapping1,mapping2;
        ss decrypt;
        bool success =correctMapping(eqClass,wordOrder,mapping1,mapping2,0,decrypt);
        if (!success)
        {
            tr(words,it)
            {
                forall(j,0,(*it).length())
                    cout<<"*";
                cout<<" ";
            }
        }
        else
        {
        tr(words,it)
            cout<<decrypt[(*it)]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
        
}
            
            
