#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

#define forall(i,a,b)                   for(int i=a;i<b;i++)

using namespace std;

int main()
{
    string s1="1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    string s2="`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    char c;
    map<char,char> conversion_table;
    forall(i,0,s1.length())
        conversion_table[s1[i]]=s2[i];
	while (scanf("%c", &c) != EOF) {
    if (conversion_table.find(c)==conversion_table.end())
        printf("%c", c);
    else
		printf("%c", conversion_table[c]);
	}
    return 0;
}
        
        