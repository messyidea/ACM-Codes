/***********************************************\
 |Author: YMC
 |Created Time: 2015/9/17 19:41:52
 |File Name: b.cpp
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
string s;
int now, tt;
vector<int> ve;
int getnum(int& pos) {
   int i;
   int num = 0;
   for(i = pos; i < s.length(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        } else break;
   }
   pos = i; 
   return num;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(cin>>s) {
        ve.clear();
        int len = s.length();
        int pos = 0;
        now = 1;
        if(s[pos] == '-') {
            now = -1;
            pos ++;
        }
        tt = getnum(pos);
        now *= tt;
        while(pos < len && (s[pos] == '*' || s[pos] == '/')) {
            pos ++;
            if(s[pos-1] == '*') {
                now = getnum(pos) * now;
            } else {
                now = now / getnum(pos);
            }
        }
        ve.push_back(now);
        while(pos < len) {
            now = 1;
            if(s[pos] == '-') {
                now = -1;
            }
            pos ++;
            tt = getnum(pos);
            now *= tt;

            while(pos < len && (s[pos] == '*' || s[pos] == '/')) {
                pos ++;
                if(s[pos-1] == '*') {
                    now = getnum(pos) * now;
                } else {
                    now = now / getnum(pos);
                }
            }
            ve.push_back(now);
        }
        int sum = 0;
        rep(i, ve.size()) {
            sum += ve[i];
        }
        cout<<sum<<endl;
    }
	return 0;
}

