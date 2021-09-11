#include<bits/stdc++.h>
using namespace std;
int maxTime(string s){
	if(s.length()<=1) return 0;
	map<char,int> m;
	set<char> S={'A','E','I','O','U'};
	int count1=0,count2=0;
	char vowelChar,consonantChar;
	for(char c: s){
		m[c]++;
		if(S.find(c)!=S.end()){
			if(m[c]>count1) {
				count1=m[c];
				vowelChar=c;
			}
		}else{
			if(m[c]>count2) {
				count2=m[c];
				consonantChar=c;
			}	
		}
	}
	count1=0,count2=0;
	//calculating count1 while considering vowel char to be fixed
		for(char c: s){
			if(S.find(c)==S.end()){
				count1++;
			}
			else{
				if(c!=vowelChar) count1+=2;
			}
		}
	//calculating count2 while considering consonant char to be fixed
		for(char c: s){
			if(S.find(c)!=S.end()){
				count2++;
			}
			else{
				if(c!=consonantChar){
					count2+=2;
				}
			}
		}
	return count1<count2?count1:count2;
}
int main(){
	ifstream myfile("consistency_1_input.txt");
	ofstream outfile;
	outfile.open("output_Chapter10.txt");
	string s;
	getline(myfile,s);
	int n=1;
	while(n<46){
		getline(myfile,s);
		int ans=maxTime(s);
		outfile<<"Case #"<<n<<": "<<to_string(ans)<<"\n";
		n++;
	}
	outfile.close();
	myfile.close();
	return 0;
}
