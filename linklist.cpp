#include <iostream>
#include <stdlib.h>

using namespace std;

// node declaration------------------------------------------
struct node{
	int data;
	struct node * next;
}*head;

//class declaration------------------------------------------
class ll
{
public:
	node * create(int);
	void insert_first(int);
	void insert_end(int);
	void insert_index(int,int);
	void delete_begin();
	void delete_end();
	void delete_element(int);
	void delete_index(int);
	void search(int);
	void print_list();
	void print_reverse();
	void sort();
	void reverse();
	int length();
	void update_node(int ,int);
	ll(){
		head=NULL;
	}

};
ll list;

//creating a node-----------------------------------------------
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

//insert element at first position-----------------------------
void ll::insert_first(int ele){
	node * front,*temp;
	front=create(ele);
	if(head==NULL){
		head=front;
		head->next=NULL;
	}
	else{
		temp=head;
		front-> next=temp;
		head=front;
	}
	cout<<"Element inserted in the begining"<<endl;
}

//insert element at the end-----------------------------------
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

//insert element at a given index------------------------------
void ll::insert_index(int pos,int ele){
	node* temp;
	node* second;
	second=create(ele);
	temp=head;
	int count=list.length();
	if(pos==1){
		second->next=head->next;
		head=second;
		cout<<"Element inserted at "<<pos<<endl;
	}
	
	else if(count>=(pos-1)&&pos>1){
		temp=head;
		int t=pos-2;
		while(t--)
			temp=temp->next;
		second->next=temp->next;
		temp->next=second;
		cout<<"Element inserted at "<<pos<<endl;
	}
	else{
		cout<<"Can't insert as no of elements are insufficient to inset the element at given index"<<endl;
	}
}

//delete element from the begining of the list-----------------
void ll::delete_begin(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
		head= head-> next;
		cout<<"Element deleted from the begining"<<endl;
	}
}

//delete element from the last---------------------------------
void ll::delete_end(){
	node* temp=head;
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	else if(head->next==NULL){
		head=NULL;
	}
	else{
		while(temp->next->next!=NULL)
			temp=temp->next;
		temp->next=NULL;
	}
	cout<<"Element deleted from the end"<<endl;
}

//delete a given element if it exist--------------------------
void ll::delete_element(int ele){
	node * temp;
	temp=head;
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	else if(temp->next==NULL){
		if(temp->data==ele){
			list.delete_begin();
			cout<<"Element deleted"<<endl;
			return;
		}
	}
	while(temp-> next!=NULL){
		if((temp->next->data)==ele){
			temp-> next=temp->next-> next;
			cout<<"Element deleted"<<endl;
			return;
		}
		head=head-> next;
	}
	cout<<"Element is already doesn't exists";
}

//delete element of given index--------------------------------
void ll::delete_index(int pos){
	int count=list.length();
	if(head==NULL){
		cout<<"List is empty"<<endl;
	}
	else if(count>=pos) {
		if(pos==1){
			delete_begin();
		}
		else {
			node *temp=head;
			int t=pos-2;
			while(t--)
				temp=temp->next;
			temp->next=temp->next->next;
		}
		cout<<"Element deleted from index "<<pos<<endl;

	}
	else
		cout<<"Can't delete as no of elements is less than the index"<<endl;

}

//search from a element in the list-----------------------------
void ll::search(int ele){
	node* temp=head;
	if(head==NULL)
		cout<<"List is empty...therefore not present"<<endl;
	else{
		while(temp!=NULL){
			if(temp->data==ele){
				cout<<"Element is present in the list"<<endl;
				return;
			}
			temp=temp-> next;
		}
		cout<<"Element not present in the list"<<endl;
	}
}

//update the data of a given index node-------------------------
void ll::update_node(int pos,int ele){
	node *temp=head;
	int count=list.length();
	if(count>=pos){
		temp=head;
		int t=pos-1;
		while(t--)
			temp=temp->next;
		temp->data=ele;
		cout<<"Node updated"<<endl;
	}
	else
		cout<<"Can't update as no of elements are less than the index"<<endl;
}

//sort the list in ascending order-------------------------------
void ll::sort(){
	node *i,*j;
	i=head;
	int temp;
	if(head==NULL){
		cout<<"List is empty"<<endl;
		//return;
	}
	while(i!=NULL){
		j=i->next;
		while(j!=NULL){
			if((i->data)>(j->data)){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
			j=j->next;
		}
		//cout<<i->data<<"	";
		i=i->next;
	}
	cout<<"Sorted list is: ";
	list.print_list();
}

//reverse the list-------------------------------------------------
void ll::reverse(){
	node *prev,*cur,*next;
	if(head==NULL){
		cout<<"NULL as List empty"<<endl;
		return;
	}
	prev=NULL;
	cur=head;
	while(cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
	cout<<"List is reversed: ";
	list.print_list();
}

//calculate the no of elements in the list---------------------------
int ll::length(){
	node *temp=head;
	int count=0;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	return count;
}

//printing the list--------------------------------------------------
void ll::print_list(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
		node *temp=head;
		while(temp!=NULL){
			cout<<temp-> data;
			cout<<" -> ";
			temp=temp-> next;
		}
		cout<<"NULL"<<endl;
	}
	
}

//printing the list in reverse order---------------------------------
void ll::print_reverse(){
	node *prev,*cur,*next;
	if(head==NULL){
		cout<<"NULL as List empty"<<endl;
		return;
	}
	prev=NULL;
	cur=head;
	while(cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	while(prev!=NULL){
		cout<<prev->data;
		cout<<" -> ";
		prev=prev->next;
	}
	cout<<"NULL"<<endl;
}

//main---------------------------------------------------------------
int main(){	
	int n,ele,i,loc;

	while(1){
		cout<<"-----------------------MENU--------------------------"<<endl;
		cout<<"1.insert element at begining"<<endl;
		cout<<"2.insert element at end"<<endl;
		cout<<"3.insert element at specific index"<<endl;
		cout<<"4.delete element from begining"<<endl;
		cout<<"5.delete element from end"<<endl;
		cout<<"6.delete a specific element "<<endl;
		cout<<"7.delete element of specific index"<<endl;
		cout<<"8.search a element"<<endl;
		cout<<"9.update a node"<<endl;
		cout<<"10.sort the list"<<endl;
		cout<<"11.reverse the list"<<endl;
		cout<<"12.print the list"<<endl;
		cout<<"13.print list in reverse order"<<endl;
		cout<<"14.get no of elements in the list"<<endl;
		cout<<"15.exit"<<endl;
		int choice;
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"enter the element you want to insert at begining: ";
				cin>>ele;
				list.insert_first(ele);
				break;
			case 2:
				cout<<"enter the element you want to add at the end: ";
				cin>>ele;
				list.insert_end(ele);
				break;
			case 3:
				cout<<"enter the index where you want to enter the element :";
				cin>>loc;
				cout<<"enter the element you want to insert :";
				cin>>ele;
				list.insert_index(loc,ele);
				break;
			case 4:
				list.delete_begin();
				break;
			case 5:
				list.delete_end();
				break;
			case 6:
				cout<<"here is the lsit: ";
				list.print_list();
				cout<<"enter the element you want to delete: ";
				cin>>ele;
				list.delete_element(ele);
				break;
			case 7:
				cout<<"enter the index of node which you want to delete: ";
				cin>>loc;
				list.delete_index(loc);
				break;
			case 8:
				cout<<"enter the element you want to search: ";
				cin>>ele;
				list.search(ele);
				break;
			case 9:
				cout<<"enter the index of node you want to update: ";
				cin>>loc;
				cout<<"enter the new value: ";
				cin>>ele;
				list.update_node(loc,ele);
				break;
			case 10:
				list.sort();
				break;
			case 11:
				list.reverse();
				break;
			case 12:
				cout<<"List: ";
				list.print_list();
				break;
			case 13:
				cout<<"Reverse list: ";
				list.print_reverse();
				break;
			case 14:
				cout<<"No of elements in the list: ";
				n=list.length();
				cout<<n<<endl;
				break;
			case 15:
				cout<<"Thankyou..."<<endl;
				exit(1);
			default:
				cout<<"There is no such option available"<<endl;
		}
	}
}