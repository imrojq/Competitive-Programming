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

void showlast(int n)
{
    node *forward,*backward;
    int i=0;
    forward=backward=head;
    for(int i=0;i<n;i++)
    {
        if(forward==NULL)
        {
            cout<<"Insufficient Elements \n ";
            return;
        }
        forward=forward->next;
    }
    while(forward!=NULL)
    {
        forward=forward->next;
        backward=backward->next;
    }
    cout<<"\n"<<backward->data;
}


int main()
{
    enter();
    display();
    int n;
    while (true)
    {
        cin>>n;
        showlast(n);
    }
    return 0;
}