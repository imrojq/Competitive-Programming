#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <functional>
#include <numeric>
#include <map>
#include <queue>

#define s(n)                    scanf("%d",&n);
#define forall(i,a,b)           for(int i=a;i<b;i++)
#define tr(container,it)        for(typeof(container.begin()) it =container.begin();it!=container.end();it++)

using namespace std;

typedef vector<string> vs;
typedef map<string,vs> graph;
typedef map<string,string> ss;

using namespace std;

bool oneDifference(string str1,string str2)
{
    if(str1.length()!=str2.length())
        return false;
    int difference=0;
    forall(i,0,str1.length())
        if(str1[i]!=str2[i]) difference +=1;
    return difference==1;
}

void createGraph(vs &nodes, graph &g)
{
    forall(i,0,nodes.size())
    {
        g[nodes[i]]=vs();
        forall(j,0,nodes.size())
        {
            if(oneDifference(nodes[i],nodes[j]))
                g[nodes[i]].push_back(nodes[j]);
        }
    }
}

void initialiseExplored(graph &g,map<string,bool> &explored)
{
    tr(g,it)
        explored[(*it).first]=false;
}

void addToQueue(string present,queue<string> &q,map<string,bool> &explored,ss &predecessor,graph &g)
{
    vector<string>neighbours=g[present];
    forall(i,0,neighbours.size())
    {
        string child=neighbours[i];
        if (!explored[child])
        {
            explored[child]=true;
            q.push(child);
            predecessor[child]=present;
        }
    }
}

bool findPath(string source,string destination,ss &predecessor, vs &path)
{
    path.push_back(destination);
    string current=destination;
    while(current!=source)
    {
        if (predecessor.find(current)!=predecessor.end())
        {
            current=predecessor[current];
            path.push_back(current);
        }
        else
            return false;
    }
    return true;
}

void printPath(vs &path)
{
    int i=path.size()-1;
    for(i;i>-1;i--)
        cout<<path[i]<<"\n";

}
    
bool bfs(ss &predecessor,graph &g)
{
    
    queue<string> q;
    map<string,bool> explored;
    initialiseExplored(g,explored);
    string present=(*(g.begin())).first;
    explored[present]=true;
    addToQueue(present,q,explored,predecessor,g);
    while(!q.empty())
    {
        present=q.front();
        q.pop();
        addToQueue(present,q,explored,predecessor,g);
    }
    return true;
}
    

    
int main()
{
    string str;
    vs nodes;
    graph g;
    while(getline(cin,str))
    {
        if(str.length()==0)
            break;
        nodes.push_back(str);
    }
     //cout<<"hi";
     
    createGraph(nodes,g);
    string source,destination;
   /* tr(g,it)
    {
        cout<<(*it).first<<"\t";
        tr((*it).second,it1)
            cout<<(*it1)<<" ";
        cout<<"\n";
    }*/
    ss predecessor;
    vs path;
    bfs(predecessor,g);
    while(getline(cin,str))
    {
        vs path;
        if(str.length()==0)
            break;
        istringstream iss(str);
        iss>>source>>destination;
        bool success=findPath(source,destination,predecessor,path);
        if (success)
        printPath(path);
        else 
        cout<<"No Solution"<<"\n";
    }
}