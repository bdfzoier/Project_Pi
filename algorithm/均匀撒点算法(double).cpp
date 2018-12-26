#include<cstdio>
#include<cmath>
long long n,sq,lastsq=0,cnt=0;
int main(){
    scanf("%lld",&n);sq=n*n;
    for(int i=1;i<=n;i++){
        lastsq+=i+i-1;
        int j=sqrt(sq-lastsq);
        cnt+=j+1;
    }
    printf("%lld*4 divide by %lld\nPi=%.14f",cnt,sq,double(cnt)*4/sq);
  	return 0;
}
