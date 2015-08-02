/***********************************************\
 |Author: YMC
 |Created Time: 2015/8/2 19:31:27
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
struct st {
    int l,r;
    int len;
    int t;
};
struct st2 {
    int l;
    int len;
};

list<st2> st2lst;

st tp;
st2 tp2;
int tans;
list<st> lst;
pair<int,int> ve[2005];
int vetot;
int n,m;
int len;
list<st>::iterator it;
list<st>::iterator it2;
list<st>::iterator itt;
st tst1, tst2;
int is_ava(int len) {
    if(m < len) return -2;
    if(lst.size() == 0) {
        if(m >= len) return 0;
        else return -2;
    }
    it = lst.begin();
    if(it->l >= len) return 0;
    if(lst.size() == 1) {
        if(m - 1 - (it->r) >= len) return it->r + 1;
        else return -1;
    }
    it2 = ++lst.begin();
    int tlen;
    while(it2 != lst.end()) {
        tlen = it2->l - it->r - 1;
        if(tlen >= len) return it->r + 1;
        it ++;
        it2 ++;
    }
    //printf("it == %d %d\n",it->r,len);
    if(m - it->r - 1 >= len) {
        return it->r + 1;
    } else return -1;
}
int inse(int len,int ii) {
    tans = is_ava(len);
    if(tans == -1) return -1;
    tp.l = tans;
    tp.r = tans + len - 1;
    tp.t = ii;
    tp.len = len;
    //add to tp2;
    tp2.l = tans;
    tp2.len = len;
    st2lst.push_back(tp2);

    //insert tp
    it = lst.begin();
    bool fg = false;
    while(it!=lst.end()) {
        if(it->l > tp.l) {
            lst.insert(it, tp);
            fg = true;
            break;
        }
        it ++;
    }
    if(!fg) {
        lst.push_back(tp);
    }
}
void remo() {
    int lll = st2lst.begin()->l;
    st2lst.erase(st2lst.begin());
    it = lst.begin();
    while(it != lst.end()) 
    {
        if(it -> l == lll) {
            lst.erase(it);
            break;
        }
        it ++;
    }
}
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.first < b.first;
}
void show() {
    vetot = 0;
    it = lst.begin();
    while(it != lst.end()) {
        //printf("%d %d\n",it->t + 1,it->l);
        ve[vetot ++] = MP(it->t + 1,it->l);
        it ++;
    }
    sort(ve,ve + vetot,cmp);
    rep(i,vetot) {
        printf("%d %d\n",ve[i].first,ve[i].second);
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&m) != EOF) {
        lst.clear();
        st2lst.clear();
        rep(ii,n) {
            scanf("%d",&len);
            tans = is_ava(len);
            if(tans == -2) continue;
            else if(tans != -1) {
                tp.l = tans;
                tp.r = tans + len - 1;
                tp.t = ii;
                tp.len = len;
                //add to tp2;
                tp2.l = tans;
                tp2.len = len;
                st2lst.push_back(tp2);

                //insert tp
                it = lst.begin();
                bool fg = false;
                while(it!=lst.end()) {
                    if(it->l > tp.l) {
                        lst.insert(it, tp);
                        fg = true;
                        break;
                    }
                    it ++;
                }
                if(!fg) {
                    lst.push_back(tp);
                }
            } else {
                //只能替换了
                remo();
                while(true) {
                    if(inse(len,ii) != -1) break;
                    else remo();
                }
            }
            //show();
            //puts("");
        }
        show();
    }
	return 0;
}

