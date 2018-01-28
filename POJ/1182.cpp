#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 50000 + 100;
int n,k;
int s[maxn * 3];

void init()
{
	for(int i=1;i<=n*3;i++) s[i] = i;
	return ;
}

int find_root(int number)
{
	return s[number] == number ? number : s[number] = find_root(s[number]);
}

void join(int x,int y)
{
	int xx = find_root(x);
	int yy = find_root(y);
	if(xx != yy) s[yy] = xx;
	return ;
}

int main(void)
{
	scanf("%d%d",&n,&k);
	int ans = 0;
	init();
	while(k--)
	{
		int is,x,y;
		scanf("%d%d%d",&is,&x,&y);
		if(x > n || y > n)
		{
			ans++;
			continue;
		}
		
		if(is == 1)
		{
			if(find_root(x) == find_root(y + n) || find_root(x) == find_root(y + 2 * n)) ans++;
			else
			{
				join(x,y);//表示同种类合并
				join(x + n,y + n);
				join(x + 2 * n, y + 2 * n);
			}
		}

		if(is == 2)
		{
			if(find_root(x) == find_root(y) || find_root(x) == find_root(y + 2 * n)) ans++;
			else
			{
				if(find_root(x) != find_root(y + n))
				{
					join(x, y + n);//表示吃y的和x是同种类
					join(x + n, y + 2 * n);//吃x的和被y吃的-->关键是这个，可以通过三个域之间的维护，即A>B,B>C,C>A得到三个域之间的关系，然后得到A和B之间的三个域之间的对应关系。
					join(x + 2 * n, y);//表示被x吃的和y是同种类
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}