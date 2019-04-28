字节跳动后台开发暑期实习编程题
==
思路
--
# 母牛存活数量
   用数组a[9]保存1-10岁母牛的数量，每年更新不同年龄的母牛数量，新出生母牛数量为3-7岁母牛数量之和，即将a[2]至a[6]之和赋值给a[0],之后将数组中每项右移。
# 雀魂游戏胡牌条件

# 特工位置
[牛客网解答参考](https://www.nowcoder.com/discuss/184691) 作者：牛客609171号
   
    int solution(vector<int>& nums, int D) {
       if (nums.size() < 3) return 0;
       int mod = 99997867;
       int start = 0;
       long ans = 0;
    
       int i = 0;
       while(start < nums.size()) {
           while(i < nums.size() && nums[i] - nums[start] <= D) {
               i++;
           }
           int diff = i - start;
           if (diff < 3) {
               start++;
               continue;
           };
           diff--; // 选定区间第一个数后，在剩余的区间里面取两个
           ans = (ans + diff * (diff - 1) / 2) % mod;
           start++;
       }
       return ans;
    }


参考答案之后自己写了一遍
```
#include<iostream>
#include<vector>
using namespace std;
vector<int>coordinate;

int main()
{
	int n, d;
	int number, solution = 0, length;
	int mod = 99997867;

	cin >> n >> d;

	for (int i = 0; i < n; i++)
	{
		cin >> number;
		coordinate.push_back(number);
	}

	for (int i = 0; i < n-2; i++)
	{
		int one, three;
		one = coordinate[i];
		int j = i + 1;
		do{			
			j++;
		}while (j<n && coordinate[j] - one <= d);
		j--;		
		length = j - i + 1;

		if (length<3)
			continue;
		else
		{
			length--;
			solution = (solution + length*(length - 1) / 2) % mod;
		}		
	}

	cout << solution << endl;
	system("pause");
	return 0;
}
```

自己机试的时候把问题复杂化了，尝试用二分法找最大的第三个位置，在计算区间内埋伏方案数量时用的C（n,3）（错误），应为C（n,2），因第一个区间此时已确定。

```
//原解答内存超出。算法复杂度过大
#include<iostream>
#include<vector>
using namespace std;
vector<int>coordinate;

int findMaxThree(int one ,int d,int first,int end)
{
	int pos,middlePos=(first+end)/2;
	if (coordinate[middlePos] == one + d)
	{
		return middlePos;
	}
	else if (coordinate[middlePos] < one + d)
	{
		if (coordinate[middlePos + 1]>one + d)
			return middlePos;
		else pos = findMaxThree(one, d, middlePos / 2,end);
	}
	else if(coordinate[middlePos] > one + d)
	{
		if (coordinate[middlePos - 1]<one + d)
			return middlePos - 1;
		else pos = findMaxThree(one, d, first,middlePos / 2);

	}
	return pos;
}

int main()
{
	   int n, d;
	   int number, solution = 0;
	   cin >> n >> d;
	
		for (int i = 0; i < n; i++)
		{
			cin >> number;
			coordinate.push_back(number);
		}

		for (int i = 0; i < n; i++)
		{		
			int one, two, three;
			one = coordinate[i];
			int pos = findMaxThree(one, d,i,n);	//可直接遍历，找到满足条件（pos3-pos1<=D）的第三个点的位置i。
			if (pos >= 3)
			{
				int length = pos - i + 1;
				solution += solution + length*(length - 1)*(length - 2) / 6;	
            //这里错了，第一个位置确定后，应该从剩下区间选两个数
            //solution += length*(length - 1)/ 2;	
			}				
		}	
	cout << solution << endl;		
	system("pause");
	return 0;
}
```

# 数列最长全1区间
[Leetcode原题](https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91271/Java-12-lines-O(n)-sliding-window-solution-with-explanation)

题目：有k次0变1机会

思路：sliding window

和剑指offer48:最长不含重复字符的子字符串 思路有类似


