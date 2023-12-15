#include <iostream>
#include <stdlib.h>
#include "phonebook.h"
#include <string>

using namespace std;


void phonebook :: addcontact(string name,long phoneno)
{
	struct node *q,*tmp;
	tmp=new(struct node);
	tmp->name=name;
	tmp->phoneno=phoneno;

	if(last==NULL)
	{
	last=tmp;
	tmp->link=last;
	}
	else
	{
		tmp->link=last->link;	/*added at the end of list*/
		last->link=tmp;
		last=tmp;
	}
}


void phonebook :: delcontact(string name)
{
	struct node *tmp,*q;
	if(last->link==last && last->name==name)	/*only one element*/
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return;
	}
	q=last->link;
	if(q->name==name)
	{
		tmp=q;
		last->link=q->link;
		free(tmp);
		return;
	}
	while(q->link!=last)
	{
		if(q->link->name==name)	       /*element deleted in between*/
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			cout<<"Deleted "<<name<<endl;
			return;
		}
		q=q->link;
	}
	if(q->link->name==name)		/*last element deleted q->link=last*/
	{
		tmp=q->link;
		q->link=last->link;
		free(tmp);
		last=q;
		return;
	}
	cout<<name<<" not found"<<endl;
}

void phonebook :: displaycontacts()
{
	struct node *q;
	if(last==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	q=last->link;
	cout<<"Contacts :"<<endl;
	cout<<"NAME\tPHONENO"<<endl;
	while(q!=last)
	{
		cout<<q->name<<"\t"<<q->phoneno<<endl;
		q=q->link;
	}
	cout<<last->name<<"\t"<<q->phoneno<<endl;
}


