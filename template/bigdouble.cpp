# include <queue>
# include <cstdio>
# include <stack>
# include <cstring>
# include <algorithm>
# define LL long long
# define F(i, a, b) for (int i = a; i < b; i++)
using namespace std;
const int NR = 1000;
struct lld{
	int s[NR * 2 + 5];
	int l, r;
	lld(){
		l = NR - 1;
		r = NR;
		memset(s, 0, sizeof(s));
	}
	void operator = (const double &x){
		int a = (int)x;
		double c = x;
		while (a){
			s[r++] = a % 10;
			a /= 10;
		}
		c = c - (int)c;
		while (c != 0){
			c *= 10;
			int b = (int)c;
			s[l--] = b;
			c = c - b;
		}
	}
	void print(int x){
		for (int i = r - 1; i >= NR - x; i--){
			if (i == NR - 1) printf(".");
			printf("%d", s[i]);
		}
	}
};
int main(){
	lld a;
	a = 3.14159265358979;
	a.print(14);
	return 0;
}

