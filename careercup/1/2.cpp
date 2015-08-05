#include <iostream>
#include <stdio.h>
// #include <string.h>
using namespace std;

void reverseString(char *str)
{
    char *end=str;
    char temp;
    if(str==NULL)
        return ;
    while(*end)
        end++;
    end--;
    while(str<end)
    {
        temp=(*str);
        *str=*end;
        *end=temp;
         end--;
         str++;
    }
}
    
        
        

int main()
{
    char string[20];
    scanf("%s",&string);
    reverseString(string);
    printf("%s",string);
 }