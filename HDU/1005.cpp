#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

map<pair<int,int>, int>op;

int main(void)
{
	int a,b,n;
	//freopen("out.txt","r",stdin);
	//freopen("out_ans.txt","w",stdout);
	while(~scanf("%d%d%d",&a,&b,&n) && (a && b && n))
	{
		if(n == 1 || n == 2)
		{
			printf("1\n");
			continue;
		}
		op.clear();
		int cyc,num,num_pre = 1,num_pre_pre = 1,length;
		bool flag = true;
		for(int i=1;i < (n > 51 ? 51 : n) - 1;i++)
		{
			num = (a * num_pre + b * num_pre_pre) % 7;
			if(op[make_pair(num_pre_pre,num_pre)])
			{
				cyc = i - op[make_pair(num_pre_pre,num_pre)];
				n -= op[make_pair(num_pre_pre,num_pre)] + 1;
				flag = false;
				break;
			}
			else op[make_pair(num_pre_pre,num_pre)] = i;

			num_pre_pre = num_pre;
			num_pre = num;
		}
		if(!flag)
		{
			n %= cyc;
			for(int i=1;i<=n;i++)
			{
				num = (a * num_pre + b * num_pre_pre) % 7;
				num_pre_pre = num_pre;
				num_pre = num;
			}
		}
		
		printf("%d\n", num);
	}
	return 0;
}