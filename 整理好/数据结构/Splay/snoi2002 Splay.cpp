/***********************************************\
 |Author: YMC
 |Created Time: 2014/2/22 21:45:36
 |File Name: snoi2002 Splay.cpp
 |Description: Splay 模板
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

using namespace std;
const int INF = 1<<20;
const int N = 100005;
int pre[N],key[N],ch[N][2],root,tot;
int n;
void addn(int &rt,int fa,int k){            //根为1，根的父亲节点为0，便于记录。
    rt = ++tot;
    pre[rt] = fa;
    key[rt] = k;
    ch[rt][0] = ch[rt][1] = 0;          //左右孩子为空
}
void rotate(int x,int kind){           //kind为0，左旋；kind为1，右旋
    int y = pre[x],z = pre[y];
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if(z) ch[z][ch[z][1] == y] = x;
    pre[x] = z;
    ch[x][kind] = y;
    pre[y] = x;
}
void splay(int rt,int goal){
    int y,kind;
    while(pre[rt] != goal){
        y = pre[rt];
        if(pre[y] == goal){
            rotate(rt,ch[y][0] == rt);        
        }
        else{
            kind = ch[pre[y]][0] == y;          //理解，是两个等号，为了判断左右转
            if(ch[y][kind] == rt){              //两次旋转方向不一样
                rotate(rt,!kind);
                rotate(rt,kind);
            }
            else{                               //两次旋转方向一样
                rotate(y,kind);
                rotate(rt,kind);
            } 
        }
    }
    if(goal == 0) root = rt;
}
int insert(int k){
    int rt = root;
    while(ch[rt][k>key[rt]]){
        if(key[rt] == k){
            splay(rt,0);
            return 0;
        }
        rt = ch[rt][k>key[rt]];
    }
    addn(ch[rt][k>key[rt]],rt,k);
    splay(ch[rt][k>key[rt]],0);             //新插入的节点更新至根节点
    return 1;
}
int getpre(int x){                          //找前驱
    if(!ch[x][0]) return -INF;
    x = ch[x][0];
    while(ch[x][1]) x = ch[x][1];           //注意，这边return的是key
    return key[x];
}
int getsuf(int x){                          //找后继
    if(!ch[x][1]) return INF;
    x = ch[x][1];
    while(ch[x][0]) x = ch[x][0];
    return key[x];
}
int main() {
	freopen("input.txt","r",stdin); 
    int i,m,ans;
    while(scanf("%d",&n)!=EOF){
        ans = root = tot = 0;
        for(int i=0;i<n;++i){
            scanf("%d",&m);
            if(i == 0){
                ans += m;
                addn(root,0,m);
            }
            else{
                if(insert(m) == 0) continue;
                ans += min(m-getpre(root),getsuf(root)-m);
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}

