#include<iostream>
using namespace std;
struct node{
	int priority;
	char name;
	node *next;
};
class linked_list{
private:
	node *head, *tail, *prev,*tmp;
	char name;
	int priority;
public:
	linked_list(){
	head=NULL;
	tail=NULL;
	}
	void add_patient(char name, int priority);
	void deleted();
	void display();
};

void linked_list::add_patient(char name,int priority){
	node *new_node=new node;
	new_node->name=name;
	new_node->priority=priority;
	if(head==NULL){
		head=new_node;
		tail=new_node;
	}
	else{
		if(new_node->priority < head->priority){
			new_node->next=head;
			head=new_node;
		}
		else if(new_node->priority > tail->priority||new_node->priority==tail->priority){
			tail->next=new_node;
			new_node->next=NULL;
			tail=new_node;
		}
		else if(head->priority==new_node->priority){
			new_node->next=head->next;
			head->next=new_node;
		}
		else if(priority > head->priority && priority < tail->priority){
			tmp=head->next;
			prev=head;
			while(priority > tmp->priority){
				prev=tmp;
				tmp=tmp->next;
			}
			prev->next=new_node;
			new_node->next=tmp;
		}
	}
}

void linked_list::display(){
	tmp=head;
	while(tmp!=NULL){
		cout<<"\nPATIENT NAME : "<<tmp->name<<"\nPATIENT PRIORITY : "<<tmp->priority<<endl;
		tmp=tmp->next;
	}
}

void linked_list::deleted(){
	node *tmp1;
	tmp1=head;
	if(head==NULL){
		cout<<"\n\n\tUnderflow.......!";
	}
	cout<<"DELETED\n******************\nPatient name: "<<tmp1->name<<"\nPatient priority: "<<tmp1->priority<<endl;
	head=head->next;
	delete tmp1;
}

int main(){
	linked_list a;
	int i=0;
	char nam;
	int priority;
	while(i!=9){
		cout<<"\n1.add_patient_patient   2.delete_patient    3.display     9.exit()\n";
		cout<<"Enter the choice :";
		cin>>i;
		switch(i){
			case 1:cout<<"\nEnter name of the patient : ";
			      cin>>nam;
			      cout<<"Enter name of the priority : ";
			      cin>>priority;
			      a.add_patient(nam,priority);
			      break;
			case 2:a.deleted();
			     break;
			case 3:a.display();
			     break;
		}
	}
	return 0;
 }