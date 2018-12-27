#include<cstdio>
#include<cmath>
double pi=2,last=2;
int n;
int main(){
    //1+1/3+1/3*2/5+1/3*2/5*3/7……+1*2*3*……n/3*5*……*(2n+1)
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        last=last*(double)i/(2*i+1);
        pi=pi+last;
    }
    printf("%.14f",pi);
  	return 0;
}
