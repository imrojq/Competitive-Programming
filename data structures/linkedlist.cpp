#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>

using namespace std;

class node
{
    public :
    node *next;
    int data;
    node()
    {
        next=NULL;
        data=0;
    }
};


class linkedlist
{
    public:
    node *head,*tail,*curr,*prev;
    linkedlist()
    {
        head=tail=NULL;
    }
    
    void insert(int n)
    {
        if (head==NULL)
        {
            head=new node;
            head->data=n;
            tail=head;
        }
        else
        {
            tail->next=new node;
            tail=tail->next;
            tail->data=n;
        }
    }
    
    void deletion(int n)
    {
        if (head->data==n)
            head=head->next;
        else
        {
            prev=head;
            curr=head->next;
            while(curr!=NULL)
            {
                if(curr->data==n)
                {
                    prev->next=curr->next;
                    if(curr==tail)
                        tail=prev;
                    break;
                }
                curr=curr->next;
                prev=prev->next;
            }
        }
    }
    
    void display()
    {
        if(head==NULL)
            cout<<"Nothing to display\n";
        else
        {
            curr=head;
            while(curr!=NULL)
            {
                cout<<curr->data<<" ";
                curr=curr->next;
            }
            cout<<"\n";
        }
    }
};


int main()
{
    string command;
    linkedlist a;
    int num;
    cin>>command;
    while(command!="end")
    {
        if (command=="i")
        {
            cin>>num;
            a.insert(num);
        }
        
        if (command=="d")
        {
            cin>>num;
            a.deletion(num);
        }
        
        if (command=="dis")
        {
            a.display();
        }
        
        cin>>command;
        
    }
    return 0;

}
            
            
            
                
        
            

            