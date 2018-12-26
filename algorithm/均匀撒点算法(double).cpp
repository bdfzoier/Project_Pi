#include<cstdio>
long long n,sq,cnt=0;
const int NR=100000;
long long r[NR];
inline long long fastsq(int x){
    if(r[x]==0 && x<NR)r[x]=x*x;
    return (x<NR?r[x]:(x*x));
}
int main(){
    //memset(r,0,sizeof(r));
    scanf("%lld",&n);
    sq=n*n;cnt+=(sq+n)/2;
    for(int i=1;i<=n;i++)
        for(int j=n-i+1;j<=n;j++)
  			  cnt+=(fastsq(i)+fastsq(j)<=sq);
    printf("%lld %lld %.14f",cnt,sq,double(cnt)*4/sq);
  	return 0;
}
