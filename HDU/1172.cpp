#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
struct node
{
	string str;
	int cnt_num,pos_num;
};

node s[105];
int n;
bool vis[4];

bool check(int num)
{
	char str_cmp[10];
	for(int i=3;i>=0;i--)
	{
		str_cmp[i] = num % 10 + '0';
		num /= 10;
	}
	str_cmp[4] = '\0';
	//cout<<str_cmp<<endl;
	for(int i=1;i<=n;i++)
	{
		int cnt = 0, pos = 0;
		memset(vis,0,sizeof vis);
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(s[i].str[j] == str_cmp[k] && !vis[k]) {cnt++, vis[k] = 1; break;}
			}
		}
		for(int j=0;j<4;j++) if(s[i].str[j] == str_cmp[j]) pos++;
		if(cnt != s[i].cnt_num || pos != s[i].pos_num) return false;
	}
	return true;
}

int main(void)
{
	while(~scanf("%d",&n) && n)
	{
		for(int i=1;i<=n;i++) cin>>s[i].str>>s[i].cnt_num>>s[i].pos_num;
		int cnt = 0;
		int num = 1000;
		int ans;
		while(num <= 9999)
		{
			if(!check(num)) num++;
			else cnt++,ans = num++;
			if(cnt > 1) break;
		}
		if(cnt != 1) printf("Not sure\n");
		else printf("%d\n", ans);
	}
	return 0;
}