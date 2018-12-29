#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 2000 + 5;

struct Superfloat{
	private:
		char num[MAXN];
		int in[MAXN], dc[MAXN], len, pnt;
		int Extract(Superfloat src, int dst[])
		{
			int tp = -1;
			for (int i = 2000;i >= 0;i--)
				if (src.dc[i]){
					tp = i + 1;
					break;
				}
			for (int i = tp;i >= 0;i--) {
				dst[tp - i + 1] = src.dc[i];
			}
			for (int i = 0;i <= pnt;i++){
				dst[tp + i + 1] = src.in[i];
			}
			return (tp < 0 ? 0 : tp);
		}
	public:
		Superfloat(){
			memset(num, 0, sizeof(num));
			memset(in, 0, sizeof(in));
			memset(dc, 0, sizeof(dc));
			len = 0;
			pnt = 0;
		}
		void Input(){
			scanf("%s", num);
			len = strlen(num);
			pnt = len;
			for (int i = 0;i < len;i++){
				if (num[i] == '.'){
					pnt = i;
					break;
				}else{
					in[i] = num[i] - '0';
				}
			}
			if (pnt != len){
				for(int i = pnt + 1;i < len;i++){
					dc[i - pnt - 1] = num[i] - '0';
				}
			}
			for(int i = 0;i < pnt / 2;i++){
				swap(in[pnt - i - 1], in[i]);
			}
		}
		void Output(){
			int tp = 0;
			for(int i = 2000 ; i >= 0 ; i --){ // search first number
				if(in[i]){
					tp = i;
					break;
				}
			}
			for(int i = tp ; i >= 0 ; i --){
				putchar(in[i] + '0');
			}
			tp = -1;
			for(int i = 2000 ; i >= 0 ; i --){
				if(dc[i]){
					tp = i;
					break;
				}
			}
			if(tp != -1){
				putchar('.');
				for(int i = 0 ; i <= tp ; i ++){
					putchar(dc[i] + '0'); 
				}
			}
		}
		Superfloat operator + (const Superfloat& b) const{
			int crry = 0;
			Superfloat c;
			for(int i = 2000 ; i >= 0 ; i --){
				c.dc[i] += dc[i] + b.dc[i];
				if(i == 0){ // iza c4rry tyM!
					crry = c.dc[0] / 10;
					c.dc[0] %= 10;
				}
				else if(c.dc[i] > 9){ // smol c4rry...
					c.dc[i - 1] += c.dc[i] / 10;
					c.dc[i] %= 10;
				}
			}
			c.in[0] += crry;
			for(int i = 0 ; i <= min(pnt, b.pnt) ; i ++){
				c.in[i] += in[i] + b.in[i];
				if(c.in[i] >= 10){
					c.in[i + 1] += c.in[i] / 10;
					c.in[i] %= 10; 
				}
			}
			return c;
		}
		Superfloat operator * (const Superfloat& b) const {
			int _a[2 * MAXN], _b[2 * MAXN], _c[4 * MAXN] = {0};
			int tp1 = -1;
			for (int i = 2000;i >= 0;i--)
				if (dc[i]){
					tp1 = i + 1;
					break;
				}
			if (tp1 < 0) {
				tp1 = 0;
			}
//			printf("%d\n", tp1);
			for (int i = tp1;i >= 1;i--) {
				_a[tp1 - i + 1] = dc[i - 1];
			}
			for (int i = 0;i <= pnt;i++){
				_a[tp1 + i + 1] = in[i];
			}
			
			int tp2 = -1;
			for (int i = 2000;i >= 0;i--)
				if (b.dc[i]){
					tp2 = i + 1;
					break;
				}
			if (tp2 < 0) {
				tp2 = 0;
			}
//			printf("%d\n", tp2);
			for (int i = tp2;i >= 1;i--) {
				_b[tp2 - i + 1] = b.dc[i - 1];
			}
			for (int i = 0;i <= b.pnt;i++){
				_b[tp2 + i + 1] = b.in[i];
			}
			
			int __len1 = 0, __len2 = 0;
			for (int i = 4000;i >= 1;i--)
				if (_a[i]){
					__len1 = i;
					break;
				}
			for (int i = 4000;i >= 1;i--)
				if (_b[i]){
					__len2 = i;
					break;
				}
//			printf("__len1=%d __len2=%d\n", __len1, __len2);
//			for (int i = __len1;i >= 0;i--)
//				printf("%d", _a[i]);
//			printf("\n");
//			for (int i = __len2;i >= 0;i--)
//				printf("%d", _b[i]);
//			printf("\n");
			for (int i = 1;i <= __len1;i++) {
				int _crry = 0;
				for (int j = 1;j <= __len2;j++) {
					_c[i + j - 1] += _a[i] * _b[j] + _crry;
					_crry = _c[i + j - 1] / 10;
					_c[i + j - 1] %= 10;
				}
				_c[i + __len2] = _crry;
			}
			int tp3 = tp1 + tp2, __len3 = __len1 + __len2;
			while (_c[__len3] == 0) {
				__len3--;
			}
//			for (int i = __len3;i >= 0;i--)
//				printf("%d", _c[i]);
//			printf("\n");
			Superfloat ans;
			for (int i = 1;i <= tp3;i++)
				ans.dc[tp3 - i] = _c[i];
			for (int i = tp3 + 1;i <= __len3;i++)
				ans.in[i - tp3 - 1] = _c[i];
			ans.pnt = __len3 - tp3;
			return ans;
		}
};

int main(){
	Superfloat a, b, c;
	a.Input();
	b.Input();
	c = a + b;
	c.Output();
	putchar('\n');
	c = a * b;
	c.Output();
	return 0;
}
