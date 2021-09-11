#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int solve(int n,int m,char c,vector<string> maze){
	
	if(n<0||m<0) return 0;
	if((n==0&&m==0)&&(maze[0][0]!=c)) { //cout<<"vikas1\n";
	return 1;}
	if(maze[n][m]!=c){
		//cout<<"vikas2\n";
		int x=solve(n-1,m,c,maze);
		int y=solve(n,m-1,c,maze);
		if(x>0&&y>0) return min(x,y)+1;
		else if(x>0) return x+1;
		else if(y>0) return y+1;
		else return INT_MIN;
	}
	else {//cout<<"vikas3\n";
	return INT_MIN;
	}
return 0;	
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<string> maze;
	string s;
	//char maze[n+1][m+1];
	for(int i=0;i<n;i++){
		cin>>s;
		maze.push_back(s);	
		}
	//cout<<maze[0][1];
		//for(auto it=maze.begin();it!=maze.end();it++) cout<<*it<<endl;;
	cout<<solve(n-1,m-1,'*',maze);
return 0;
}
