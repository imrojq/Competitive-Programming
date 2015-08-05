#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

class node 
{
    public:
    int data;
    node *next;
    node(){next=NULL;}
    node(int n)
    {
        next=NULL;
        data=n;
    }
}*head;


void insert(int i)
{
    if(head==NULL)
    {
    
        node *temp=new node(i);
        head=temp;
        
    }
        
    else
    {
        node *curr=head;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=new node(i);
    }
    
    //return head;
}
       
void enter()
{
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        insert(num);
    }
    cout<<"\n";
}
 
void display()
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
    cout<<"hi\n";
}

void removeDuplicate()
{
    map<int,int> mp;
    node *curr,*previous;
    curr=head;
    previous=NULL;
    while(curr!=NULL)
    {
        if(mp.find(curr->data)!=mp.end())
            previous->next=curr->next;
        else
        {
            previous=curr;
            mp[curr->data]=1;
        }
        curr=curr->next;
    }
}

void removeDuplicate1()
{
    node *curr,*prev,*curr1;
    curr=head;
    while(curr!=NULL)
    {
        curr1=head;
        prev=NULL;
        while(curr1!=curr)
        {
            if(curr1->data==curr->data)
            {
                if(curr1==head)
                    head=head->next;
                else
                    prev->next=curr1->next;
                break;
            }
            prev=curr1;
            curr1=curr1->next;
        }
        curr=curr->next;
    }
}
            
            

int main()
{
    head=NULL;
    enter();
    display();
    removeDuplicate1();
    display();
}