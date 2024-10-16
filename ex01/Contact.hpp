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
	string	first_name_;
	string	last_name_;
	string	nickname_;
	string	phone_number_;
	string	darkest_secret_;
	void	getInput(string input_label);
};
