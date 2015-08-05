#include <stdio.h>
#include <iostream>

using namespace std;

class image
{
    public :
    int columns,rows;
    char filename[20];
    char grid[255][255];
    bool explored[255][255];
    void unexplore()
    {
     int i,j;
     for(i=1;i<=250;i++)
     {
        for(j=1;j<=250;j++)
            explored[i][j]=0;
     }
     }

    void clear()
    {
        int i,j;
        for (i=1;i<=columns;i++)
        {
            for(j=1;j<=rows;j++) 
                grid[i][j]='0';
        }
    }
    void color_point(int x ,int y,char c)
    {
        grid[x][y]=c;
    }
    void horizontal_segment(int row,int col1,int col2,char c)
    {
        int i,j;
        j=row;
        for (i=col1;i<=col2;i++)
            grid[i][j]=c;
    }
    void vertical_segment(int column,int row1,int row2,char c)
    {
        int i,j;
        i=column;
        for (j=row1;j<=row2;j++)
            grid[i][j]=c;
    }
    void fill_rectangle(int x1,int y1,int x2,int y2,char c)
    {
        int i,j;
        for (i=x1;i<=x2;i++)
        {
            for(j=y1;j<=y2;j++)
                grid[i][j]=c;
        }
    }
    
    void fill_region(int x, int y ,char c)
    {
        char color=grid[x][y];
        if (color==c)
            return ;
        grid[x][y]=c;
        explored[x][y]=1;
        if (x+1<=columns && grid[x+1][y]==color && !explored[x+1][y])
            fill_region(x+1,y,c);
        if (x-1>=1 && grid[x-1][y]==color && !explored[x-1][y])
            fill_region(x-1,y,c);
        if (y+1<=rows && grid[x][y+1]==color && !explored[x][y+1])
            fill_region(x,y+1,c);
        if (y-1>=1 && grid[x][y-1]==color && !explored[x][y-1])
            fill_region(x,y-1,c);
    }
    
    void display()
    {
        int i,j;
        for (j=1;j<=rows;j++)
        {
            for(i=1;i<=columns;i++)
                putchar(grid[i][j]);
            cout<<"\n";
        }
    }
 };
 
 
 int main()
 {
    char c,color;
    char filename[1000];
    image object;
    int m,n,x,y,x1,y1,x2,y2;
    while (1)
    {
        scanf("%c",&c);
        if (c=='I')
        {   
            scanf("%d%d",&m,&n);
            object.columns=m;
            object.rows=n;
            object.clear();
        }
        else if (c=='C')
             object.clear();
        else if (c=='L')
        {
            scanf("%d%d",&x,&y);
            cin>>color;
            object.color_point(x,y,color);
        }
        else if (c=='V')
        {
            scanf("%d%d%d",&x,&y1,&y2);
            cin>>color;
            if (y1<y2)
                object.vertical_segment(x,y1,y2,color);
            else
                object.vertical_segment(x,y2,y1,color);
        }
        else if (c=='H')
        {
            scanf("%d%d%d",&x1,&x2,&y);
            cin>>color;
            if (x1<x2)
                object.horizontal_segment(y,x1,x2,color);
            else
                object.horizontal_segment(y,x2,x1,color);
                
        }
        else if (c=='K')
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            cin>>color;
            object.fill_rectangle(x1,y1,x2,y2,color);
        }
        else if (c=='F')
        {
            scanf("%d%d",&x,&y);
            cin>>color;
            object.fill_region(x,y,color);
            object.unexplore();
        }
        else if (c=='S')
        {
            scanf("%s",&filename);
            printf("%s",filename);
            cout<<endl;
            object.display();
        }
        else if (c=='X')
        {
            return 0;
        }
        
    }
    }
            
            
        
            
        
        
