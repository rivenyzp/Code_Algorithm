#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
bool s[26][26];
bool vis[26];

bool ouler(int num)
{
	if(num == 'm' - 'a') return true;
	vis[num] = 1;
	for(int i=0;i<26;i++)
	{
		if(!vis[i] && s[num][i]) if(ouler(i)) return true;
	}
	vis[num] = 0;
	return false;
}

int main(void)
{
	string str;
	while(cin>>str)
	{
		memset(s,0,sizeof s);
		s[str[0] - 'a'][str[str.size() - 1] - 'a'] = 1;
		while(cin>>str && str != "0")
		{
			s[str[0] - 'a'][str[str.size() - 1] - 'a'] = 1;
		}
		memset(vis,0,sizeof vis);
		if(ouler('b' - 'a')) cout<<"Yes."<<endl;
		else cout<<"No."<<endl;
	}
	return 0;
}