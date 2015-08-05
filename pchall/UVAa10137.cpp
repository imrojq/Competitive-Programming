#include <stdio.h>
#include <iostream>
using namespace std;
void roundoff(double &n)
{
    double temp;
    temp=((int)(n*100))/100.0;
    
    if ((n-temp) >=(1/200.0)) temp+=0.01;
    n=temp;
    
}
int main()
{ 
    int n,i;
    double posdiff,negdiff,sum,avg;
    cin>>n;

    while (n!=0)
    {
        double costs[n];
        sum=0;
        posdiff=negdiff=0;
        for (i=0;i<n;i++)
        {
            cin>>costs[i];
            sum+=costs[i];
        }
        avg=sum/n;
        roundoff(avg);
        
        for(i=0;i<n;i++)
        {
            if (costs[i]<avg) negdiff+=(avg-costs[i]);
            else posdiff+=(costs[i]-avg);
        }
        if (posdiff<negdiff) printf("$%.2lf\n",posdiff);
        else printf("$%.2lf\n",negdiff);

        
        cin>>n;
        delete costs;
    }
    return 0;
}
        
          
