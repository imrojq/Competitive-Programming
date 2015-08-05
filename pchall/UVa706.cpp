#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAXLEN 999999


using namespace std;



int main()
{
    const char conversion_table[10][7]={
        {'-','|','|',' ','|','|','-'} ,       //for 0
        {' ',' ','|',' ',' ','|',' '} ,      //for 1
        {'-',' ','|','-','|',' ','-'},       //for 2
        {'-',' ','|','-',' ','|','-'},       //for 3
        {' ','|','|','-',' ','|',' '},       //for 4
        {'-','|',' ','-',' ','|','-'},       //for 5
        {'-','|',' ','-','|','|','-'},       //for 6
        {'-',' ','|',' ',' ','|',' '},       //for 7
        {'-','|','|','-','|','|','-'},       //for 8
        {'-','|','|','-',' ','|','-'}        //for 9
        
        
        };
    int i,j,pos,width,s,digit,index=0;
    bool row_present,col_present;
    char number[MAXLEN];
    while (1)
    {     
        index=0;
        scanf("%d",&s);
        scanf("%s",&number);
        width=(s+3)*strlen(number);
        if (s==0)
        return 0;
        
        
        for (i=0;i<(2*s)+3;i++)
        {
            col_present=(i==0 || i==(s+1) || i==(2*s + 2) );
            for (j=0;j<width-1;j++)
            {   
                pos=j%(s+3);
                row_present=(pos==0 || pos==(s+1) );
                if ((row_present ^ col_present) && pos !=(s+2))
                {
                    digit =(int)number[(j)/(s+3)];
                    digit-=48;
                   //cout<<i<<index;
                    putchar(conversion_table[digit][index]);
                    if (index==2 || index==5)
                        index--;
                    else if (index==1 || index==4)
                        index++;                 
                }
                else 
                    putchar(' ');  
             }
             if ((index==1 || index==4 ) && (i==s || i==(2*s+1)))

                    index+=2;
             else if (index!=1 && index!=4)
                    index++;             
             cout<<"\n";
        }
        cout<<"\n";

    }

        
        
        
        
        
        
        
        
        
    
}
           
        
        
     
        
            
