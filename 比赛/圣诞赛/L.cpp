
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;
int n,m,w,d;
struct node
{
    int x,y;
    int val;    
};
int b[1010][1010];
node a[1000010];
bool cmp(node i,node j)
{
    return i.val<j.val;
}
int sum(int i,int j)
{
    int summ=0,ii,jj;
    for(ii=i;ii<i+d;ii++)
    {
        for(jj=j;jj<j+w;jj++)
            summ+=b[ii][jj];
    }
    return summ;
}
int main()
{
    while(cin>>n>>m>>d>>w)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>b[i][j];
        }
        int e=0;
        for(int i=0;i<=n-d;i++)
        {
            for(int j=0;j<=m-w;j++)
            {
                a[e].x=i;
                a[e].y=j;
                a[e].val=sum(i,j);
                e++;
            }
        }
    //  cout<<"re:"<<sum(1,1)<<endl;
        sort(a,a+e,cmp);
    /*  for(int i=0;i<e;i++)
            cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].val<<endl;*/
        int min=99999999;
        for(int i=0;i<(d*w);i++)
        {
            for(int j=i+1;j<e;j++)
            {
                if(abs(a[i].x-a[j].x)<d&&abs(a[i].y-a[j].y)<w)
                    continue;
                if(min>a[i].val+a[j].val)
                {
                //  cout<<i<<" "<<j<<endl;
                    min=a[i].val+a[j].val;
                //  cout<<min<<endl;
                }
                 
            }
        }/*2*w>m&&2*d>n*/
        if(min==99999999)
            cout<<"-1\n";
        else
            cout<<min<<endl;
    }
    return 0;
} 
/**************************************************************
    Problem: 1326
    User: 2014CHBY17
    Language: C++
    Result: Accepted
    Time:248 ms
    Memory:17384 kb
****************************************************************/
