#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(void)
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int ans = -1;
		bool flag = false;
		if(n > m) swap(n,m),flag = true;
		for(int i=n;i<=m;i++)
		{
			int x = i;
			int cnt = 1;
			while(x != 1)
			{
				if(x % 2) x = 3 * x + 1;
				else x = x >> 1;
				cnt++; 
			}
			ans = ans > cnt ? ans : cnt;
		}
		if(flag) swap(n,m);
		printf("%d %d %d\n", n, m, ans);
	}
	return 0;
}