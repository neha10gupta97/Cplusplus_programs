#include <iostream>
using namesoace std;

struct node{
	int data;
	node * head;
}*head;

class ll
{
public:
	node* create(int);
	void insert_end();
	ll(){
		head=NULL;
	}

};


node* ll::create(int ele){
	node *head = new node;
	if(head==NULL){
		cout<<"Allocation of memory failed";
		return 0;
	}
	else{
		head->data=ele;
		head->next=NULL;
	}	
	return head;
}


void ll::insert_end(int ele){
	node * second,*last;
	second = create(ele);
	last=head;
	if(head==NULL){
		head=second;
	}
	else{
		while(last->next!=NULL)
			last=last->next;
		last->next=second;
	}
	cout<<"Element inserted at the end"<<endl;
	
}

node* ll::gethead(){
	node *temp =head;
	return temp;
}

main(){
	ll list,list1;
	int t,n1,n2;
	int i,ele;
	cin<<t;
	while(t--){
		cin<<n1;

		for(i=0;i<n1;i++){
			cin<<ele;
			node * temp(ele);
			list1.insert_end();
		}
		
		cin<<n2;

		for(i=0;i<n2;i++){
			cin<<ele;
			node * temp(ele);
			list2.insert_end();
		}

		node *temp=list2.gethead();
		list1.multiply(temp);









