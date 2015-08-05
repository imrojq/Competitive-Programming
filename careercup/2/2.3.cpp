#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

class node 
{
    public:
    char data;
    node *next;
    node(){next=NULL;}
    node(char n)
    {
        next=NULL;
        data=n;
    }
}*head;


void insert(char i)
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

node * search(char c)
{
    node *curr=head;
    while(curr!=NULL)
    {
        if(curr->data==c)
            return curr;
        curr=curr->next;
    
    }
    return NULL;
}
 
void deleteNode()
{   
    char c;
    cin>>c;
    node *a=search(c);
    a->data=a->next->data;
    a->next=a->next->next;
}
 
void enter()
{
  /*  int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        insert(num);
    }
    cout<<"\n";*/
    char c;
    while((cin>>c))
    {
        if(c=='0')
            break;
        insert(c);
        
    }
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

int main()
{
    string command;
    cin>>command;
    while(true)
    {
        if(command=="exit")
            break;
        else if (command=="display")
            display();
        else if (command=="enter")
            enter();
        else if (command=="delete")
            deleteNode();
        cin>>command;
    }
    return 0;
}