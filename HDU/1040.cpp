#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 10;
int s[maxn];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int length;
		scanf("%d",&length);
		for(int i=1;i<=length;i++) scanf("%d",s + i);
		sort(s + 1, s + length + 1);
		for(int i=1;i<=length;i++)
		{
			printf("%d",s[i]);
			if(i != length) printf(" ");
			else printf("\n");
		}
		//if(T) printf("\n");
	}
	return 0;
}