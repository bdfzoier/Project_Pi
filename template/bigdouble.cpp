# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
using namespace std;
const int DC = 10;
struct lld{
    static const int NR = 30050,accuRacy=300;
    static char str[NR+510];
    int l, r;
    int s[NR + 505];
    lld(){
        l = r = 0;
        memset(s, 0, sizeof(s));
    }
    lld(int x){
        l = r = 0;
        memset(s, 0, sizeof(s));
        int p = x;
        while (p){
            s[NR + r++] = p % DC;
            p /= DC;
        }
    }
    void read(){
        scanf("%s",str);
        int len=strlen(str);
        int dot=0;bool f=0;
        for(dot = dot; dot < len; dot++)//find where "." is
            if(str[dot]=='.'){
                f=1;
                break;
            }
        l=dot-len+f;r=dot;
        for(int i=0;i<dot;i++)
            s[NR+r-i-1]=str[i]-'0';
        for(int i=dot+1;i<len;i++)
            s[NR+r-i]=str[i]-'0';
        while(r>=0 && s[NR+r-1]==0)r--;
        while(l<=0 && s[NR+l]==0)l++;
    }
    void print(int x){
        if (r <= 0) printf("0");
        for (int i = max(r - 1, -1); i >= -x; i--){
            if (i == -1) printf(".");
            if (s[NR + i] < 10)
                printf("%d", s[NR + i]);
            else printf("**%d**", s[NR+i]);
        }
        puts("");
    }
    void print(){
        int x=-l;
        if (r <= 0) printf("0");
        for (int i = max(r - 1, -1); i >= -x; i--){
            if (i == -1) printf(".");
            if (s[NR + i] < 10)
                printf("%d", s[NR + i]);
            else printf("**%d**", s[NR+i]);
        }
        puts("");
    }
    void operator = (const int &x) {
        l=r=0;
        memset(s, 0, sizeof(s));
        int p = x;
        while (p){
            s[NR + r++] = p % DC;
            p /= DC;
        }
    }
    bool operator < (const lld &x) const{
        if (r != x.r) return r < x.r;
        for (int i = r - 1; i >= min(l, x.l); i--)
            if (s[NR + i] != x.s[NR + i]) return s[NR + i] < x.s[NR + i];
        return false;
    }
    lld operator + (const int &x) const{
        int c = x;
        lld q;
        q = *this;
        for (int i = 0; i < NR; i++){
            if (c == 0) break;
            int p = s[NR + i] + c;
            c = p / DC;
            q.s[NR + i] = p % DC;
            q.r = max(q.r, i + 1);
        }
        return q;
    }
    lld operator + (const lld &x) const{
        lld q;
        bool flag = false;
        q.l = min(x.l, l);
        int c = 0;
        for (int i = q.l; i < 505; i++){
            if (i >= r && i >= x.r && c == 0) break;
            int p = s[NR + i] + x.s[NR + i] + c;
            q.s[NR + i] = p % DC;
            c = p / DC;
            if (q.s[NR + i] != 0) flag  = true;
            if (!flag) q.l++;
            q.r = i + 1;
        }
        return q;
    }
    lld operator - (const lld &x) const{
        lld q;q.l=min(l,x.l);q.r=max(r,x.r);
        for(int i=q.l;i<q.r;i++)
            q.s[i+NR]=s[i+NR]-x.s[i+NR];
        for(int i=q.l;i<q.r;i++){
            q.s[NR+i+1]+=q.s[NR+i]/DC;
            if(q.s[NR+i]<0){
                q.s[NR+i]+=DC;
                q.s[NR+i+1]--;
            }
        }
        while(q.r>=0 && q.s[NR+q.r-1]==0)q.r--;
        while(q.l<=0 && q.s[NR+q.l]==0)q.l++;
        return q;
    }
    lld operator * (const int &x) const{
        lld q;
        int c = 0;
        bool flag = false;
        for (int i = l; i < 505; i++){
            if (i >= r && c == 0) break;
            int p = s[NR + i] * x + c;
            q.s[NR + i] = p % DC;
            c = p / DC;
            if (q.s[NR + i] != 0) flag = true;
            if (!flag) q.l++;
            q.r = i + 1;
        }
        q.l = min(q.l, 0);
        return q;
    }
    lld operator * (const lld &x) const{
        lld q;q.l=l+x.l;q.r=r+x.r;
        for (int i=l;i<r;i++)
            for(int j=q.l;j<q.r;j++){
                q.s[NR+i+j]+=s[i+NR]*x.s[j+NR];
                q.s[NR+i+j+1]+=q.s[NR+i+j]/DC;
                q.s[NR+i+j]%=DC;
            }
        while(q.s[q.l+NR]==0 && q.l<0)q.l++;
        while(q.s[q.r+NR-1]==0 && q.r>=0)q.r--;
        return q;
    }
    lld operator / (const int &x) const{
        lld q;
        q.r = r;
        bool flag = false;
        int o = 0;
        for (int i = r - 1; i >= -accuRacy; i--){
            o = o * DC + s[NR + i];
            q.s[NR + i] = o / x;
            o = o % x;
            if (q.s[NR + i] != 0) flag = true;
            if (!flag) q.r--;
            q.l = i;
        }
        return q;
    }
    lld operator / (const lld &x) const{
        lld q,o,save_x;
        save_x.r=x.r-x.l;
        for(int i=0;i<save_x.r;i++)
            save_x.s[NR+i]=x.s[NR+x.l+i];
        while(save_x.s[save_x.r+NR-1]==0 && save_x.r>=0)save_x.r--;
        q.r=r-x.l;q.l=-accuRacy;
        for (int i = r - 1; i >= -accuRacy; i--){
            o = o * DC;
            o = o + s[NR + i];
            //若长度不足则跳过
            if((o.r-o.l)<(save_x.r-save_x.l))continue;
            int cnt=0;
            while(!(o < save_x)){
                cnt++;
                o = o - save_x;
            }
            q.s[NR + i - x.l]+=cnt;
            if (o.l == o.r) break;
        }
        for(int i=q.l;i<q.r;i++){
            q.s[NR+i+1]+=q.s[NR+i]/DC;
            q.s[NR+i]%=DC;
            if(q.s[NR+q.r])q.r++;
        }
        while(q.r>0 && q.s[NR+q.r-1]==0)q.r--;
        while(q.l<0 && q.s[NR+q.l]==0)q.l++;
        return q;
    }
};
char lld::str[NR+510];
int main(){
    return 0;
}