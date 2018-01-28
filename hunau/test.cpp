#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int mid,n,leftt,rightt,ans;
int s[105][105];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
bool flag;
bool vis[105][105];

bool check(int x,int y,int mi,int mx)
{
	if(x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y] && mx - mi <= mid) return true;
	else return false;
}

void dfs(int x,int y,int mi,int mx)
{
	if(x == n && y == n && mx - mi <= mid) 
	{
		if(mx == mi) ans = 0;
		flag = true;
		return;
	}
	if(flag) return;
	for(int i=0;i<4;i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		int minn = mi > s[xx][yy] ? s[xx][yy] : mi;
		int maxn = mx < s[xx][yy] ? s[xx][yy] : mx;
		if(flag) return;
		if(check(xx,yy,minn,maxn)) {vis[xx][yy] = true; dfs(xx,yy,minn,maxn);}
	}
	return;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			scanf("%d",&s[i][j]);
	leftt = 0,rightt = 120;
	while(rightt - leftt > 1)
	{
		mid = (rightt + leftt)>>1;
		cout<<rightt<<' '<<leftt<<' '<<mid<<endl;
		flag = false;
		memset(vis,false,sizeof vis);
		dfs(1,1,s[1][1],s[1][1]);
		cout<<flag<<endl;
		if(flag) rightt = mid;
		else leftt = mid;
	}
	if(!ans) ans = mid;
	printf("%d",ans);
	return 0;
}