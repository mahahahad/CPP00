#pragma	once
#include "Common.hpp"

class Contact {
public:
	Contact	Initialize(void);
	string	GetFirstName(void);
	string	GetLastName(void);
	string	GetNickname(void);
private:
	string	first_name_;
	string	last_name_;
	string	nickname_;
	string	phone_number_;
	string	darkest_secret_;
};
