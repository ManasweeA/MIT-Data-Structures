#include<iostream>
#include<string.h>
int count = 0;
using namespace std;
struct inventory
{	
	char name_medicine[50];
	float price_medicine;
	int quantity_medicine;
};
//*****************************************
class invent
{
	private:
		inventory medicine[100];
		int i,n,id,found,temp1,temp2;
		char search_name[50];
		char temp[50];
	public:
		void Add();
		void remove();
		void search();
		void display_stock();
		void modify_stock();
};
//------------------------------function definition--------------------------------
void invent::Add()
{
	cout<<"How many medicines you want to add? :";
	cin>>n;
	cout<<endl;
	cout<<"enter the following details:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Name : ";
		cin>>medicine[count+1].name_medicine;
		cout<<"Price : ";
		cin>>medicine[count+1].price_medicine;
		cout<<"Quantity : ";
		cin>>medicine[count+1].quantity_medicine;
		count++;
	}
}

void invent::remove()
{
	cout<<"Enter the Id of medicine you want to remove"<<endl;
	cin>>id;
	if(id>count)
	{
		cout<<"ID not valid"<<endl;
	}
	else
	{
		strcpy(temp,medicine[id].name_medicine);
		temp1 = medicine[id].price_medicine;
		temp2 = medicine[id].quantity_medicine;
		for(i=id;i<count;i++)
		{
			medicine[i]=medicine[i+1];
		}
	count--;
	cout<<"Medicine successfully removed with details:"<<endl<<"ID : "<<id <<endl;
	cout<<"Name : "<<temp<<endl;
	cout<<"Price : "<<temp1<<endl;
	cout<<"Quantity : "<<temp2<<endl;
}
}
void invent::search()
{
	cout<<"Enter the name of medicine you want to search"<<endl;
	cin>>search_name;
	for(i=1;i<count+1;i++)
	{
		if(strcmp(medicine[i].name_medicine,search_name)==0)
		{
			cout<<"Medicine found "<<endl<<"\nDeatails: \n" ;
			cout<<"ID : "<<i<<endl;
			cout<<"Name : "<<search_name<<endl;
			cout<<"Price : "<<medicine[i].price_medicine<<endl;
			cout<<"Quantity : "<<medicine[i].quantity_medicine<<endl;
			found=1;
			break;
		}
		else
		{
			found=0;
		}
	}
	if(found==0)
	{
		cout<<"No Medicine with name "<<search_name<<" is found"<<endl;
	}
}

void invent::modify_stock()
{
	cout<<"Enter the ID of medicine : ";
	cin>>id;
	if(id<=count)
	{
	cout<<endl<<"Enter new price of "<< medicine[id].name_medicine<<":";
	cin>>medicine[id].price_medicine;
	cout<<endl<<"Enter new Quantity of "<< medicine[id].name_medicine<<":";
	cin>>medicine[id].quantity_medicine;
	cout<<endl;
	strcpy(temp,medicine[id].name_medicine);
	}
	else
	{
		cout<<"INVALID ID"<<endl;
	}
	
}
void invent:: display_stock()
{
	if(count==0)
	{
		cout<<"Stock is empty"<<endl;
	}
	else
	{
		for(i=1;i<count+1;i++)
		{
			cout<<"ID : "<<i<<endl;
			cout<<"Name : "<<medicine[i].name_medicine<<endl;
			cout<<"Price : "<<medicine[i].price_medicine<<endl;
			cout<<"Quantity : "<<medicine[i].quantity_medicine<<endl;
			cout<<"______________________________________________________"<<endl;
		}
	}
}		
//-----------------------------------Main function---------------------------------------

int main()
{
	invent o;
	int b,c;
	do
	{
		cout<<endl<<"1. Add"<<endl<<"2. Remove"<<endl<<"3. Search"<<endl<<"4. Display"<<endl<<"5. Modify"<<endl;
		cout<<"\n\nEnter Your choice : ";
		cin>>b;
		cout<<endl;
		switch(b)
		{
			case 1: o.Add();
					break;
			case 2: o.remove();
					break;
			case 3: o.search();
					break;
			case 4: o.display_stock();
					break;
			case 5: o.modify_stock();
					break;
			default: 
					cout<<"Invalid INPUT"<<endl;
		}
		cout<<" \n\n\n\nPress any key to Continue OR 1 to Exit"<<endl;
		cin>>c;
		if(c==1)
		{
			break;
		}	
		else
		{
		system("clear");
		continue;
		}
	}while(b!=0);
return 0;
}

				

