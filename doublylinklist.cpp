/*c++ program
of doubly link list 
with functions-
1. create a node
2. print the circular link list
3. insert an element in the begining
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
	struct node* prev;
}*head;

class dll{
public:
	node* create(int);
	void push(int );
	void append(int);
	void delete_first();
	void delete_end();
	void reverse();
	void print_list();
	void print_reverse();
	dll(){
		head=NULL;
	}
};
dll list;

node* dll::create(int ele){
	node* first=new node;
	if(first==NULL){
		cout<<"Allocation of memory failed"<<endl;
		return 0;
	}
	else{
		first->data=ele;
		first->prev=NULL;
		first->next=NULL;
	}
	return first;
}

void dll::push(int data){
	node* second=create(data);
	second->next=head;
	if(head!=NULL)
		head->prev=second;

	head=second;

	cout<<data<<" has been pushed into the list"<<endl;
}

void dll::append(int data){
	node* second=create(data);
	node* temp=head;
	if(head==NULL)
		head=second;
	else{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=second;
		second->prev=temp;
	}
	cout<<data<<" is appended in the list"<<endl;
}

void dll::delete_first(){
	if(head==NULL)
		cout<<"List is empty...nothing to delete"<<endl;
	else{
		node* second=head;
		head=second->next;
		head->prev=NULL;
	}
	cout<<"Node deleted fromt he begining"<<endl;
}

void dll::delete_end(){
	if(head==NULL)
		cout<<"List is empty...nothing to delete"<<endl;
	else{
		node* temp=head;
		while(temp->next->next!=NULL)
			temp=temp->next;
		temp->next=NULL;
	}
	cout<<"Node deleted from end"<<endl;
}

void dll::reverse(){
	node* cur=head;
	node*temp,*ref;
	while(cur!=NULL){
		ref=cur;
		temp=cur->next;
		cur->next=cur->prev;
		cur->prev=temp;
		cur=cur->prev;
	}
	head=ref;
	cout<<"Reversed link list"<<endl;
	list.print_list();
}

void dll::print_list(){
	node* temp=head;
	if(temp==NULL)
		cout<<"List is empty"<<endl;
	else{
		cout<<"List is:	";
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;	
	}
}

void dll::print_reverse(){
	node* temp=head;
	if(head==NULL)
		cout<<"List is empty"<<endl;
	else{
		cout<<"Reversed List is :	";
		while(temp->next!=NULL)
			temp=temp->next;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->prev;
		}
		cout<<"NULL"<<endl;
	}
}

int main(){
	cout<<"Starting....."<<endl;

	list.push(10);
	list.push(4);
	list.append(15);
	list.push(2);
	list.append(21);

	list.delete_first();
	list.delete_end();

	list.print_list();
	list.print_reverse();

	list.reverse();

}
