#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 5;
string fst, scd;
int in1[MAXN], dc1[MAXN];
int in2[MAXN], dc2[MAXN];
int len1, len2; #include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 5;
string fst, scd;
int in1[MAXN], dc1[MAXN];
int in2[MAXN], dc2[MAXN];
int len1, len2; 
int pnt1, pnt2;
int crry;
void prePrcs(){ // PreProcessing func
	pnt1 = len1;
	for(int i = 0 ; i < len1 ; i ++){
		if(fst[i] == '.'){ // if now == '.'
			pnt1 = i;
			break;
		}
		else{ // if now is number
			in1[i] = fst[i] - '0';
		}
	}
	if(pnt1 != len1){ // if '.' isn't the last
		for(int i = pnt1 + 1 ; fst[i] != 0 ; i ++){
			dc1[i - pnt1 - 1] = fst[i] - '0';
		} // keep finding number
	}
	pnt2 = len2;
	for(int i = 0 ; scd[i] != 0 ; i ++){
		if(scd[i] == '.'){ // if now == '.'
			pnt2 = i;
			break;
		}
		else{ // if now is number
			in2[i] = scd[i] - '0';
		}
	}
	if(pnt2 != len2){ // if '.' isn't the last
		for(int i = pnt2 + 1 ; scd[i] != 0 ; i ++){
			dc2[i - pnt2 - 1] = scd[i] - '0';
		} // keep finding number
	}
	for(int i = 0 ; i < pnt1 / 2 ; i ++){
		swap(in1[pnt1 - i - 1], in1[i]);
	} // swap int part 1
	for(int i = 0 ; i < pnt2 / 2 ; i ++){
		swap(in2[pnt2 - i - 1], in2[i]);
	} // swap int part 2
}
void calcDcm(){
	for(int i = 2000 ; i >= 0 ; i --){
		dc1[i] += dc2[i];
		if(i == 0){ // iza c4rry tyM!
			crry = dc1[0] / 10;
			dc1[0] %= 10;
		}
		else if(dc1[i] > 9){ // smol c4rry...
			dc1[i - 1] += dc1[i] / 10;
			dc1[i] %= 10;
		}
	}
}
void calcInt(){
	in1[0] += crry;
	for(int i = 0 ; i <= min(pnt1, pnt2) ; i ++){
		in1[i] += in2[i];
		if(in1[i] >= 10){
			in1[i + 1] += in1[i] / 10;
			in1[i] %= 10; 
		}
	}
}
void print(){
	int tp = 0;
	for(int i = 2000 ; i >= 0 ; i --){ // search first number
		if(in1[i]){
			tp = i;
			break;
		}
	}
	for(int i = tp ; i >= 0 ; i --){
		cout << in1[i];
	}
	tp = -1;
	for(int i = 2000 ; i >= 0 ; i --){
		if(dc1[i]){
			tp = i;
			break;
		}
	}
	if(tp != -1){
		cout << '.';
		for(int i = 0 ; i <= tp ; i ++){
			cout << dc1[i];
		}
	}
}
int main(){
	cin >> fst >> scd; // ya 1 usd cin 1 sux
	len1 = fst . length();
    len2 = scd . length();
	prePrcs(); // PreProcessing
	print();
	cout << endl;
	calcDcm(); // CalculateDecimal
	calcInt(); // CalculateInteger
	print(); // Print
	return 0;
}
int pnt1, pnt2;
int crry;
void prePrcs(){ // PreProcessing func
	for(int i = 0 ; fst[i] != 0 ; i ++){
		if(fst[i] == '.'){ // if now == '.'
			pnt1 = i;
			break;
		}
		else{ // if now is number
			in1[i] = fst[i] - '0';
		}
	}
	if(pnt1 != len1){ // if '.' isn't the last
		for(int i = pnt1 + 1 ; fst[i] != 0 ; i ++){
			dc1[i - pnt1 - 1] = fst[i] - '0';
		} // keep finding number
	}
	for(int i = 0 ; scd[i] != 0 ; i ++){
		if(scd[i] == '.'){ // if now == '.'
			pnt2 = i;
			break;
		}
		else{ // if now is number
			in2[i] = scd[i] - '0';
		}
	}
	if(pnt2 != len2){ // if '.' isn't the last
		for(int i = pnt2 + 1 ; scd[i] != 0 ; i ++){
			dc2[i - pnt2 - 1] = scd[i] - '0';
		} // keep finding number
	}
	for(int i = 0 ; i < pnt1 / 2 ; i ++){
		swap(in1[pnt1 - i - 1], in1[i]);
	} // swap int part 1
	for(int i = 0 ; i < pnt2 / 2 ; i ++){
		swap(in2[pnt2 - i - 1], in2[i]);
	} // swap int part 2
}
void calcDcm(){
	for(int i = 2000 ; i >= 0 ; i --){
		dc1[i] += dc2[i];
		if(i == 0){ // iza c4rry tyM!
			crry = dc1[0] / 10;
			dc1[0] %= 10;
		}
		else if(dc1[i] > 9){ // smol c4rry...
			dc1[i - 1] += dc1[i] / 10;
			dc1[i] %= 10;
		}
	}
}
void calcInt(){
	in1[0] += crry;
	for(int i = 0 ; i < min(pnt1, pnt2) ; i ++){
		in1[i] += in2[i];
		if(in1[i] >= 10){
			in1[i + 1] += in1[i] / 10;
			in1[i] %= 10; 
		}
	}
}
void print(){
	int tp = 0;
	for(int i = 2000 ; i >= 0 ; i --){ // search first number
		if(in1[i] == true){
			tp = i;
			break;
		}
	}
	for(int i = tp ; i >= 0 ; i --){
		cout << in1[i];
	}
	tp = -1;
	for(int i = 2000 ; i >= 0 ; i --){
		if(dc1[i] == true){
			tp = i;
			break;
		}
	}
	if(tp != -1){
		cout << '.';
		for(int i = 0 ; i <= tp ; i ++){
			cout << dc1[i];
		}
	}
}
int main(){
	cin >> fst >> scd; // ya 1 usd cin 1 sux
	len1 = fst . length();
    len2 = scd . length();
	prePrcs(); // PreProcessing
	calcDcm(); // CalculateDecimal
	calcInt(); // CalculateInteger
	print(); // Print
	return 0;
}
