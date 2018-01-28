#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int maix[15][15];

int main(void)
{
	int r,c;
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++) scanf("%d",&maix[i][j]);
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++) swap(maix[i][j],maix[j][i]);
	}
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=r;j++)
		{
			printf("%d", maix[i][j]);
			if(j != r) printf(" ");
		}
		if(i != c) printf("\n");
	}
	return 0;
}