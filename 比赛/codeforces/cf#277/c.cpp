/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/11 23:54:13
 |File Name: c.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n,p;
char s[100005];
int num[100005];
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d %d",&n,&p);
    p --;
    scanf("%s",s);
    int t = n/2;
    int sum = 0;
    for(int i=0;i<t;++i) {
        num[i] = abs(s[i] - s[n-i-1]);
        num[i] = min(26-num[i],num[i]);
        num[n-i-1] = num[i];
        sum += num[i];
    }
    int p1 = 0,p2 = n-1;
    while(num[p1] == 0 && p1 <= n) p1 ++;
    while(num[p2] == 0 && p2 >= 0) p2 --;
    if(p1 > p2) {
        puts("0");
        return 0;
    }
    int mid = n / 2;
    int mid1 = mid;
    while(num[mid1] == 0 && mid1 <= n) mid1 ++;
    int mid2 = n - mid1 - 1;
    int ans1 = 0,ans2 = 0,ans3 = 0,ans = 0;
    //cout<<mid2<<"  "<<mid1<<endl;
    if(p <= p1) {
        ans = sum + mid2 - p;
        cout<<ans<<endl;
        return 0;
    }
    if(p >= p2) {
        ans = sum + p - mid1;
        cout<<ans<<endl;
        return 0;
    }
    if(p >= mid2 && p <= mid1) {
        ans1 = sum + p2 - p;
        ans2 = sum + p - p1;
        ans = min(ans1,ans2);
        cout<<ans<<endl;
        return 0;
    }
    if(p >= mid) {
        ans1 = sum + p - p1;
        ans2 = sum + (p - mid1) + (p2 - mid1);
        ans3 = sum + (p2 - p) + (p2 - mid1);
    } else {
        ans1 = sum + p2 - p;
        ans2 = sum + (mid2 - p1) + (mid2 - p);
        ans3 = sum + (mid2 - p1) + (p - p1);
    }
    //cout<<ans1<<"  "<<ans2<<"  "<<ans3<<endl;
    ans = min(ans1,ans2);
    ans = min(ans,ans3);
    //cout<<"sum == "<<sum<<endl;
    cout<<ans<<endl;

	return 0;
}

