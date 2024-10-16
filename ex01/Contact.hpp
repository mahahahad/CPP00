#pragma	once
#include "Common.hpp"

class Contact {
public:
	Contact	initialize(void);
	string	getFirstName(void);
	string	getLastName(void);
	string	getNickname(void);
	void	printInfo(void);

private:
	string	_first_name;
	string	_last_name;
	string	_nickname;
	string	_phone_number;
	string	_darkest_secret;
	void	getInput(string input_label);
};
