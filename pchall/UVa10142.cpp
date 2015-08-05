#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <functional>
#include <numeric>
#include <queue>

#define s(n)            scanf("%d",&n);
#define forall(i,a,b)   for(int i=a;i<b;i++)
#define tr(container,it)        for(typeof(container.begin()) it =container.begin();it!=container.end();it++)

using namespace std;

void readNames(vector<string> &names, int n)
{
    forall(i,1,n+1)
    {
        getline(cin,names[i]);
        if (names[i].empty())
            i--;
       // cout<<i<<" "<<names[i];
    }
    
}

void displayNames(vector<string> &names, int n)
{
    forall(i,1,n+1)
        cout<<names[i];
}

void readBallot(vector < queue<int> > &ballot, int n)
{
    string str;
    int x;
    while (true)
    {
        getline(cin,str);
        if (str.empty())
            break;
        istringstream iss(str);
        queue<int> temp;
        while ( iss >> x)
            temp.push(x);
       // cout<<temp.front()<<" ";
        ballot.push_back(temp);
    }
}

void initResult(vector < queue<int> > &ballot,vector<int> &result ,int n)
{
    forall(i,0,n+1)
        result[i]=0;
    int size=ballot.size();
    forall(i,0,size)
    {
       // cout<<ballot[i].front()<<"\n";
        result[ballot[i].front()]++;
    }
}

int getWinner(vector <int> &result, int n)
{
    double majority = accumulate(result.begin(),result.end(),0)/2.0;
    forall(i,1,n+1)
        if (result[i] > majority) return i;
    return 0;
}

bool isTie (vector <int> result , vector<bool> eliminated, int n)
{
    int i=1;
    while (eliminated[i])
        i++;
    int value = result[i];
    forall(j,i,n+1)
        if ( result[j]!=value && !eliminated[j]) return false;
    return true;
}

void eliminateMin(vector<int> &result, vector<bool> &eliminated,int n)
{
    int i=1;
    while (eliminated[i])
        i++;
    int min=result[i];
    forall(j,i,n+1)
        if (!eliminated[j] && result[j] < min) min=result[j];
    forall(j,i,n+1)
        if (!eliminated[j] && result[j]==min) eliminated[j]=true;
}
    

void prune ( vector < queue<int> > &ballot, vector<bool> &eliminated, vector<int> &result, int n)
{
    eliminateMin(result,eliminated,n);
    
    tr(ballot,it)
    {
        while(eliminated[(*it).front()])
        {    
            result[(*it).front()]--;
            (*it).pop();
            result[(*it).front()]++;
        }
    }
}
            
void printAllWinners(vector<int> result,vector<bool> eliminated,int n,vector<string> names)
{
    forall(i,1,n+1)
        if (!eliminated[i]) cout<<names[i]<<"\n";
}

using namespace std;

int main()
{
    int n;
    int t;
    string temp;
    cin>>t;
    getline(cin,temp);
    while(t--)
    {
        cin>>n;
        vector <string> names(n+1);
        readNames(names,n);
     //   displayNames(names,n);
        vector < queue<int> > ballot ;
        readBallot(ballot,n);
        
        
        
        vector <int> result(n+1);
        initResult(ballot,result,n);
        cout<<"\n";
        //forall(i,1,4)
          //  cout<<result[i]<<" ";
       
        vector <bool> eliminated(n+1);
        int num=getWinner(result,n);
        if (num!=0)
        {
            cout<<names[num];
            if (t>0) cout<<"\n";
            continue;
        }
            
            
        if (isTie(result,eliminated,n))
        {
            printAllWinners(result,eliminated,n,names);
            if (t>0) cout<<"\n";
            continue;
        }
         
        while (true)
        {
            prune(ballot,eliminated,result,n);

            int num=getWinner(result,n);
            if (num!=0)
            {
                cout<<names[num];
                break;
            }
            
            if (isTie(result,eliminated,n))
            {
                printAllWinners(result,eliminated,n,names);
                break;
            }
        }
        if (t>0) cout<<"\n";
     
            
        
        
    }
    return 0;
}
                
        
        
        
        
    