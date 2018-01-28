#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 1e5 + 100;
int s[maxn];
int cnt[maxn];

int main(void)
{
	int T;
	scanf("%d",&T);
	int cur = 1;
	while(T--)
	{
		int length;
		scanf("%d",&length);
		for(int i=1;i<=length;i++) scanf("%d",s + i);
		int ans_left = 1,ans_right = 1,left = 1,right = 0,ans_maxn = s[1];
		cnt[1] = s[1],s[0] = 0;
		for(int i=1;i<=length;i++)
		{
			if(s[i] + cnt[right] >= 0)
			{
				cnt[i] = s[i] + cnt[right];
				right = i;
				if(cnt[right] > ans_maxn)
				{
					ans_left = left;
					ans_right = right;
					ans_maxn = cnt[right];
				}
				//printf("%d\n", cnt[right]);
			}
			else
			{
				while(s[i] < 0) 
				{
					if(s[i] > ans_maxn) 
					{
						ans_maxn = s[i];
						ans_left =  ans_right = i;
					}
					i++;
				}
				left = i;
				right = i;
				cnt[right] = s[right];
			}
		}
		printf("Case %d:\n", cur++);
		printf("%d %d %d\n", ans_maxn , ans_left , ans_right);
		if(T) printf("\n");
	}
	return 0;
}