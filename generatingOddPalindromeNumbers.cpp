#include<bits/stdc++.h>
using namespace std;

long long palindrome(int i){
	int num=i/10;
	while(num>0){
		i=i*10+num%10;
		num=num/10;
	}
	return i;
}
int main(){
	const unsigned int m = 1000000007;
	int k=1,stop=pow(10,5)+1,t,L,R;
	int dp[stop],i=1;
	dp[0]=0;
	while(k<stop){
		dp[k]=palindrome(i);
		i++;
		k++;
	}
	//cout<<fmod(fmod(pow(9,101),m)*fmod(pow(9,111),m),m);
	cin>>t;
	while(t--){
		unsigned long long ans=1;
		int a=0;
		cin>>L>>R;
		//cout<<dp[L]<<"  "<<dp[R]<<endl;
		for(int i=L+1;i<=R;i++){
			a+=dp[i];
			//ans=fmod(pow(dp[L],dp[i]),m)*ans;
			//ans=(pow(dp[L],dp[i])*ans);
		}
		ans=fmod(pow(dp[L],a),m);
		//ans=fmod(ans,m);
		cout<<ans<<endl;
	}
	return 0;
}
