#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1e6 + 10;
int ans[maxn];

int main(void)
{
	ans[0] = 7%3;
	ans[1] = 11%3;
	for(int i=2;i<maxn;i++) ans[i] = (ans[i - 1] + ans[i - 2]) % 3;
	int n;
	while(~scanf("%d",&n))
	{
		if(!ans[n]) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}