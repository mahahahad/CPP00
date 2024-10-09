#pragma once
#include "Common.hpp"
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	Contact contacts[8];
	void	AddContact();
	void	ListContacts(void);
	void	FindContact(void);
private:
	int		active_index_;
	void	PrintValue(string str, char suffix);
};
