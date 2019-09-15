网易雷火2019秋招笔试
===

4 
---

题目:
```
输入：正整数 1<=n<=1000000000
输出：结果保留6位小数
对<=n中的每个数，计算 f=以n为分子的最简分数个数/n，求fmin。
```
解析： 用欧拉函数
```
test case:
1 1.000000
2
6 0.333333
30-209 0.266667
210-2309 0.228571   
2310-30000  0.207792
33000-50000 0.191808
```
①原本的思路，时间复杂度过大 ac 50%
      
      int zuijianElement(int num,double fmin){
        if(num==2) 
          return 1;
        vector<int> sub;
        unordered_set<int> notzuijian; //保存<num且和num有公约数的数字
        int count=num;
        //int count=num-1;

        //求因子
        if(num%2==0)
          sub.push_back(2);
        for (int i = 3; i <num ; i+=2){
          bool exist=false;
          if(num%i==0)
              sub.push_back(i);	
        } 

        for (int i = 0; i < (int)sub.size(); ++i)
        {
          if(sub[i]==2) {	//num为偶数时
            count-=(num-1)/2;
            continue;
          }
          int yinzi=sub[i];
          for (int j = 1; yinzi*j<=num && j < num; j+=2)
            notzuijian.insert(yinzi*j);
        }
        count-=(int)notzuijian.size();
        return count;
      }
      
②用欧拉函数公式

        #include<bits/stdc++.h>
        using namespace std;

        int zuijianElement(int num,double fmin){
          if(num==2) 
            return 1;
          vector<int> sub;
          unordered_set<int> notzuijian; //保存<num且和num有公约数的数字
          int count=num;
          //int count=num-1;

          //求因子  需为质因数，3 9则重复！！
          if(num%2==0)
            sub.push_back(2);
          for (int i = 3; i <num ; i+=2){
            bool exist=false;
            if(num%i==0){
              for (int j = 0; j < (int)sub.size(); ++j)
              {
                if(i%sub[j]==0){
                  exist=true;
                  break;
                }
              }
              if(!exist)
                sub.push_back(i);	
            }
          } 

          for (int i = 0; i < (int)sub.size(); ++i)
            count=(count-count/sub[i]);
          return count;
        }

        int main()
        {
          int n;
          cin>>n;

          double fmin=1.0;
          for (int i = 2; i <= n; ++i)
          {
            int nums=zuijianElement(i,fmin);
            fmin=min(fmin,double(nums*1.0/i));
          }

          printf("%6f\n",fmin);
          return 0;
        }
