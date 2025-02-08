#pragma	once
#include "Common.hpp"

enum INPUT_TYPE {
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
};

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
	int 	_phone_number;
	string	_darkest_secret;
};
