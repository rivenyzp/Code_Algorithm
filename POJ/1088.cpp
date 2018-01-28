#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int s[105][105];
bool vis[105][105];
int cnt[105][105];
int r,c;
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};

void init()
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			cnt[i][j] = 1;
	}
	return ;
}

bool check(int x,int y)
{
	if(x < 1 || x > r || y < 1 || y > c ) return false;
	else return true;
}

int dp(int x,int y)
{
	if(vis[x][y]) return cnt[x][y];
	for(int i=0;i<4;i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(s[xx][yy] < s[x][y] && check(xx,yy))
		{
			if(vis[xx][yy]) cnt[x][y] = cnt[xx][yy] + 1 > cnt[x][y] ? cnt[xx][yy] + 1 : cnt[x][y];
			else cnt[x][y] = dp(xx,yy) + 1 > cnt[x][y] ? cnt[xx][yy] + 1 : cnt[x][y];
		} 

	}
	vis[x][y] = 1;
	return cnt[x][y];
}

int main(void)
{
	while(~scanf("%d%d",&r,&c))
	{
		init();

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				scanf("%d",&s[i][j]);
			}
		}

		int ans = -1;

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if(!vis[i][j])
				{
					cnt[i][j] = dp(i,j);
					vis[i][j] = 1;
					if(cnt[i][j] > ans) ans = cnt[i][j];
				}
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}