#include <iostream>
#include <cstdio>

using namespace std;
#define inf 1e9

int length;
int n,c,t;
int vr,v1,v2;

double getTime(int b,int a)
{
	return a - b <= c ? (double)(a - b) / v1 : (double)c / v1 + (double)(a - b - c) / v2;
}

int main(void)
{
	while(cin>>length)
	{
		int s[105];
		cin>>n>>c>>t;
		cin>>vr>>v1>>v2;
		for(int i=1;i<=n;i++) scanf("%d",s + i);
		double time_tz = (double)length / vr;
		double dp[105];
		dp[0] = -t,s[0] = 0,s[n + 1] = length;
		for(int i=1;i<=n+1;i++)
		{
			dp[i] = 1.0*inf;
			for(int j=0;j<i;j++)
			{
				double get_time = getTime(s[j],s[i]);
				//cout<<get_time<<endl;
				dp[i] = dp[i] < t + dp[j] + get_time ? dp[i] : t + dp[j] + get_time;
			}
		}
		//cout<<time_tz<<' '<<dp[n+1]<<endl;
		printf(time_tz > dp[n + 1] ? "What a pity rabbit!\n" : "Good job,rabbit!\n" );
	}
	return 0;
}