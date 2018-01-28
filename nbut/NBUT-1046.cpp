#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int s[50 + 5];

void print_ans(int length)
{
	for(int i=1;i<=length;i++)
	{
		printf("%d", s[i]);
		if(i != length) printf(" ");
		else printf("\n");
	}
	return ;
}

void dfs(int pos,int maxn,int num,int cnt)
{
	if(cnt == num)
	{
		print_ans(pos);
		return ;
	}
	for(int i=maxn;i<=num - cnt;i++)
	{
		if(i + cnt <= num) 
		{	
			s[pos + 1] = i;
			dfs(pos + 1, i, num, i + cnt);
		}
		else return ;
	}
	return ;
}

int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n/2;i++) {s[1] = i; dfs(1, i, n, i);}
		printf("%d\n", n);
	}
	return 0;
}