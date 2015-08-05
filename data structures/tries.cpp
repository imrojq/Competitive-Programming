#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <vector>

using namespace std;

#define forall(i,a,b)                   for(int i=a;i<b;i++)

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
    
    tries t;
    string str;
   /* string command;
    cin>>command;
    node *test,*temp;
   /* test=new node;
    test->letter='a';
    cout<<test->letter;
    forall(i,0,26)
    {
        temp=new node;
        temp->setletter('a'+i);
        test->children.push_back(temp);
    }
    forall(i,0,26)
    {
        if (test->findchild('a'+0))
            cout<<(char)('a'+i)<<"present\n";
    }
    while(command!="end")
    {
        if (command=="in")
        {
            cin>>str;
            t.insert(str);
        }
        if (command=="d")
        {
            //cin>>str;
            t.display();
        }
        if (command=="s")
        {
            cin>>str;
            if (t.findword(str))
                cout<<"yes the number was found \n" ;
            else 
                cout<<"word not found\n";
        }
        cin>>command;
    }*/
    
    
    return 0;
}
 