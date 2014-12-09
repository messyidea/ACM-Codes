/***********************************************\
 |Author: YMC
 |Created Time: 2014/2/27 16:12:34
 |File Name: noi 2004.cpp
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

using namespace std;
const int INF = 1<<20;
const int N = 100000;
int pre[N],key[N],ch[N][2],tot,root;
void addn(int& rt,int fa,int k){
    rt = ++root;
    pre[rt] = fa;
    key[rt] = k;
    ch[rt][0] = ch[rt][1] = 0;
}
void rotate(int x,int kind){
    int y = pre[z];int z = pre[y];
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if(z) ch[z][ch[z][1] == y] = x;
    pre[x] = z;
    ch[x][kind] = y;
    pre[y] = x;
}
void splay(int rt,int goal){
    int y,kind;
    while(pre[rt]!=goal){
        y = pre[rt];
        if(pre[y] == goal){
            rotate(rt,ch[y][0] == rt);
        }
        else{
            kind = ch[pre[y]][0] == y;
            if(ch[y][kind] == rt){
                rotate(rt,!kind);
                rotate(rt,kind);
            }
            else{
                rotate(y,kind);
                rotate(rt,kind);
            }
        }
    }
    if(goal == 0) root = rt;
}
int insert(int k){
    int rt = root;
    while(ch[rt][k > key[rt]]){
        if(key[rt] == k){
            splay(rt,0);
            return 0;
        }
        rt = ch[rt][k > key[rt]];
    }
    addn(ch[rt][k>key[rt]],rt,k);
    splay(ch[rt][k>key[rt]],0);
    return 1;
}
int getpre(int x){
    if(!ch[x][0]) return -INF;
    x = ch[x][0];
    while(ch[x][1]) x = ch[x][1];
    return x;
}
int getsuf(int x){
    if(!ch[x][1]) return INF;
    x = ch[x][1];
    while(ch[x][0]) x = ch[x][0];
    return x;
}
int main() {
	freopen("input.txt","r",stdin); 
    
	return 0;
}

