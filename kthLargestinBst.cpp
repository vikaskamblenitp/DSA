#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	
};
Node* newNode(int x){
		Node* temp=new Node();
	    temp->data=x;
	    temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
void findKthLargest(Node* root,int k,int &ans){
	//cout<<k<<endl;
	if(root==NULL) return;
	findKthLargest(root->right,k,ans);
	k--;
	cout<<root->data<<"->"<<k<<endl;
	if(k==0)  ans=root->data;
	findKthLargest(root->left,k,ans);
}	

int main(){
	Node* root=newNode(10);
	root->right=newNode(15);
	root->right->right=newNode(20);
	root->right->left=newNode(12);
	root->left=newNode(7);
	root->left->right=newNode(8);
	root->left->left=newNode(6);
	root->left->left->left=newNode(5);
	int k=4,ans=0;
	findKthLargest(root,k,ans);
	cout<<ans<<endl;
	
}
