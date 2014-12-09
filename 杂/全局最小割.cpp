
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

#define MAX_V 500

int M[MAX_V][MAX_V],w[MAX_V];
bool A[MAX_V],merged[MAX_V];

int minCut(int n){
    int best = INT_MAX;
    for(int i=1;i<n;++i) merged[i] = false;
    merged[0] = true;
    
    for(int phase=1;phase<n;++phase){
        A[0] = true;
        
        for(int i=1;i<n;++i){
            if(merged[i]) continue;
            A[i] = false;   //代表还没有被合并。
            w[i] = M[0][i];     //更新源块到点i的最大距离。
        }
        
        int prev = 0,next;
        
        for(int i=n-1-phase;i>=0;--i){
            // hallar siguiente vértice que no esté en A
            next = -1;
            
            for(int j=1;j<n;++j)
                if(!A[j] && (next==-1 || w[j]>w[next])) //取得最大的距离
                    next = j;
            
            A[next] = true;
            
            if(i>0){
                prev = next;
                
                // actualiza los pesos
                for(int j=1;j<n;++j)
                    if(!A[j]) w[j] += M[next][j];
            }
        }
        
        if(best>w[next]) best = w[next];
        
        // mezcla s y t
        for(int i=0;i<n;++i){
            M[i][prev] += M[next][i];
            M[prev][i] += M[next][i];
        }
        
        merged[next] = true;
    }
    
    return best;
}

int main(){
    int T,n,m,u,v,c;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&n,&m);
        
        memset(M,0,sizeof(M));
        
        for(int i=0;i<m;++i){
            scanf("%d %d %d",&u,&v,&c);
            --u; --v;
            M[u][v] += c;
            M[v][u] += c;
        }
        
        printf("Case #%d: %d\n",tc,minCut(n));
    }
    
    return 0;
}
