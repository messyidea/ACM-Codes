
#include<stdio.h>  
#include<math.h>  
#include<iostream> 
#include <string.h>
#define eps 1e-7  
using namespace std;  
double a[110][110],as[110];  
int n,u[110],v[110];  
bool l[110];  
int aa[100];
int gauss(){  
    int i,j,k,r=0;  
    double tmp;  
    for(i=0;i<n;i++)  
        l[i]=0;  
    for(i=0;i<n;i++){  
        for(j=r;j<n;j++)  
            if(fabs(a[j][i])>eps){  
                for(k=i;k<=n;k++)  
                    swap(a[j][k],a[r][k]);  
                break;  
            }  
        if(fabs(a[r][i])<eps)continue;  
        for(j=0;j<n;j++)  
            if(j!=r&&fabs(a[j][i])>eps){  
                tmp=a[j][i]/a[r][i];  
                for(k=i;k<=n;k++)  
                    a[j][k]-=tmp*a[r][k];  
            }  
        l[i]=1;r++;  
    }  
    for(i=0;i<n;i++)if(l[i])  
        for(j=0;j<n;j++)  
            if(fabs(a[j][i])>eps)  
                as[i]=a[j][n]/a[j][i];  
    for(i=r;i<n;i++)if(fabs(a[i][n])>eps)return -1;  
    return 1<<n-r;  
} 
char sss[100];
int main(){  
    freopen("input.txt","r",stdin);
    int i,j,x,y,cs;  
    scanf("%d",&cs); 
     
    while(cs--){    
        n = 3*4*5;
        for(i=0;i<=n+1;i++)  
            for(j=0;j<=n+1;j++)  
                a[i][j]=0;  
        int ttt = 0;
        for(i=0;i<15;i++)  {
            scanf("%s",sss);
            int len = strlen(sss); 
            for(int ii=0;ii<len;++ii) {
                u[ttt ++] = sss[ii] - '0';
                //u[ttt - 1] = 1 - u[ttt - 1];
                //cout<<u[ttt-1];
            }
        }
        //cout<<"ttt == "<<ttt<<endl;
        for(i=0;i<n;i++){  
            a[i][n]=u[i]^1;
            a[i][i]=1;
        }
        for(int i=0;i<n;++i) {
            aa[0] = i + 12;
            aa[1] = i + 1;
            aa[2] = i - 1;
            aa[3] = i + 4;
            aa[4] = i - 4;
            aa[5] = i - 12;
            for(int kk=0;kk<=6;++kk) {
                if(aa[kk] >= 0 && aa[kk] < n) {
                    a[i][aa[kk]] = 1;
                }
            }
        }
        x=gauss();  
        if(x==-1)puts("Oh,my Boring!");  
        else {
            for(int i=0;i<60;++i) {
                printf("%d",a[i][60]);
                /*if((i+1)%4 == 0) {
                    puts("");
                }*/
            }
        }  
    }  
    return 0;  
}  
