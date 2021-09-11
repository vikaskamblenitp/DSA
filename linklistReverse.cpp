#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
void printlist(Node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"\n";
}
Node* reverse(Node* head, Node* pre=NULL){
	if(head==NULL) return NULL;
	Node* temp=head->next;
	head->next=pre;
	pre=head;
	head=reverse(temp,pre);
	if(head==NULL) return pre;
	else return head;
}
int main(){
	int n,data;
	cout<<"Enter no of elements of link list\n";
	cin>>n;
	Node* head=NULL,*nextNode=NULL;
	for(int i=0;i<n;i++){
		cin>>data;
		if(head==NULL){
		head=new Node();
		head->data=data;
		head->next=NULL;
		nextNode=head;	
		}
		else{
		nextNode->next=new Node();
		nextNode->next->data=data;
		nextNode->next->next=NULL;
		nextNode=nextNode->next;	
		}
	}
	cout<<"Original Linked List :\n";
	printlist(head);
	cout<<"Reverse Linked List :\n";
	head=reverse(head);
	printlist(head);
return 0;
}
