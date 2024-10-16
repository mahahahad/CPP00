#pragma once
#include "Common.hpp"
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	Contact contacts[8];
	void	addContact(void);
	int		listContacts(void);
	void	findContact(void);

private:
	int		_active_index;
	void	printValue(string str, char suffix);
};
