
double diameter(Point* o,int n,Point *p){
    //求点集直径(最大距离),旋转卡壳
    int num=ConvexHull(o,n,p);
    int mi=0,ma=0;
    for(int q=0;q<num;q++){
        if(p[q]<p[mi])mi=q;
        if(p[ma]<p[q])ma=q;
    }
    int v=ma;
    double ans=(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y);
    ans=max(ans,(p[num-1].x-p[ma].x)*(p[num-1].x-p[ma].x)+(p[num-1].y-p[ma].y)*(p[num-1].y-p[ma].y));
    ans=max(ans,(p[mi].x-p[ma-1].x)*(p[mi].x-p[ma-1].x)+(p[mi].y-p[ma-1].y)*(p[mi].y-p[ma-1].y));
    ans=max(ans,(p[num-1].x-p[ma-1].x)*(p[num-1].x-p[ma-1].x)+(p[num-1].y-p[ma-1].y)*(p[num-1].y-p[ma-1].y));
    for(;mi<v;mi++){
        for(;;){
            int a=dcmp(Cross(p[mi+1]-p[mi],p[ma+1]-p[ma]));
            if(a==0){
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                ma++;
                break;
            }
            if(a>0){
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ma++;
            }
            if(a<0){
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                break;
            }
        }
    }
    return ans;
}
