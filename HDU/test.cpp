#include <iostream>
#include <cstdio>
#include <time.h>
#include <cstdlib>

using namespace std;
const int maxn = 1e9 - 1;

int tran(int x)
{
	return x >= 0 ? x : -x;
}

/*
int main(void)
{
	int a,b,n;
	//freopen("out.txt","r",stdin);
	//freopen("out_ans_right.txt","w",stdout);
	//srand((unsigned)time(NULL));
		//a = tran(1 + (int)rand() % 999);
		//b = tran(1 + (int)rand() % 999);
		//n = tran(1 + (int)rand() % (maxn));
	while(~scanf("%d%d%d",&a,&b,&n) && (a + b + n))
	{
		int num_pre_pre = 1, num_pre = 1, num;
		for(int i=2;i<n;i++)
		{
			num = (a * num_pre + b * num_pre_pre) % 7;
			num_pre_pre = num_pre;
			num_pre = num;
		}

		printf("%d\n", num);
	}
		
		
	return 0;
}*/

int s[105],s_g[105];
int main(void)
{
	freopen("out_ans.txt","r",stdin);
	for(int i=1;i<=100;i++) scanf("%d",s +i);
	freopen("out_ans_right.txt","r",stdin);
	for(int i=1;i<=100;i++) scanf("%d",s_g + i);
	for(int i=1;i<=100;i++)
	{
		if(s[i] != s_g[i])
		{
			printf("%d %d %d\n",i, s[i],s_g[i]);
		}
	}
	return 0;
}