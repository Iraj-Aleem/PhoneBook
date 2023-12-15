#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
using namespace std;


struct node
{
	string name;
	long phoneno;
	struct node *link;
};

struct phonebook{
	node *last=NULL;
	
	void addcontact(string,long);
	void delcontact(string);
	void displaycontacts();

};

#endif
