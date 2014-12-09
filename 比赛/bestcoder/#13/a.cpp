/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/11 19:04:12
 |File Name: a.cpp
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
#include <sstream>
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
bool can(string s) {
    for(int i=0;i<s.length();++i) {
        if(s[i] != s[s.length() - i - 1])  return false;
    }
    for(int i=1;i<(s.length() + 1)/2;++i) {
        if(s[i] <= s[i-1]) return false;
    }
    return true;
}
int solve(int u) {
    int ans = 0;
    string s;
    for(int i=1;i<=u;++i) {
        int t = i;
        stringstream ss;
        ss << i;
        ss >> s;
        if(can(s)) ans ++;
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    cout<<solve(10)<<endl;
    cout<<solve(100)<<endl;
    cout<<solve(1000)<<endl;
    cout<<solve(10000)<<endl;
    cout<<solve(100000)<<endl;

    cout<<solve(1000000)<<endl;
	return 0;
}

