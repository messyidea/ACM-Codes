
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <stack>  
#include <queue>  
#define LL long long  
using namespace std;  
const int maxn = 200000 + 5;  
  
int n;  
LL num[maxn];  
int vis[maxn][2];  
LL go[maxn][2];  
  
LL find(int x,int kind){  
    if(go[x][kind]) return go[x][kind];  
    if(vis[x][kind] == 1) {  
        return go[x][kind] = -1;  
    }  
    vis[x][kind] = 1;  
    if(kind == 1 && x + num[x] > n){  
        return go[x][kind] = num[x];  
    }  
    else if(kind == 0 && x-num[x] <= 0){  
        return go[x][kind] = num[x];  
    }  
    LL tem = find(x+(kind==1?num[x]:-num[x]),(kind+1)%2);//分kind讨论，1代表当前为操作1，0代表操作2  
    if(tem != -1)  
        return go[x][kind] = tem + num[x];  
    else return go[x][kind] = -1;  
}  
  
int main(){
    freopen("input.txt","r",stdin);  
    while(cin >> n){  
        memset(vis,0,sizeof(vis));  
        memset(go,0,sizeof(go));  
        for(int i = 2;i <= n;i++) cin >> num[i];  
        num[1] = 1;
        LL x,y;  
        for(int i = 2;i <= n;i++){  
            y = i-1;  
            LL tem = find(i,0);
            //cout<<tem<<endl;
          //cout<<num[1]<<endl;  
            if(tem == -1){  
                cout << -1 << endl;  
                continue;  
            }  
            y += tem;  
            cout << y << endl;  
        }  
    }  
    return 0;  
}  
