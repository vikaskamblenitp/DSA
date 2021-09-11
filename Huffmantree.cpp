#include<bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	int freq;
	Node* left,*right;
};
Node* newNode(char a,int b){
	Node* t=new Node();
	t->data=a;
	t->freq=b;
	t->left=NULL;
	t->right=NULL;
	return t;
}
struct compare{
bool operator()(Node* t1,Node* t2){
	return t1->freq>t2->freq;
}
};

Node* generateTree(priority_queue<Node*,vector<Node*>,compare> pq){
	while(pq.size()>1){
		Node * root=newNode(' ',0);
		root->left=pq.top();
		pq.pop();
		root->right=pq.top();
		pq.pop();
		root->freq=root->left->freq+root->right->freq;
		pq.push(root);
	}
	return pq.top();	
}
void inorder(Node* root){
	if(root==NULL) return ;
	inorder(root->left);
	cout<<root->freq<<"  \b"<<root->data<<"  \b";
	inorder(root->right);
}
void Encoding(Node* root,string s,vector<pair<char,string>> encode){
	if(root->left==NULL && root->right==NULL){
		cout<<1<<" "<<s<<"\n";
		encode.push_back(make_pair(root->data,s));
		return ;
	}
	else{
		cout<<2<<"\n";
		s.push_back('0');
	Encoding(root->left,s,encode);
	s.pop_back();
	s.push_back('1');
	Encoding(root->left,s,encode);
	s.pop_back();
   }
}

int main(){
priority_queue<Node*,vector<Node*>,compare> pq;
	int n,b;
	char a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		Node* temp=newNode(a,b);
		pq.push(temp);
	}
	Node* root=generateTree(pq);
	inorder(root);
	vector<pair<char,string>> encode;
	string s;
	Encoding(root,s,encode);
	for(auto it=encode.begin();it!=encode.end();it++){
		cout<<it->first<<" "<<it->second<<"\n";
	}
	//cout<<root->freq;
}
