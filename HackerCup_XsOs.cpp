#include<bits/stdc++.h>
using namespace std;
pair<int,int> solve(vector<vector<char>> v,int n){
	int count1=0,count2=0,minRow=INT_MAX,minCol=INT_MAX;
	
	int row[n],col[n];
	for(int i=0;i<n;i++){
		
		count1=0;
		for(int j=0;j<n;j++){
			if(v[i][j]=='O'){
				
				count1=-1;
				break;	
			}
			else if(v[i][j]=='.'){
				
				count1++;
			}	
		}
		row[i]=count1;
		if(count1!=-1)
		minRow=min(minRow,count1);
	}
	
	for(int i=0;i<n;i++){
		count2=0;
		for(int j=0;j<n;j++){
			if(v[j][i]=='O'){
			
				count2=-1;
				break;	
			}
			else if(v[j][i]=='.'){
			
				count2++;
			}	
		}
		col[i]=count2;
		if(count2!=-1)
		minCol=min(minCol,count2);
	}
count1=0,count2=0;	
if(minRow==INT_MAX && minCol==INT_MAX){
		return make_pair(-1,-1);
	}
else if(minRow!=1 || minCol!=1){
	if(minRow<minCol){
		for(int i=0;i<n;i++){
			if(row[i]==minRow) 
			count1++;
		}
		count2=minRow;
	}
	else if(minRow>minCol){
		for(int i=0;i<n;i++){
			if(col[i]==minCol) 
			count1++;
		}
		count2=minCol;
	}
	else {
		for(int i=0;i<n;i++){
			if(row[i]==minRow) 
			count1++;
			if(col[i]==minCol) 
			count1++;
		}
		count2=minCol;
		}
	}
	else{
		set<pair<int,int>> s;
		for(int i=0;i<n;i++){
			if(row[i]==1){
				count1++;
				for(int j=0;j<n;j++){
					if(v[i][j]=='.'){
					if(s.find(make_pair(i,j))==s.end()){
						s.insert(make_pair(i,j));
					   }
					   break;
					}
				}
			}
			if(col[i]==1){
				count1++;
				for(int j=0;j<n;j++){
					if(v[j][i]=='.'){
					if(s.find(make_pair(j,i))==s.end()){
						s.insert(make_pair(j,i));
					   }
					   break;
					}
				}
			}
		}
	count2=1;
	count1=s.size();	 
	}
	return make_pair(count2,count1);
	
}

int main(){
	ifstream myfile("XsOs.txt");
	ofstream outfile;
	outfile.open("output_xs.txt");
	string s;
	getline(myfile,s);
	stringstream geek(s);
	int t=0,i=1;
	geek>>t;
	while(i<=t){
		string N;
		int n=0;
		getline(myfile,N);
		stringstream geek(N);
		geek>>n;
		vector<vector<char>> v(n,vector<char>(n,'.'));
		
		for(int i=0;i<n;i++){
			getline(myfile,s);
			for(int j=0;j<n;j++){
				v[i][j]=s[j];
			}
		}
		pair<int,int> p=solve(v,n);
	
		if(p.first!=-1){
			outfile<<"Case #"<<i<<": "<<to_string(p.first)<<" "<<to_string(p.second)<<"\n";
		}
		else{
			outfile<<"Case #"<<i<<": Impossible"<<"\n";
		}
		i++;
	}
	myfile.close();
	outfile.close();
	return 0;
}
