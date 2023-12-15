#include <iostream>
#include "phonebook.h"
#include <string>
using namespace std;


int main()
{
	int choice,n,m,position,i;
	string name;
	long phoneno;
	phonebook L;
	L.last=NULL;
	while(1)
	{
		cout<<"1. Add Contact"<<endl;
		cout<<"2. Delete Contact"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Quit"<<endl;

		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many Contacts you want to save :"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter Name"<<endl;
					cin>>name;
					cout<<"Enter Phone No"<<endl;
					cin>>phoneno;
					L.addcontact(name,phoneno);
				}
				break;
			case 2:
				if(L.last==NULL)
				{
					cout<<"List is empty"<<endl;
					continue;
				}
				cout<<"Enter the Contact Name for deletion"<<endl;
				cin>>name;
				L.delcontact(name);
				break;
			case 3:
				L.displaycontacts();
				break;
			case 4:
				exit(1);
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
}

