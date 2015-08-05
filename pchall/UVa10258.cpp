#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;


#define forall(i,a,b)                   for(int i=a;i<b;i++)
#define all(c)                          c.begin(),c.end()
#define tr(container,it )               for(typeof(container.begin()) it = container.begin(); it!=container.end();it++)


class student 
{
    public:
    int studentNumber;
    int penalty;
    int problems;
    bool participated;
    vector<bool> solved;
    student();
    
    bool operator < (const student &p) const
    {
        if (problems > p.problems) return true;
        if (problems < p.problems) return false;
        
        if (penalty < p.penalty) return true;
        if (penalty > p.penalty) return false;
        
        if (studentNumber < p.studentNumber) return true;
        if (studentNumber < p.studentNumber) return false;
        
        return false;
        
    }
        
        
    
 };
 
 student::student()
{
    penalty=0;
    problems=0;
    solved.resize(10,false);
}

 
int main()
{
    int t;
    string line;
    int studentnum,problem,time;
    char status;
    cin>>t;
    getline(cin,line);
    getline(cin,line);
    forall(i,0,t)
    {
        //cout<<line;
        vector<student> v(100);
        forall(j,0,100)
            v[j].studentNumber=j+1;
        while(true)
        {
            getline(cin,line);
            if (line.empty())
                break;
            istringstream iss(line);
            iss>>studentnum;
            iss>>problem;
            iss>>time;
            iss>>status;
            studentnum-=1;
            v[studentnum].participated=true;
            if (!v[studentnum].solved[problem])
            {
                if (status == 'I')
                    v[studentnum].penalty+=20;
                if (status == 'C')
                {
                    v[studentnum].penalty+=time;
                    v[studentnum].problems+=1;
                    v[studentnum].solved[problem]=true;
                }
            }
        }
        sort(all(v));
        forall(j,0,100)
        {
            
            if(v[j].participated)
            {
                cout<<v[j].studentNumber<<" ";
                cout<<v[j].problems<<" ";
                cout<<v[j].penalty<<"\n";
            }
        }
        
        cout<<"\n";
    }
    return 0;
}
        
                
            
            
        
        