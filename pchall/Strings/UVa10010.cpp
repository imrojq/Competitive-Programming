#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

#define forall(i,a,b)                   for(int i=a;i<b;i++)
#define tr(container,it)        for(typeof(container.begin()) it =container.begin();it!=container.end();it++)
typedef pair<int,int>   ii;
//#define map<string,pii> mspii;

class node
{
    public :
    char letter;
    bool iswordend;
    vector<node*> children;
    node()
    {
        letter=' ';
        iswordend=false;
    }
    
    node* findchild(char c)
    {
        forall(i,0,children.size())
        {
            if (children[i]->letter == c)
                return children[i];
        }   
        return NULL;
    }
    
    void setletter(char c)
    {
        letter =c ;
    }
    void setwordend()
    {
        iswordend=true ;
    }

    
};






class tries 
{
    public :
    node *root,*current,*next;
    tries ()
    {
        root = new node;
    }
    void insert(string str)
    {
        current = root;
        forall(i,0,str.length())
        {
            next=current->findchild(str[i]);
            if (next!=NULL)
            {
                current=next;
                continue;
            }
            next=new node;
            next->setletter(str[i]);
            (current->children).push_back(next);
            current=next;
        }
        current->setwordend();
    }
    bool findword(string str)
    {
        current=root;
        forall(i,0,str.length())
        {
            next=current->findchild(str[i]);
            if (next==NULL)
                return false;
            current=next;
        }
        return true;
    }
    
    void display()
    {
        current=root;
        if (current->children.size()==0)
            cout<<"the trie is empty\n";
        while(current->children.size()!=0)
        {
            forall(i,0,current->children.size())
                cout<<current->children[i]->letter<<" ";
            current=current->children[0];
            cout<<current->letter<<current->iswordend<<"\n";
            
        }
    }
        
    
};


int main()
{
    int test_cases,m,n,n_words,x,y,pos_i,pos_j;
    node *parse,*next;
    map<string,ii> word_pos;
    string str;
    tries tr;
    char c;
    cin>>test_cases;
    forall(t,0,test_cases)
    {
        cin>>m>>n;
        vector< vector<char> > letters(n,vector<char>(m));
        forall(j,0,m)
        {
            forall(i,0,n)
            {
                cin>>c;
                letters[i][j]=tolower(c);
            }
        }
        cin>>n_words;
        forall(i,0,n_words)
        {
            cin>>str;
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            tr.insert(str);
        }
        cout<<"\n\n";
     /*   forall(j,0,m)
        {
            forall(i,0,n)
                cout<<letters[i][j];
            cout<<"\n";
        }
        
        tr.display();*/
        forall(j,0,m)
        {
            forall(i,0,n)
            {
                forall(x,-1,2)
                {
                    forall(y,-1,2)
                    {
                        if (!x&!y)
                            continue;
                        pos_i=i;
                        pos_j=j;
                        parse=tr.root;
                        str="";        
                        for(pos_i,pos_j;(pos_i >=0 && pos_i<n) && (pos_j>=0 && pos_j<m);pos_i+=x,pos_j+=y)
                        {
                            str+=letters[pos_i][pos_j];
                            if (str.length()>2)
                                cout<<str<<"\n";
                            
                            next=parse->findchild(letters[pos_i][pos_j]);
                            if(next!=NULL)
                            {
                                if(next->iswordend)
                                    word_pos[str]=ii(j+1,i+1);
                                parse=next;
                            }
                            else
                                break;
                        }
                       // cout<<"\n";
                    }
                }
            }
        }
        cout<<word_pos.size();
        tr(word_pos,it)
            cout<<(*it).first<<" "<<(*it).second.first<<","<<(*it).second.second<<"\n";
        
        
    }
    
    return 0;
}
            
        
            
