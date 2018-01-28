#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
string str;
string ctf = "ctf";
long long int sum;

int main(void)
{
	freopen("in.txt","r",stdin);
	sum = 0L;
	while(cin>>str)
	{
		for(int i=0;i<str.size() - 3;i++)
		{
			string temp = str.substr(i,i+3);
			if(temp == ctf)
			{
				sum += str.size();
				break;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}