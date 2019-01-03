# include <set>
# include <map>
# include <ctime>
# include <stack>
# include <queue>
# include <ctime>
# include <vector>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
using namespace std;
int main(){
	double a0 = 1;
	double b0 = 1 / sqrt(2);
	double t0 = 1.0 / 4;
	double p0 = 1;
	for (int i = 0; i < 10; i++){
		double a1 = (a0 + b0) / 2;
		double b1 = sqrt(a0 * b0);
		double t1 = t0 - p0 * (a0 - a1) * (a0 - a1);
		double p1 = 2 * p0;
		a0 = a1;
		b0 = b1;
		p0 = p1;
		t0 = t1;
		printf("%.14f\n", (a0 + b0) * (a0 + b0) / 4 / t0);
	}
	return 0;
}
