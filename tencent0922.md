1
---

```
题目：
输入：一串仅包含数字的字符串
删除0次或多次后能否得到企鹅电话号码。
输出：“YES”或者“NO”
```
```
//100%

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	vector<int> len(t);
	vector<string> str(t);
	for (int i = 0; i < t; ++i)
	{	
		cin>>len[i];
		getchar();
		getline(cin,str[i]);		
	}

	for (int i = 0; i < t; ++i)
	{
		if(len[i]<11)
			cout<<"NO"<<endl;
		else{
			int first8=str[i].find_first_of("8");
			//cout<<"find at: "<<first8<<endl;
			if(first8<len[i]&& first8>=0 && len[i]-first8>=11)
				cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}

	return 0;
}
```

2
---

```
题目：
刷房子，红绿蓝
输入：房子个数n,及n个房子的分别刷红绿蓝颜料的用料量。这n个房子没有首尾相连。
输出：求最少用料
```

```
//100%  

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> red,green,blue;
int min_sum;

void add(int color_index,int house_index,int sum)
{
	if(house_index==n){
		if(sum<min_sum)
			min_sum=sum;
		return;
	}
	if(color_index==0){
		add(1,house_index+1,sum+green[house_index]);
		add(2,house_index+1,sum+blue[house_index]);
	}
	if(color_index==1){
		add(0,house_index+1,sum+red[house_index]);
		add(2,house_index+1,sum+blue[house_index]);
	}
	if(color_index==2){
		add(0,house_index+1,sum+red[house_index]);
		add(1,house_index+1,sum+green[house_index]);
	}	



}

int main()
{	
	cin>>n;
	min_sum=1000*n;
	for (int i = 0; i < n; ++i){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		red.push_back(t1);
		green.push_back(t2);
		blue.push_back(t3);
	}
	int sum=0;
	add(0,0,sum);
	add(1,0,sum);
	add(2,0,sum);
	cout<<min_sum<<endl;
	return 0;
}
```

3
---

···
//100%

#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	vector<int> vec(n),first,second;

	for (int i = 0; i < n; ++i)
		cin>>vec[i];

	sort(vec.begin(),vec.end());
	for (int i = 0; i < n; ++i){
		if(i%2)
			second.push_back(vec[i]);
		else first.push_back(vec[i]);
	}

	sort(second.begin(),second.end(),greater<int>());
	vec.assign(first.begin(),first.end());
	vec.insert(vec.end(),second.begin(),second.end());

	for(int a:first)
		cout<<a<<" ";
	cout<<endl;
	for(int a:second)
		cout<<a<<" ";
	cout<<endl;

	for (int i = 0; i < n-1; ++i)
		cout<<vec[i]<<" ";
	
	cout<<vec[n-1];
	return 0;
}
···
