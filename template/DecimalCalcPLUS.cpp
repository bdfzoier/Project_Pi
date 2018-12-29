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
};

int main(){
	Superfloat a, b, c;
	a.Input();
	b.Input();
	c = a + b;
	c.Output();
	return 0;
}
