# include <cstdio>
# include <cstring>
# define max(a,b) (a>b?a:b)
# define min(a,b) (a<b?a:b)
const int NR = 10050;
struct lld{
    int l, r;
    int s[NR + 505];
    lld(){
        l = r = 0;
        memset(s, 0, sizeof(s));
    }
    void operator = (const int &x) {
        int p = x;
        while (p){
            s[NR + r++] = p % 10;
            p /= 10;
        }
    }
    lld operator + (const lld &x) const{
        lld q;
        bool flag = false;
        q.l = min(x.l, l);
        int c = 0;
        for (int i = q.l; i < 505; i++){
            if (i >= r && i >= x.r && c == 0) break;
            int p = s[NR + i] + x.s[NR + i] + c;
            q.s[NR + i] = p % 10;
            c = p / 10;
            if (q.s[NR + i] != 0) flag  = true;
            if (!flag) q.l++;
            q.r = i + 1;
        }
        return q;
    }
    lld operator * (const int &x) const{
        lld q;
        int c = 0;
        bool flag = false;
        for (int i = l; i < 505; i++){
            if (i >= r && c == 0) break;
            int p = s[NR + i] * x + c;
            q.s[NR + i] = p % 10;
            c = p / 10;
            if (q.s[NR + i] != 0) flag = true;
            if (!flag) q.l++;
            q.r = i + 1;
        }
        return q;
    }
    lld operator / (const int &x) const{
        lld q;
        q.r = r;
        bool flag = false;
        int o = 0;
        for (int i = r - 1; i >= -NR; i--){
            o = o * 10 + s[NR + i];
            q.s[NR + i] = o / x;
            o = o % x;
            if (q.s[NR + i] != 0) flag = true;
            if (!flag) q.r--;
            q.l = i;
        }
        return q;
    }
    void print(int x){
        if (r <= 0) printf("0");
        for (int i = max(r - 1, -1); i >= -x; i--){
            if (i == -1) printf(".");
            printf("%d", s[NR + i]);
        }
        puts("");
    }
    void print(){
        print(-l);
    }
};
lld pi,last;int n;
int main(){
    pi=2;last=2;
    scanf("%d",&n);
    freopen("pi.out","w",stdout);
    for(int i=1;i<=n;i++){
        last=last*i;
        last=last/(2*i+1);
        pi=pi+last;
    }
    pi.print();
    return 0;
}
