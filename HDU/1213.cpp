#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 1e3 + 50;
int n,length;
int s[maxn];

void init()
{
	for(int i=1;i<=n;i++) s[i] = i;
	return ;
}

int find_root(int number)
{
	return number == s[number] ? number : s[number] = find_root(s[number]);
}

bool join(int x,int y)
{
	int xx = find_root(x);
	int yy = find_root(y);
	if(xx != yy)
	{
		s[yy] = xx;
		return true;
	} 
	return false;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&length);
		int ans = 0;
		init();
		for(int i=1;i<=length;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(join(x,y)) ans++;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}