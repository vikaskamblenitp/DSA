#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int maxProfit(int n,int P[],int Vit[],int m,int flag){
	if(n==0||m==0) {
		dp[n][m]=0;
		return 0;
	}
	if(P[n-1]>m){
		if(P[n-1]/2<=m && flag==0) dp[n][m]=max(Vit[n-1]+maxProfit(n-1,P,Vit,m-P[n-1]/2,1),maxProfit(n-1,P,Vit,m,0));
		else dp[n][m]=maxProfit(n-1,P,Vit,m,0);
	}
	else {
		if(flag==0){
			dp[n][m]=max(Vit[n-1]+maxProfit(n-1,P,Vit,m-P[n-1]/2,1),max(Vit[n-1]+maxProfit(n-1,P,Vit,m-P[n-1],0),maxProfit(n-1,P,Vit,m,0)));
		}
		else {
			dp[n][m]=max(Vit[n-1]+maxProfit(n-1,P,Vit,m-P[n-1],0),maxProfit(n-1,P,Vit,m,0));
		}
	}
	return dp[n][m];
}
int main(){
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--){
		int n,m;
		cin>>n>>m;
		int P[n],Vit[n];
		for(int i=0;i<n;i++){
			cin>>Vit[i]>>P[i];
		}
		if(dp[n][m]==-1)
			dp[n][m]=maxProfit(n,P,Vit,m,0);
		cout<<dp[n][m]<<endl;
	}
}

