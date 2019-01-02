#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	//格雷戈里 - 莱布尼茨无穷级数
	//π = (4/1) - (4/3) + (4/5)...
	int n;scanf("%d",&n);
	double pi=0;
	for (int i=1;i<=n;i++){
		pi+=(i&1?4.0/(i*2-1):0);
		pi-=(i&1?0:4.0/(i*2-1));
	}
	printf("%.14f\n",pi);
	return 0;
}
