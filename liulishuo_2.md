```
//爬台阶，非递归方法
#include<bits/stdc++.h>
using namespace std;

long long climb(int n)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	long long one=1,two=2,cur;
	for(int i=3;i<=n;i++)
	{
		cur=one+two;
		one=two;
		two=cur;
	}
	return cur;
}

int main()
{
	int n;
	cin>>n;
	cout<<climb(n)<<endl;
	return 0;
}
```
