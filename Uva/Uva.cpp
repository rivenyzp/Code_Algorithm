#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100 + 5;
int n;
const int max_cols = 60;
string str[maxn];

void print(const string &s, int length, char extra)
{
	cout<<s;
	for(int i = 0; i < length - s.length(); i++) cout<<extra;
}

int main(void)
{
	while(cin>>n)
	{
		int max_length = -1;
		for(int i = 0; i < n; i++)
		{
			cin>>str[i];
			max_length = max_length > str[i].length() ? max_length : str[i].length();
		}
		sort(str, str + n);
		int cols = (max_cols - max_length) / (max_length + 2) + 1;
		int rows = (n - 1) / cols + 1;
		print("", 60, '-');
		cout<<endl;
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < cols; c++)
			{
				int idx = c * rows + r;
				if(idx < n) print(str[idx], c == cols - 1 ? max_length : max_length + 2, ' ');
			}
			cout<<endl;
		}
	}
	return 0;
}