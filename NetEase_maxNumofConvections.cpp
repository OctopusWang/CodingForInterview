//Q1：Maximum number of conventions
//求a,b的最大公约数。a,b为大数，0<a<10^(10^5),0<b<10^18
//Algorithm: 欧几里得算法（辗转相除法）

//Q2：Cambricon寒武纪笔试 a最多有9999位，b最多有10位，要求输出余数和最大公约数。

#include<bits/stdc++.h>
using namespace std;
char s[100005];
long long gcd(long long a,long long b)
{
    return a % b == 0 ?b : gcd(b , a % b) ;
}
int main()
{
    scanf("%s",s+1) ;//从s[1]开始输入
    
    long long a ; cin >> a;
    long long b = 0;
    for(int i = 1;s[i] != '\0';i++) {
        b = (b * 10 + s[i] - '0') % a;	//大数的处理：逐位取余，最终得到的余数小于a，用long long表示可以。
    }	

    cout << gcd(a,b);
    return 0;
}
