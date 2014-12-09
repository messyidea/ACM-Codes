
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
#include <cstdio>
using namespace std;  
typedef long long ll;  
int n,k,d[50055];  
ll sumd[50055];  
  
ll getsum(int i,int j) //[i,j)  
{  
    if(i)return sumd[j-1]-sumd[i-1];  
    else return sumd[j-1];   
}  
  
int main()  
{ 
   freopen("input.txt","r",stdin); 
    int T;  cin>>T;   while(T--)  
    {  
        memset(d,0,sizeof d);  
        memset(sumd,0,sizeof sumd);  
        scanf("%d%d",&n,&k);  
        for(int i=0;i<n;i++)  
            scanf("%d",&d[i]);  
        sort(d,d+n);  
        for(int i=0;i<n;i++)  
            if(i) sumd[i]=sumd[i-1]+(ll)d[i];  
            else sumd[i]=(ll)d[i];  
        double messc=0.0,minv=0.0,now=0.0;  
        for(int j=0;j<=k;j++)  
        {  
            ll nows=getsum(j,n-(k-j));  //now sum of j ~ (n-k+j)  
            messc=(double)nows/(double)(n-k);  
            now=0.0;  
            for(int i=j;i<=(n-1)-(k-j);i++)// it means move i item at front and (n-(k-j)) items at end  
            {  
                double dis=(double)d[i]-messc;  
                now+=(dis*dis);  
                if(j && now>=minv) break; //IMPORTANT! TLE if miss it  
            }  
            if(!j)minv=now;  
            else if(now<minv) minv=now;  
        }  
        printf("%.10f\n",minv);  
    }  
}  
