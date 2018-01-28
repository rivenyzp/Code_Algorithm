#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

string muilt(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans;
	ans.resize(a.size()+b.size(),'0');
	for(int i=0;i<b.size();i++)
	{
		int flag = 0;
		for(int j=0;j<a.size();j++)
		{
			int temp = (a[j] - '0') * (b[i] - '0') + (ans[i + j] - '0') + flag;
			flag = temp / 10;
			ans[i + j] = temp % 10 + '0';
		}
		ans[i + a.size()] += flag;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

string get_ans(string str)
{
	string ans;
	if(str.size() > 3)
	{
		ans = str.substr(str.size() - 3,str.size());
	}
	else ans = str;
	return ans;
}

int main(void)
{
	int b;
	string a;
	while(cin>>a>>b && b)
	{
		string ans = a;
		for(int i=2;i<=b;i++)
		{
			ans = muilt(ans,a);
			//cout<<ans<<endl;
			ans = get_ans(ans);
			//cout<<ans<<endl;
		}
		bool flag = false;
		for(int i=0;i<3;i++)
		{
			if(!flag && ans[i] == '0') {continue;}
			else
			{
				cout<<ans[i];
				flag = true;
			}
		}
		if(!flag) cout<<'0';
		cout<<endl;
	}
	return 0;
}