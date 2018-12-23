#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct lll{
    static const int M=5005;
    static char str[M];
    int n[M];
    lll(){
        memset(n,0,sizeof(n));
        n[0]=1;
    }
    lll(int a){
        memset(n,0,sizeof(n));
        n[0]=1;
        n[1]=a;
        for(int i=1;i<=n[0];i++){
            n[i+1]+=n[i]/10;
            n[i]%=10;
            if(n[n[0]+1])n[0]++;
        }
    }
    void read(){
        scanf("%s",str);
        n[0]=strlen(str);
        for(int i=n[0];i>=1;i--)
            n[i]=str[n[0]-i]-'0';
    }
    void prt(){
        for(int i=n[0];i>=1;i--)
            putchar(n[i]+'0');
        puts("");
    }
    bool operator < (const lll &b)const{
        if(n[0]!=b.n[0])
            return n[0]<b.n[0];
        for(int i=0;i<n[0];i++)
            if(n[n[0]-i]!=b.n[n[0]-i])
                return n[n[0]-i]<b.n[n[0]-i];
        return 0;
    }
    bool operator > (const lll &b)const{
        if(n[0]!=b.n[0])
            return n[0]>b.n[0];
        for(int i=0;i<n[0];i++)
            if(n[n[0]-i]!=b.n[n[0]-i])
                return n[n[0]-i]>b.n[n[0]-i];
        return 0;
    }
    lll operator + (const lll &b)const{
        lll c;c.n[0]=(n[0]>b.n[0]?n[0]:b.n[0]);
        for(int i=1;i<=c.n[0];i++)
            c.n[i]=n[i]+b.n[i];
        for(int i=1;i<=c.n[0];i++){
            c.n[i+1]+=c.n[i]/10;
            if(c.n[i]>10){
                c.n[i]-=10;
                c.n[i+1]++;
            }
        }
        c.n[0]+=(c.n[c.n[0]+1]>0);
        return c;
    }
    lll operator - (const lll &b)const{
        lll c;c.n[0]=max(n[0],b.n[0]);
        for(int i=1;i<=c.n[0];i++)
            c.n[i]=n[i]-b.n[i];
        for(int i=1;i<=c.n[0];i++){
            c.n[i+1]+=c.n[i]/10;
            if(c.n[i]<0){
                c.n[i]+=10;
                c.n[i+1]--;
            }
        }
        while(c.n[0]>1 && !c.n[c.n[0]])c.n[0]--;
        return c;
    }
    lll operator * (const int &b)const{
        lll c;c.n[0]=n[0];
        for(int i=1;i<=n[0];i++)
            c.n[i]=n[i]*b;
        for(int i=1;i<=c.n[0];i++){
            c.n[i+1]+=c.n[i]/10;
            c.n[i]%=10;
            if(c.n[c.n[0]+1])c.n[0]++;
        }
        return c;
    }
    lll operator * (const lll &b)const{
        lll c;c.n[0]=n[0]+b.n[0]-1;
        for(int i=1;i<=n[0];i++)
            for(int j=1;j<=c.n[0];j++){
                c.n[i+j-1]+=n[i]*b.n[j];
                c.n[i+j]+=c.n[i+j-1]/10;
                c.n[i+j-1]%=10;
            }
        while(c.n[c.n[0]]==0 && c.n[0]>1)c.n[0]--;
        while(c.n[c.n[0]+1])c.n[0]++;
        return c;
    }
    lll operator / (const int &b)const{
        lll c;c.n[0]=n[0];
        for(int i=c.n[0];i>=1;i--)
            c.n[i]=n[i]+c.n[i+1]%b*10;
        for(int i=1;i<=c.n[0];i++)
            c.n[i]/=b;
        while(c.n[c.n[0]]==0 && c.n[0]>1)
            c.n[0]--;
        return c;
    }
};
char lll::str[M];
int main()
{
    return 0;
} 