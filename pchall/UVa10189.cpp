#include <stdio.h>
#include <iostream>

using namespace std;


#define forall(i,a,b)		for(int i= a;i<b;i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;


void display(vi vec)
{
	forall(i,0,vec.size())
		cout<<vec[i]<<" ";
	cout<<"\n";
}

void display2d(vvi vec)
{
	forall(i,0,vec.size())
		display(vec[i]);
}

vvi createNumMines(vvc &mineMap)
{
	int size1 = mineMap.size();
	int size2 = mineMap[0].size();
	vvi numMines(size1+2,vi(size2+2,0));
	forall(i,1,size1+1)
	{
		vc t = mineMap[i-1];
		forall(j,1,size2+1)
		{
			if (minMap[i-1][j-1] == '*')
			{
				forall(x,i-1,i+2)
                {
                    forall(y,j-1,j+2)
                        numMines[x][y]=numMines[x][y]+1;
                }
				numMines[i][j] =-1;
			}
		}
	}
	vvi newNum(size1,vi(size2,0));
	forall(i,1,size+1){
		forall(j,1,size+2)
			newNum[i-1][j-1] = numMines[i][j];
	}
	return newNum;
}

void flood(vvb &checked , vvi &numMines, int i ,int j,int size1,int size2)
{
	if (i<0 || i> size1 || j< 0 || j>size2 || checked[i][j])
		return;
	checked[i][j] = true;
	if (numMines[i][j] == 0){
		forall(x,i-1,i+2)
        {
            forall(y,j-1,j+2)
                flood(checked,numMines,x,y,size1,size2);
        }
	}
}

int count(vvi &numMines){
	int size1 = numMines.size();
	int size2 = numMines[0].size();
	vvb checked(size1, vb(size2,false);
	int count = 0;
	forall(i,0,size1){
		forall(j,0,size2){
			if(numMines[i][j] == 0 && !checked[i][j]){
				flood(checked,numMines,i,j,size1,size2);
				count++;
			}
		}
	}
	forall(i,0,size1){
		forall(j,0,size2)
			if(numMines[i][j] != 0 && !checked[i][j]) count++;
	}
	return count;
}
		
			

int main()
{
	int testCases,x,y,k;
	cin>>testCases;
	forall(i,0,testCases)
	{
		cin>>x;
		vvc mineMap(x,vc(x));
		forall(j,0,x){
			forall(k,0,x)
				cin>>mineMap[i][j];
		}
		display2d(createNumMines(mineMap);
    }
    return 0;
}
        
        
        
        
