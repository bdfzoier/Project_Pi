lld pow(lld a,int b){
	lld ans=1;
	while(b){
		if(b&1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
