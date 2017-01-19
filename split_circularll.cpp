/*c++ program
of circular link list 
with functions-
1. create a node
2. print the circular link list
3. insert an element in the begining
4. split the circular list into two halves
*/

#include <iostream>
#include <stdlib.h>
using namespace std;


//declaring the node structure
struct node{
	int data;
	struct node* next;
}*head;


//declaring the class
class cll{
public:
	void push(int);
	void print_list(struct node*);
	node* create(int);
	void split();
	cll(){
		head=NULL;
	}
};
cll list;

//create a node function
node* cll::create(int ele){
	node * first=new node;
	if(first==NULL){
		cout<<"Allocation of memory failed";
		return 0;
	}else{
		first->data=ele;
		first->next=first;
	}
	return first;
}

//function to printing the elements of the list
void cll::print_list(struct node * x){
	node* temp =x;
	if(x==NULL)    					//if x==NULL i.e. list has no elements
		cout<<"List is empty..."<<endl;

	else{
		cout<<"List is:  ";
		do{

			cout<<temp->data<<" -> ";
			temp=temp->next;
		}while(temp!=x);
		cout<<x->data<<endl;   //printing the first element showing circular link lsit

	}

}

//function that insert an element in the begining
void cll::push(int ele){
	//cout<<"pushing";
	node *second=create(ele);
	node *temp=head;
	if(head==NULL){
		second->next=second;
	}
	else{
		while(temp->next!=head)
			temp=temp->next;
		temp->next=second;
		second->next=head;
	}
	head=second;
}


//function to split the circular link list into two halves
void cll::split(){

	node * fast=head->next;
	node* slow=head;

	if(head==NULL)
		return;
	
	//fast is incremented twice and slow only once ,so slow will be at mid-point
	while(fast!=head &&fast->next!=head){
		fast=fast->next;
		fast=fast->next;
		slow=slow->next;
	}
	node * head1=head;
	node* head2=slow->next;
	
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=head2;
	slow->next=head1;
	cout<<"First list.....  ";
	list.print_list(head1);
	cout<<"second list.......   ";
	list.print_list(head2);
}

int main(){
	cout<<"Initially:";
	list.print_list(head);
	list.push(3);
	list.push(6);
	list.push(4);
	list.push(7);

	list.print_list(head);
	list.split();


}
